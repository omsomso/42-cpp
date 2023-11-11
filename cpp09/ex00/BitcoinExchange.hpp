#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <ctime>
# include <map>

class Btc {
	private:
		std::map<time_t, float> _db;
		std::map<time_t, float> _input;
		time_t _inDate;
		float _inVal;
		std::ifstream _inFile;
		
		void printDb();
		void printInput();
		bool isLeap(long year);
		bool isValidDate(long day, long month, long year);
		bool checkValidDate(std::string line);
		
		std::string outputDateStr(time_t time, const char* format);
		time_t parseDate(const char* dateString, const char* format);
		int parseInLine(std::string line);
		int parseDbLine(std::string& line);
		int initInput(std::string inFileName);
		int initDatabase(std::string dbFileName);

	public:
		Btc();
		Btc(Btc& other);
		~Btc();
		Btc& operator=(Btc& other);

		static int convert(std::string input);
};

#endif