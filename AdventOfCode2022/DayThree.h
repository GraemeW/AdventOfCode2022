#pragma once
using std::string;
#include <string>
#include <map>
#include <vector>

class DayThree
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
		void CrunchPartOne(string& input);
		void CrunchPartTwo(string& input);
	private:
		map<char, int> GetUniqueCompartment(string & inputString);
		char GetMatchedEntry(map<char, int> compartmentA, map<char, int> compartmentB);
		char GetMatchedEntry(map<char, int> rucksack, int numberToMatch);
		map<char, int> GetCombinedRucksack(vector<map<char, int>> rucksacks);
		void GetCombinedRucksack(map<char, int>& parentRucksack, map<char, int> childRucksack);
		int GetItemValue(char item);
};
