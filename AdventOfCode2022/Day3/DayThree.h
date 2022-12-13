#pragma once
#include <map>
#include <vector>
#include "../Day.h"

class DayThree : public Day
{
	// Constructor
	public:
		DayThree();

	// Properties
	private:
		map<char, int> itemValueLookup;
		int numberOfRucksacksToCheck = 3;

	// Methods
	public:
		void CrunchPartOne(string& input) override;
		void CrunchPartTwo(string& input) override;
	private:
		map<char, int> GetUniqueCompartment(string & inputString);
		char GetMatchedEntry(map<char, int> compartmentA, map<char, int> compartmentB);
		char GetMatchedEntry(map<char, int> rucksack, int numberToMatch);
		map<char, int> GetCombinedRucksack(vector<map<char, int>> rucksacks);
		void GetCombinedRucksack(map<char, int>& parentRucksack, map<char, int> childRucksack);
		int GetItemValue(char item);
};
