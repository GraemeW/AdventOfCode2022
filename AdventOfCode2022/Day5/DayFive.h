#pragma once
#include <map>
#include <vector>
#include "../Day.h"

class DayFive : public Day
{
	// Methods
	public:
		void CrunchPartOne(string& input) override;
		void CrunchPartTwo(string& input) override;

	private:
		void SplitInstructions(const string& input, string& initialPosition, string& instructionSet);
		map<int, vector<char>> GetInitialCrateMap(const string& initialPosition);
		vector<vector<int>> GetInstructionSets(const string& instructionSet);
		void AdjustCratePosition(map<int, vector<char>>& crateMapping, const vector<int>& instructions);
		string GetTopCrates(map<int, vector<char>>& crateMapping);
};

