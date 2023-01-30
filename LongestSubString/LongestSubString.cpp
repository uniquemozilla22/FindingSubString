//////////////////////////////////////////////////////////////////////////////
//
//   Project      : LongestSubString
//   File         : LongestSubString.cpp
//   Author       : Yogesh Bhattarai
//   Description  : Driver class for the main to take the input from the input file using that file's string to output the longest substring of that line.
//	 Compiler Used:	Visual Studio 2022 C++ Compiler
// 
//   Created On: 1/27/2023 2:24:07 PM
//   Created By: [Yogesh bhattarai] <mailto:[ybhat@my.bridgeport.edu]>
////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#include "SubstrExtractor.h"


int main() {
	SubstrExtractor my_extr;
	std::ifstream file_in("input.txt");
	std::ofstream file_out("output.txt");


	if (file_in.is_open() && file_out.is_open())
	{

		while (file_in)
		{
			file_in >> my_extr;
			my_extr.find_ldsubstr();
			file_out << my_extr;
		}
	}
	return 0;
}