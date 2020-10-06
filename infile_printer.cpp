#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv)
{
    std::cout<<"Hello World"<<std::endl;
	std::string string;
	std::ifstream infile;
	infile.open (argv[2]);
        while(!infile.eof()) // To get you all the lines.
        {
	        getline(infile,string); // Saves the line in string.
	        std::cout<<string; // Prints our string.
        }
    // Closes file
	infile.close();
	return 0;
}