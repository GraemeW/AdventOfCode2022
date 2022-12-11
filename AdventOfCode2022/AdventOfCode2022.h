#pragma once

class AOC
{
	// Attributes
	public:
		enum AdventDay { AdventDayOne, AdventDayTwo };

	// Methods
	public:
		string GetAdventDayInput(int& resourceInput, int& resourceType);
		void SolveDayOne();
		void SolveDayTwo();
};
