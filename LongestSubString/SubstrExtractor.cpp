
//////////////////////////////////////////////////////////////////////////////
//
//   Project      : LongestSubString
//   File         : SubstrExtractor.cpp
//   Author       : Yogesh Bhattarai
//   Description  : This file will contain the prior methods and overloading methods that will change the string provided from the file 
//					to the output file.
//	 Compiler Used:	Visual Studio 2022 C++ Compiler
// 
//   Created On: 1/27/2023 2:24:07 PM
//   Created By: [Yogesh bhattarai] <mailto:[ybhat@my.bridgeport.edu]>
////////////////////////////////////////////////////////////////////////////
#pragma once

#include<iostream> 
#include<fstream> 
#include <map>
#include <string>
#include "SubstrExtractor.h"

using namespace std;



/// <summary>
/// 
/// Using the operator overloading from the driver file to take the lines from the input file and storing it into
/// the private string.
/// 
/// 
/// </summary>
/// <param name="inputWordFile">ifstream:  file to read the line </param>
/// <param name="sub_string_extractor"> Class with string data type </param>
/// <returns>ifstream input file</returns>
std::ifstream& operator>>(std::ifstream& inputWordFile, SubstrExtractor& sub_string_extractor)
{
	if (inputWordFile.eof()) {
		exit(0);
	}
	string line;
	std::getline(inputWordFile, line);
	sub_string_extractor.inputWord = sub_string_extractor.removeSpaces(line);
	return inputWordFile;
}

/// <summary>
/// 
/// Using the operator overloading from the driver file to update the lines from the input file and storing it into
/// the output file.
/// 
/// 
/// </summary>
/// <param name="outputFile">ifstream:  file to output the modified line </param>
/// <param name="stringEditor"> Class with string data type </param>
/// <returns>ifstream output file</returns>

ofstream& operator<<(ofstream& outputFile, SubstrExtractor& stringEditor)
{
    outputFile << "In the file 'inputWord.txt', it contains  :"+stringEditor.inputWord;
	outputFile << "-> The distinct substring : ";
    if (stringEditor.distinctSubString->empty()) {
        outputFile << "Nothing so the process is empty"<< endl;
    }
    else {
        for (int i = 0; i < (stringEditor.distinctSubString->length()); i++) {
			outputFile << "\"" << stringEditor.distinctSubString[i] << "\"" << endl;
            if (stringEditor.distinctSubString[i + 1] == "")
                break;
            outputFile << "\, " ;
        }
    }

	outputFile << " " << endl;
	return outputFile;
}




/// <summary>
/// Method that will parse the string into distinct subtrings.
/// 
/// </summary>
void SubstrExtractor::find_ldsubstr() {
	int totalSize = inputWord.size();
	int initialPoint = 0;
	int maximumPoint = 0;
	for (int i = 0; i < totalSize; i++) {
		string distinctWord = "";
		distinctWord += inputWord[i];
		for (int j = i + 1; j < totalSize; j++) {
			if (inputWord[j - 1] != inputWord[j]) {
				distinctWord += inputWord[j];
				
			}
			else {
				break;
			}
			
		}
		if (distinctWord.size() >= maximumPoint) {
			if (distinctWord.size() > maximumPoint) {
				distinctSubString[0] = distinctWord;
			}
			else {
				distinctSubString[initialPoint] = distinctWord;
			}
			maximumPoint = distinctWord.length();
			initialPoint++;
		}
	}
}


/// <summary>
/// Removes the spaces from the string.
/// </summary>
/// <param name="inputword"> string :that contains space between them</param>
/// <returns> string with removed spaces</returns>
string SubstrExtractor::removeSpaces(string inputword)
{
	inputword.erase(std::remove(inputword.begin(), inputword.end(), ' '), inputword.end());
	return inputword;
}
