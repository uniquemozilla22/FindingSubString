//////////////////////////////////////////////////////////////////////////////
//
//   Project      : LongestSubString
//   File         : SubstrExtractor.h
//   Author       : Yogesh Bhattarai
//   Description  : Header file for the class to initialize the methods, variables and overloaders.
//	 Compiler Used:	Visual Studio 2022 C++ Compiler
// 
//   Created On: 1/27/2023 2:24:07 PM
//   Created By: [Yogesh bhattarai] <mailto:[ybhat@my.bridgeport.edu]>
////////////////////////////////////////////////////////////////////////////

#ifndef STRINGEDITOR_H_
#define STRINGEDITOR_H_
#include <string>
#include <fstream>


/// <summary>
/// Class to get the longest distinct substring that will be read from the file and output into another file
/// </summary>
class SubstrExtractor{

public:
	SubstrE
	std::string inputWord;
	std::string distinctSubString[100];
	void find_ldsubstr();
	std::string removeSpaces(std::string);
	friend std::ifstream& operator>>(std::ifstream& inputWordFile, SubstrExtractor& sub_string_extractor);
	friend std::ofstream& operator << (std::ofstream& in, SubstrExtractor& stringEditor);

};
#endif

