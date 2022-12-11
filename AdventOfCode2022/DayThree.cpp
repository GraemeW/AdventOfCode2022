// DayThree.cpp

// Namespaces
using namespace std;
// Standard Includes
#include<string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
// Other Includes
#include "DayThree.h"

DayThree::DayThree()
{
	string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	int itemValue = 1;
	for (char c : alphabet)
	{
		itemValueLookup[c] = itemValue;
		itemValue++;
	}
}

void DayThree::CrunchPartOne(string& input)
{
	stringstream ss(input);
	string token;

	int totalScore = 0;

	string compartmentA;
	string compartmentB;
	while (getline(ss, token, '\n'))
	{
		size_t tokenLength = token.length();
		if ((tokenLength % 2) != 0) { cout << "Malformed entry, must be divisible / 2.  Skipping.\n"; }

		compartmentA = token.substr(0, tokenLength / 2);
		compartmentB = token.substr(tokenLength / 2, tokenLength);

		map<char, int> uniqueCompartmentA = GetUniqueCompartment(compartmentA);
		map<char, int> uniqueCompartmentB = GetUniqueCompartment(compartmentB);

		char matchedEntry = GetMatchedEntry(uniqueCompartmentA, uniqueCompartmentB);
		if (matchedEntry == NULL) { cout << "No matched entry found.  Skipping.\n"; }

		totalScore += GetItemValue(matchedEntry);
	}
	cout << "Total score:\n";
	cout << totalScore;
}

void DayThree::CrunchPartTwo(string& input)
{
	stringstream ss(input);
	string token;

	int totalScore = 0;

	int rucksackCounter = 0;
	vector<map<char, int>> rucksacks;
	while (getline(ss, token, '\n'))
	{
		rucksacks.push_back(GetUniqueCompartment(token));
		rucksackCounter++;

		if (rucksackCounter == numberOfRucksacksToCheck)
		{
			map<char, int> combinedRucksack = GetCombinedRucksack(rucksacks);

			char matchedEntry = GetMatchedEntry(combinedRucksack, numberOfRucksacksToCheck);
			if (matchedEntry == NULL) { cout << "No matched entry found.  Skipping.\n"; }

			totalScore += GetItemValue(matchedEntry);

			rucksacks.clear();
			rucksackCounter = 0;
		}
	}
	cout << "Total score:\n";
	cout << totalScore;
}

map<char, int> DayThree::GetUniqueCompartment(string& inputString)
{
	map<char, int> uniqueCompartment;
	for (const char& c : inputString)
	{
		uniqueCompartment[c] = 1; // On dupes will just overwrite (no need to check if existing)
	}
	return uniqueCompartment;
}

char DayThree::GetMatchedEntry(map<char, int> rucksack, int numberToMatch)
{
	for (auto const& entry : rucksack)
	{
		if (entry.second == numberOfRucksacksToCheck)
		{
			return entry.first;
		}
	}
	return NULL;
}

char DayThree::GetMatchedEntry(map<char, int> compartmentA, map<char, int> compartmentB)
{
	for (auto const& entry : compartmentB)
	{
		map<char, int>::iterator matchIndex = compartmentA.find(entry.first);
		if (matchIndex != compartmentA.end()) {
			return entry.first;
		}
	}
	return NULL;
}

map<char, int> DayThree::GetCombinedRucksack(vector<map<char, int>> rucksacks)
{
	map<char, int> combinedRucksack = rucksacks[0];
	for (int i = 1; i < rucksacks.size(); i++)
	{
		GetCombinedRucksack(combinedRucksack, rucksacks[i]);
	}
	return combinedRucksack;
}

void DayThree::GetCombinedRucksack(map<char, int>& parentRucksack, map<char, int> childRucksack)
{
	for (auto const& entry : childRucksack)
	{
		map<char, int>::iterator matchIndex = parentRucksack.find(entry.first);
		if (matchIndex != parentRucksack.end()) {
			parentRucksack[entry.first]++;
		}
		else
		{
			parentRucksack[entry.first] = 1;
		}
	}
}

int DayThree::GetItemValue(char item)
{
	map<char, int>::iterator matchIndex = itemValueLookup.find(item);
	if (matchIndex != itemValueLookup.end())
	{
		return itemValueLookup[item];
	}
	else { cout << "Malformed entry on lookup, skipping.\n"; return 0; }
}
