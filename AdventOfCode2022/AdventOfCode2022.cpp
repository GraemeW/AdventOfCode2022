// AdventOfCode2022.cpp

// Namespaces
using namespace std;
// Standard Includes
#include <Windows.h>
#include <iostream>
#include <string>
// Other Includes
#include "resource.h"
#include "AdventOfCode2022.h"

// Data Input/Output
HMODULE GCM()
{
	HMODULE hModule = NULL;
	GetModuleHandleEx(
		GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS,
		(LPCTSTR)GCM,
		&hModule);
	return hModule;
}

// Execution
int main()
{
	// Main Selection
	AOC::AdventDay daySelector = AOC::AdventDayThree;
	int partSelector = 2;

	// Execution
	int resourceType = TEXTFILE;
	int resourceInput;
	Day* day = AOC::GetDaySelectors(daySelector, resourceInput);

	string inputData = AOC::GetAdventDayInput(resourceInput, resourceType);
	if (partSelector == 1)
	{
		day->CrunchPartOne(inputData);
	}
	else if (partSelector == 2)
	{
		day->CrunchPartTwo(inputData);
	}

	// Clean Up
	free(day);
}

string AOC::GetAdventDayInput(int& resourceInput, int& resourceType)
{
	HRSRC hRes = FindResource(GCM(), MAKEINTRESOURCE(resourceInput), MAKEINTRESOURCE(resourceType));
	if (hRes == 0) { return ""; }
	HGLOBAL hData = LoadResource(GCM(), hRes);
	if (hData == 0) { return ""; }

	DWORD hSize = SizeofResource(GCM(), hRes);
	char* hFinal = (char*)LockResource(hData);

	string result;
	result.assign(hFinal, hSize);
	return result;
}

Day* AOC::GetDaySelectors(AdventDay adventDay, int& resourceInput)
{
	switch (adventDay)
	{
		case AOC::AdventDay::AdventDayOne:
		{
			resourceInput = DAY1_INPUT;
			DayOne* dayOne = new DayOne();
			return dayOne;
		}
		case AOC::AdventDay::AdventDayTwo:
		{
			resourceInput = DAY2_INPUT;
			DayTwo* dayTwo = new DayTwo();
			return dayTwo;
		}
		case AOC::AdventDay::AdventDayThree:
		{
			resourceInput = DAY3_INPUT;
			DayThree* dayThree = new DayThree();
			return dayThree;
		}
		case AOC::AdventDay::AdventDayFour:
		{
			resourceInput = DAY4_INPUT;
			DayFour* dayFour = new DayFour();
			return dayFour;
		}
	}
	DayZero* dayZero = new DayZero();
	return dayZero;
}
