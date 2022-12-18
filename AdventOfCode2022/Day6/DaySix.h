#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include "../Day.h"

class DaySix : public Day
{
	// Tunables
	private:
		int startMatchLength = 4;
		int messageMatchLength = 14;

	// Methods
	public:
		void CrunchPartOne(string& input) override;
		void CrunchPartTwo(string& input) override;

	private:
		int GetIndexOfCodeMatch(string& input, int matchLength);
		bool IsCodeConstructionUnique(const list<char>& code);
};

