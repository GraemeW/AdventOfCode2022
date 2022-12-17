#pragma once
#include <map>
#include <vector>
#include <regex>
#include "../Day.h"

class DayFive : public Day
{
	// Data Structures
	private:
		struct Instruction{
			int quantity;
			char startPosition;
			char endPosition;
		};

	// Tunables
	private:
		string matchString = R"(move (\d+) from (\d+) to (\d+))";
		int matchSize = 3;

	// Methods
	public:
		void CrunchPartOne(string& input) override;
		void CrunchPartTwo(string& input) override;

	private:
		void SplitInstructions(const string& input, vector<string>& initialPositions, vector<string>& instructionSet);
		map<char, vector<char>> GetInitialCrateMap(vector<string>& initialPosition, vector<char>& loadingDockSequence);
		vector<Instruction> GetInstructionSets(const vector<string>& instructionSet);
		void AdjustCratePosition(map<char, vector<char>>& crateMap, Instruction instruction);
		void AdjustStackedCratePosition(map<char, vector<char>>& crateMap, Instruction instruction);
		string GetTopCrates(map<char, vector<char>>& crateMap, vector<char> loadingDockSequence);
};

