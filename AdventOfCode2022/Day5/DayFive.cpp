// DayFive.cpp

// Namespaces
using namespace std;
// Standard Includes
#include<string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
// Other Includes
#include "DayFive.h"

void DayFive::CrunchPartOne(string& input)
{
	string initialPosition;
	string instructionSet;

	SplitInstructions(input, initialPosition, instructionSet);

}

void DayFive::CrunchPartTwo(string& input)
{

}

void DayFive::SplitInstructions(const string& input, string& initialPosition, string& instructionSet)
{
	stringstream ss(input);
	string token;

	string result;
	bool positionMapFinishedReading = false;
	while (getline(ss, token, '\n'))
	{
		if (token == "")
		{
			initialPosition = result;
			result.clear();
		}
		else
		{
			result.append(token);
			result.append("\n");
		}
	}
	instructionSet = result;
}

map<int, vector<char>> DayFive::GetInitialCrateMap(const string& initialPosition)
{
	return map<int, vector<char>>();
}

vector<vector<int>> DayFive::GetInstructionSets(const string& instructionSet)
{
	return vector<vector<int>>();
}

void DayFive::AdjustCratePosition(map<int, vector<char>>& crateMapping, const vector<int>& instructions)
{
}

string DayFive::GetTopCrates(map<int, vector<char>>& crateMapping)
{
	return string();
}
