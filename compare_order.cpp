#include <fstream>
#include <iostream>
#include <string>

const std::string VERSION = "1.0.0";

int main( int argc, char *argv[])
{
	unsigned long long int lineCount = 0;
	
	if (argc != 3)
	{
		std::cout << "Please specify file 1 and file 2: compare_order file1.txt file2.txt" << std::endl;
		return 1;
	}

	std::string f1 = argv[1];
	std::string f2 = argv[2];

	std::ifstream IFH1( f1.c_str(), std::ios::in );
	std::ifstream IFH2( f2.c_str(), std::ios::in );

	if (!IFH1.good())
	{
		std::cout << "Couldn't open file 1 " << f1;
		return 1;
	}

	if (!IFH2.good())
	{
		std::cout << "Couldn't open file 2 " << f2;
		return 1;
	}

	std::string buffer1;
	std::string buffer2;

	while (++lineCount)
	{
		if (IFH1.eof() && IFH2.eof())
		{
			break;
		}
		else if (IFH1.eof())
		{
			std::cout << "File 1 ended but file 2 did not! Line " << lineCount << "." << std::endl;
			return 1;
		}
		else if (IFH2.eof())
		{
			std::cout << "File 2 ended but file 1 did not! Line " << lineCount << "." << std::endl;
			return 1;
		}
		
		std::getline( IFH1, buffer1 );
		std::getline( IFH2, buffer2 );

		if (buffer1.empty() && buffer2.empty())
		{
			std::cout << "No input read from file 1 or file 2 at line " << lineCount << std::endl;
			return 1;
		}
		else if (buffer1.empty())
		{
			std::cout << "File 1 did not read input at line " << lineCount << std::endl;
			return 1;
		}
		else if (buffer2.empty())
		{
			std::cout << "File 2 did not read input at line " << lineCount << std::endl;
			return 1;
		}

		size_t search_pos = buffer1.find_last_of( std::string("#") );
		if (search_pos == std::string::npos)
		{
			std::cout << "No # in read 1" << std::endl;
			return 1;
		}

		buffer1 = buffer1.erase(search_pos);

		search_pos = buffer2.find_last_of( std::string("#") );
		if (search_pos == std::string::npos)
		{
			std::cout << "No # in read 2" << std::endl;
			return 1;
		}

		buffer2 = buffer2.erase(search_pos);

		if (buffer1 != buffer2)
		{
			std::cout << "Read 1 ID != Read 2 ID at line " << lineCount << std::endl << "Buffer 1: " << buffer1 << std::endl << "Buffer 2: " << buffer2 << std::endl;
			return 1;
		}

		buffer1.clear();
		buffer2.clear();
	}

	IFH1.close();
	IFH2.close();

	std::cout << "All reads in sync. " << lineCount << " total reads processed in each file." << std::endl;
	
	return 0;
}
