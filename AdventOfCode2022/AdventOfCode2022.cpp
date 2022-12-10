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
#include "DayOne.h"

// Data Input/Output
enum AdventDay { AdventDayOne };

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
	AdventDay daySelector = AdventDayOne;
	AOC aoc = AOC();

	switch (daySelector)
	{
		case AdventDay::AdventDayOne:
			aoc.SolveDayOne();
			break;
		default:
			break;
	}
}

void AOC::SolveDayOne()
{
	int resourceInput = DAY1_INPUT;
	int resourceType = TEXTFILE;
	string inputData = AOC::GetAdventDayInput(resourceInput, resourceType);

	DayOne dayOne = DayOne();
	int partSelector = 2;
	if (partSelector == 1)
	{
		dayOne.CrunchPartOne(inputData);
	}
	else if (partSelector == 2)
	{
		dayOne.CrunchPartTwo(inputData);
	}
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
