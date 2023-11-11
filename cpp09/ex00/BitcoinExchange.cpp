#include "BitcoinExchange.hpp"

Btc::Btc() {}

Btc::Btc(Btc& other) {
	*this = other;
}

Btc::~Btc() {}

Btc& Btc::operator=(Btc& other) {
	this->_db = other._db;
	this->_input = other._input;
	return(*this);
}

// function to parse a date string.
time_t Btc::parseDate(const char* dateString, const char* format)
{
	struct tm tmStruct;
	memset(&tmStruct, 0, sizeof(struct tm));
	strptime(dateString, format, &tmStruct);
	// std::cout << "year : " << tmStruct.tm_year << " month : " << tmStruct.tm_mon << " day : " << tmStruct.tm_mday << std::endl;
	time_t t = mktime(&tmStruct);
	if (t == -1)
		std::cerr << "Error : mktime failed" << std::endl;
	return (t);
}

// Function to format a time_t value into a date or time string.
std::string Btc::outputDateStr(time_t time, const char* format)
{
	char buffer[90];
	struct tm* timeinfo = localtime(&time);
	if (!timeinfo) {
		std::cerr << "Error : localtime failed" << std::endl;
		return "";
	}
	if (strftime(buffer, sizeof(buffer), format, timeinfo) == 0) {
		std::cerr << "Error : strftime failed" << std::endl;
		return "";
	}
	return (buffer);
}

int Btc::parseDbLine(std::string& line) {
	if (line.empty())
		return (0);
	if (!checkValidDate(line))
		return (1);
	std::string strDate = line.substr(0, line.find(","));
	std::string strVal = line.substr(line.find(",") + 1);
	if (strDate.empty() || strVal.empty()) {
		std::cerr << "str empty" << std::endl;
		return (0);
	}
	time_t date = parseDate(&strDate[0], "%Y-%m-%d");
	float val = std::stof(strVal);
	_db.insert(std::pair<time_t, float>(date, val));
	line.clear();
	return (0);
}

void Btc::printDb() {
	for (std::map<time_t, float>::iterator it = _db.begin(); it != _db.end(); ++it) {
		std::cout << "date\t: " << outputDateStr(it->first, "%Y-%m-%d") << std::endl;
		std::cout << "value\t: " << it->second << std::endl;
	}
}

void Btc::printInput() {
	for (std::map<time_t, float>::iterator it = _input.begin(); it != _input.end(); ++it) {
		std::cout << "date\t: " << outputDateStr(it->first, "%Y-%m-%d") << std::endl;
		std::cout << "query\t: " << it->second << std::endl;
	}
}

int Btc::initDatabase(std::string dbFileName) {
	std::ifstream dbFile;
	try {
		dbFile.open(dbFileName);
	}
	catch (std::ios_base::failure& e) {
		std::cerr << "Error : couldn't open database file" << std::endl;
	}

	std::string line;
	std::getline(dbFile, line);
	line.clear();
	while (std::getline(dbFile, line))
		if (parseDbLine(line))
			return (1);
	return (0);
}

bool Btc::isLeap(long year) {
    return year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);
}

bool Btc::isValidDate(long day, long month, long year) {
	// if (day > std::numeric_limits(int) || month >)
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }
    if (month == 2) {
        return day <= 28 || (isLeap(year) && day == 29);
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return day <= 30;
    }
    return (true);
}

bool Btc::checkValidDate(std::string line) {
	std::string yearStr = line.substr(0, 4);
	std::string monthStr = line.substr(5, 2);
	std::string dayStr = line.substr(8, 2);
	long yearLng, monthLng, dayLng;
	try {
		yearLng = stol(yearStr);
		monthLng = stol(monthStr);
		dayLng = stol(dayStr);
	}
	catch (std::exception &e) {
		std::cerr << "Error : invalid date format" << std::endl;
	}
	yearLng = stol(yearStr);
	monthLng = stol(monthStr);
	dayLng = stol(dayStr);
	if (!isValidDate(dayLng, monthLng, yearLng)) {
		std::cerr << "Error: invalid date" << std::endl;
		return (0);
	}
    return (1);
}

int Btc::parseInLine(std::string line) {
	if (line.empty())
		return (0);
	if (!checkValidDate(line))
		return (1);
	std::string strDate = line.substr(0, line.find(" | "));
	std::string strVal = line.substr(line.find("| "));
	if (strVal.length() >= 3)
		strVal = line.substr(line.find("| ") + 2);
	else {
		std::cerr << "Error : no value in query" << std::endl;
		return (1);
	}
	if (strDate.empty() || strVal.empty()) {
		std::cerr << "str empty" << std::endl;
		return (1);
	}
	try {
		float val = std::stof(strVal);
		(void) val;
	}
	catch (std::exception &e) {
		std::cerr << "Error : float value error in input file" << std::endl;
	}
	if (strDate.empty() || strVal.empty()) {
		std::cerr << "str empty" << std::endl;
		return (1);
	}
	float val = std::stof(strVal);
	if (val < 0 || val >= 1000) {
		std::cerr << "Error : query value out of bounds (0 - 1000)" << std::endl;
		return (1);
	}
	time_t date = parseDate(&strDate[0], "%Y-%m-%d");
	_input.insert(std::pair<time_t, float>(date, val));
	line.clear();
	return (0);
}

int Btc::initInput(std::string inFileName) {
	std::ifstream inFile;
	inFile.open(inFileName);
	if (!inFile) {
		std::cerr << "Error : couldn't open input file" << std::endl;
		return (1);
	}

	std::string line;
	std::getline(inFile, line);
	if (line != "date | value") {
		std::cerr << "Error : invalid query header" << std::endl;
		return (1);
	}
	line.clear();
	while (std::getline(inFile, line))
		if (parseInLine(line))
			return (1);
	return (0);
}

int Btc::convert(std::string input) {
	Btc exchange;
	if (exchange.initDatabase("data.csv"))
		return (1);
	if (exchange.initInput(input))
		return (1);
	float val = 0;
	float qval = 0;
	time_t date;
	std::map<time_t, float>::iterator found;
	for (std::map<time_t, float>::iterator it = exchange._input.begin(); it != exchange._input.end(); ++it) {
		found = exchange._db.lower_bound(it->first);
		date = found->first;
		val = found->second;
		qval = it->second;
		std::cout << exchange.outputDateStr(date, "%Y-%m-%d") << " => " << it->second << " = " << val * qval << std::endl;
	}
	return (0);
}