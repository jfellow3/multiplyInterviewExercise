/*
Author: Jared Fellows
Date: 4-5-2018
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

int multiply(std::string stringToMultiply, char delim);
std::vector<std::string> seperate(std::string stringToMultiply, char delim);
bool wayToSort(int i, int j) { return i > j; }


int main() {
	int mult;
	mult = multiply("1,2,3,4,56,6,-3", ',');
	std::cout << mult << "\n";
}

int multiply(std::string stringToMultiply, char delim) {
	if (stringToMultiply.size() == 0) return 0;

	int finalMult;

	std::vector<std::string> seperatedVect = seperate(stringToMultiply, delim);
	std::vector<int> problemNumbers;
	std::vector<int> numbersOverHundred;

	bool isFirstTime = true;
	bool isThereNeg = false;

	for (int i = 0; i < seperatedVect.size(); ++i) {
		std::stringstream newOut(seperatedVect[i]);
		
		int tempFinal;
		newOut >> tempFinal;
		if (tempFinal > 100) {
			numbersOverHundred.push_back(tempFinal);
		}
		else {
			if (tempFinal >= 0) {
				if (isFirstTime) {
					finalMult = tempFinal;
					isFirstTime = false;
				}
				else {
					finalMult *= tempFinal;
				}
			}
			else {
				isThereNeg = true;
				problemNumbers.push_back(tempFinal);
			}
		}
	}

	if (isThereNeg) {
		std::cout << "Negatives not allowed: ";

		std::sort(problemNumbers.begin(), problemNumbers.end(), wayToSort);

		for (int i = 0; i < problemNumbers.size(); ++i) {
			std::cout << problemNumbers[i];
			if (i < problemNumbers.size() - 1) std::cout << ", ";
		}
		std::cout << "\n";
		std::cout << "exiting...\n";
		throw;
	}

	if (seperatedVect.size() == numbersOverHundred.size()) return 0;
	return finalMult;
}

std::vector<std::string> seperate(std::string stringToMultiply, char delim) {
	std::vector<std::string> final;
	std::string tempString = "";

	for (int i = 0; i < stringToMultiply.size(); i++) {
		if (stringToMultiply[i] != delim) {
			tempString += stringToMultiply[i];
		} else {
			if (tempString.size() != 0) {
				final.push_back(tempString);
				tempString = "";
			}
		}
	}

	final.push_back(tempString);
	return final;
}