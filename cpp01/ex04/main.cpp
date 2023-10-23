#include <iostream>
#include <fstream>

int main(void)
{
	std::string filename, s1, s2;

	std::cout << "Input filename : " << std::endl;
	std::getline(std::cin, filename);
	std::ifstream input_file;
	std::ofstream output_file;
	input_file.open(filename, std::ios::in);

	if (!input_file)
	{
		std::cout << "Error : specify an existing input file" << std::endl;
		return (0);
	}
	
	filename.append(".replace");
	output_file.open(filename, std::ios::out);
	if (!output_file)
	{
		std::cout << "Error : can't create the output file" << std::endl;
		return (0);
	}

	std::cout << "Input string 1 : " << std::endl;
	std::getline(std::cin, s1);
	std::cout << "Input string 2 : " << std::endl;
	std::getline(std::cin, s2);

	if (s1.empty() || s2.empty())
		std::cout << "Error : strings can't be empty" << std::endl;

	std::string input_str, tmp, out;
	size_t		pos = 0;

	// get input lines until EOF or error
	while (std::getline(input_file, input_str, '\n'))
	{
		// find first occurence of s1 in input_str
		pos = input_str.find(s1, 0);
		
		// if pos found, loop over the input line
		while (pos != std::string::npos)
		{
			// make a substring tmp from 0 to found pos and append s2
			tmp = input_str.substr(0, pos) + s2;

			// trim tmp and s1 from the beginning of the input string
			input_str = input_str.substr(pos + s1.length());

			// add tmp to out
			out = out + tmp;

			// look for the next pos of s1 in the input line
			pos = input_str.find(s1, 0);
		}
		out = out + input_str + '\n';
	}
	// write out to the output file
	output_file << out;

	input_file.close();
	output_file.close();
	return (0);
}
