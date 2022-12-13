// DayFour.cpp

// Namespaces
using namespace std;
// Standard Includes
#include<string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
// Other Includes
#include "DayFour.h"

void DayFour::CrunchPartOne(string& input)
{
	stringstream ss(input);
	string token;

	int fullyContainedCount = 0;

	string compartmentA;
	string compartmentB;
	while (getline(ss, token, '\n'))
	{
		vector<string> workerDuties = SplitString(token, workerDelimiter);
		if (workerDuties.size() != 2) { cout << "Malformed entry, skipping.\n"; continue; }

		vector<vector<int>> cartSet;
		for (string workerDuty : workerDuties)
		{
			vector<string> cartStrings = SplitString(workerDuty, taskDelimiter);

			int startIndex = -1;
			int endIndex = -1;
			GetCartIndices(cartStrings, startIndex, endIndex);
			if (startIndex == -1 || endIndex == -1) { cout << "Unable to parse task, skipping.\n"; continue; }
			cartSet.push_back(GetCart(startIndex, endIndex));
		}

		if (cartSet.size() != 2) { cout << "Malformed cart set -- incorrect size.  Skipping.\n"; continue; }
		vector<int> intersectedCart = GetIntersectedCart(cartSet[0], cartSet[1]);
		if (intersectedCart.size() == 0) { continue; } // No overlaps in tasks at all

		if (intersectedCart.size() == cartSet[0].size() || intersectedCart.size() == cartSet[1].size())
		{
			fullyContainedCount++;
		}
	}
	cout << "Number of fully contained tasks:\n";
	cout << fullyContainedCount;
}

void DayFour::CrunchPartTwo(string& input)
{
	stringstream ss(input);
	string token;

	int totalOverlaps = 0;

	string compartmentA;
	string compartmentB;
	while (getline(ss, token, '\n'))
	{
		vector<string> workerDuties = SplitString(token, workerDelimiter);
		if (workerDuties.size() != 2) { cout << "Malformed entry, skipping.\n"; continue; }

		vector<vector<int>> cartSet;
		for (string workerDuty : workerDuties)
		{
			vector<string> cartStrings = SplitString(workerDuty, taskDelimiter);

			int startIndex = -1;
			int endIndex = -1;
			GetCartIndices(cartStrings, startIndex, endIndex);
			if (startIndex == -1 || endIndex == -1) { cout << "Unable to parse task, skipping.\n"; continue; }
			cartSet.push_back(GetCart(startIndex, endIndex));
		}

		if (cartSet.size() != 2) { cout << "Malformed cart set -- incorrect size.  Skipping.\n"; continue; }
		vector<int> intersectedCart = GetIntersectedCart(cartSet[0], cartSet[1]);
		if (intersectedCart.size() != 0)
		{
			totalOverlaps++;
		}
	}

	cout << "Number of overlapped tasks:\n";
	cout << totalOverlaps;
}

vector<string> DayFour::SplitString(string& input, char delimiter)
{
	vector<string> splitString;

	stringstream ss(input);
	string token;
	while (getline(ss, token, delimiter))
	{
		splitString.push_back(token);
	}
	return splitString;
}

void DayFour::GetCartIndices(vector<string> rangeStrings, int& startIndex, int& endIndex)
{
	if (rangeStrings.size() != 2) { cout << "Incorrect size of cart, skipping.\n"; }
	try {
		startIndex = stoi(rangeStrings[0]);
		endIndex = stoi(rangeStrings[1]);
	}
	catch (invalid_argument const& ex) { cout << "Malformed entry, skipped.\n"; }
}

vector<int> DayFour::GetCart(int startIndex, int endIndex)
{
	int length = endIndex - startIndex + 1;
	std::vector<int> cart(length);
	std::iota(cart.begin(), cart.end(), startIndex);
	return cart;
}

vector<int> DayFour::GetIntersectedCart(vector<int> cartA, vector<int> cartB)
{
	vector<int> intersectedCart(cartA.size() + cartB.size());
	vector<int>::iterator it;
	it = set_intersection(cartA.begin(), cartA.end(), cartB.begin(), cartB.end(), intersectedCart.begin());
	intersectedCart.resize(it - intersectedCart.begin());
	return intersectedCart;
}
