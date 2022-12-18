// DaySix.cpp

// Namespaces / Includes
using namespace std;
#include "DaySix.h"

void DaySix::CrunchPartOne(string& input)
{
	int codeStartIndex = GetIndexOfCodeMatch(input, startMatchLength);
	if (codeStartIndex == -1) { cout << "Malformed input, no unique code found for length: " << startMatchLength; return; }

	cout << "Unique code found after entries: " << codeStartIndex;
}

void DaySix::CrunchPartTwo(string& input)
{
	int codeStartIndex = GetIndexOfCodeMatch(input, messageMatchLength);
	if (codeStartIndex == -1) { cout << "Malformed input, no unique code found for length: " << messageMatchLength; return; }

	cout << "Unique code found after entries: " << codeStartIndex;
}

int DaySix::GetIndexOfCodeMatch(string& input, int matchLength)
{
	list<char> code;
	for (int i = 0; i < input.size(); i++)
	{
		if (i < matchLength)
		{
			code.push_back(input[i]);
		}
		else
		{
			if (IsCodeConstructionUnique(code))
			{
				cout << "Unique code identified: ";
				for (char ch : code) { cout << ch; }
				cout << "\n";

				return i; 
			}
			code.pop_front();
			code.push_back(input[i]);
		}
	}
	return -1;
}

bool DaySix::IsCodeConstructionUnique(const list<char>& code)
{
	map<char, int> entryMap;
	for (char ch : code)
	{
		if (entryMap.count(ch)) { return false; }
		entryMap[ch] = 1;
	}
	return true;
}
