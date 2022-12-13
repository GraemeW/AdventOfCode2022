#pragma once
#include "Days.h"

class AOC
{
	// Attributes
	public:
		enum AdventDay { AdventDayOne, AdventDayTwo, AdventDayThree, AdventDayFour, AdventDayFive };

	// Methods
	public:
		static string GetAdventDayInput(int& resourceInput, int& resourceType);
		static Day* GetDaySelectors(AdventDay adventDay, int& resourceInput);
};
