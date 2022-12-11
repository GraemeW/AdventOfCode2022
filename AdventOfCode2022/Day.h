#pragma once
using std::string;
#include <string>

class Day
{
	// Public Methods
	public:
		virtual void CrunchPartOne(string& input) = 0;
		virtual void CrunchPartTwo(string& input) = 0;
};

