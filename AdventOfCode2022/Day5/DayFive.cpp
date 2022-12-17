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
#include <regex>
// Other Includes
#include "DayFive.h"

void DayFive::CrunchPartOne(string& input)
{
	vector<string> initialPosition;
	vector<string> instructionSet;
	SplitInstructions(input, initialPosition, instructionSet);

	vector<char> loadingDockSequence;
	map<char, vector<char>> crateMap = GetInitialCrateMap(initialPosition, loadingDockSequence);
	vector<DayFive::Instruction> instructionMap = GetInstructionSets(instructionSet);

	for (Instruction instruction : instructionMap)
	{
		AdjustCratePosition(crateMap, instruction);
	}

	cout << "Final top crate line-up is: " << GetTopCrates(crateMap, loadingDockSequence);
}

void DayFive::CrunchPartTwo(string& input)
{
	vector<string> initialPosition;
	vector<string> instructionSet;
	SplitInstructions(input, initialPosition, instructionSet);

	vector<char> loadingDockSequence;
	map<char, vector<char>> crateMap = GetInitialCrateMap(initialPosition, loadingDockSequence);
	vector<DayFive::Instruction> instructionMap = GetInstructionSets(instructionSet);

	for (Instruction instruction : instructionMap)
	{
		AdjustStackedCratePosition(crateMap, instruction);
	}

	cout << "Final top crate line-up is: " << GetTopCrates(crateMap, loadingDockSequence);
}

void DayFive::SplitInstructions(const string& input, vector<string>& initialPositions, vector<string>& instructionSet)
{
	stringstream ss(input);
	string token;

	vector<string> result;
	bool positionMapFinishedReading = false;
	while (getline(ss, token, '\n'))
	{
		if (token == "")
		{
			initialPositions = result;
			result.clear();
		}
		else
		{
			result.push_back(token);
		}
	}
	instructionSet = result;
}

map<char, vector<char>> DayFive::GetInitialCrateMap(vector<string>& initialPosition, vector<char>& loadingDockSequence)
{
	if (initialPosition.size() == 0) { cout << "Malformed crate map input."; return map<char, vector<char>>(); }
	map<char, vector<char>> initialCrateMap;

	// Loading docks positioned on bottom of the entry
	map<int, char> loadingDockPositions;
	string loadingDocks = initialPosition.back();
	initialPosition.pop_back();
	for (int i = 0; i < loadingDocks.length(); i++)
	{
		char ch = loadingDocks[i];
		if (ch == *" ") { continue; }
		loadingDockPositions[i] = ch;
		loadingDockSequence.push_back(ch);
		initialCrateMap[ch] = vector<char>();
	}

	// Crates stacked on each loading dock
	while (initialPosition.size() > 0)
	{
		string cratePositionEntry = initialPosition.back();
		initialPosition.pop_back();

		for (int i = 0; i < cratePositionEntry.length(); i++)
		{
			// Find entries aligning to dock positions
			if (loadingDockPositions.count(i))
			{
				char crate = cratePositionEntry[i];
				if (crate == *" ") { continue; }
				initialCrateMap[loadingDockPositions[i]].push_back(crate);
			}
		}
	}
	return initialCrateMap;
}

vector<DayFive::Instruction> DayFive::GetInstructionSets(const vector<string>& instructionSet)
{
	vector<Instruction> parsedInstructions;

	regex e(matchString);
	for (string instruction : instructionSet)
	{
		cmatch cm;
		if (regex_search(instruction.c_str(), cm, e))
		{
			if (cm.size() != matchSize + 1) { cout << "Malformed instruction, skipping"; }
			else
			{
				Instruction parsedInstruction;

				parsedInstruction.quantity = stoi(cm.str(1));
				// Hard requirement:  loading docks can only be single character (otherwise input map fails) - nab first character
				parsedInstruction.startPosition = cm.str(2)[0]; 
				parsedInstruction.endPosition = cm.str(3)[0];
				parsedInstructions.push_back(parsedInstruction);
			}
		}
	}
	return parsedInstructions;
}

void DayFive::AdjustCratePosition(map<char, vector<char>>& crateMap, Instruction instruction)
{
	for (int i = 0; i < instruction.quantity; i++)
	{
		if (crateMap.count(instruction.startPosition) == 0 || crateMap.count(instruction.endPosition) == 0) { cout << "Unavailable loading dock, skipping."; continue; }
		if (crateMap[instruction.startPosition].size() == 0) { continue; }

		char crate = crateMap[instruction.startPosition].back();
		crateMap[instruction.startPosition].pop_back();
		crateMap[instruction.endPosition].push_back(crate);
	}
}

void DayFive::AdjustStackedCratePosition(map<char, vector<char>>& crateMap, Instruction instruction)
{
	vector<char> stack;
	for (int i = 0; i < instruction.quantity; i++)
	{
		if (crateMap.count(instruction.startPosition) == 0 || crateMap.count(instruction.endPosition) == 0) { cout << "Unavailable loading dock, skipping."; continue; }
		if (crateMap[instruction.startPosition].size() == 0) { continue; }

		char crate = crateMap[instruction.startPosition].back();
		crateMap[instruction.startPosition].pop_back();
		stack.push_back(crate);
	}
	reverse(stack.begin(), stack.end());
	crateMap[instruction.endPosition].insert(crateMap[instruction.endPosition].end(), stack.begin(), stack.end());
}

string DayFive::GetTopCrates(map<char, vector<char>>& crateMap, vector<char> loadingDockSequence)
{
	string finalCrateSequence;
	for (char loadingDock : loadingDockSequence)
	{
		if (crateMap.count(loadingDock))
		{
			char topCrate = crateMap[loadingDock].back();
			finalCrateSequence.push_back(topCrate);
		}
	}
	return finalCrateSequence;
}
