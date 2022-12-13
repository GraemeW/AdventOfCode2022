// DayOne.cpp

// Namespaces
using namespace std;
// Standard Includes
#include<string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
// Other Includes
#include "DayOne.h"

void DayOne::CrunchPartOne(string& input)
{
	stringstream ss(input);
	string token;

	int maxCart = 0;
	int maxCartIndex = 1; // Indexed off of 1
	int currentCart = 0;
	int currentCartIndex = 1; // Indexed off of 1
	while (getline(ss, token, '\n')) {
		if (token == "")
		{
			if (currentCart > maxCart)
			{
				maxCart = currentCart;
				maxCartIndex = currentCartIndex;
			}
			currentCart = 0;
			currentCartIndex++;
		}
		else
		{
			int cartEntry = 0;
			try {
				cartEntry = stoi(token);
			}
			catch (invalid_argument const& ex) { cout << "Malformed entry, skipped."; }
			catch (out_of_range const& ex) { cout << "Entry out of range, skipped."; }
			currentCart += cartEntry;
		}
	}

	cout << "Max cart identified:\n";
	cout << maxCart << "\n";
	cout << "On index:\n";
	cout << maxCartIndex << "\n\n";
}

void DayOne::CrunchPartTwo(string& input)
{
	stringstream ss(input);
	string token;

	vector<int> maxCart(3);
	int currentCart = 0;
	while (getline(ss, token, '\n')) {
		if (token == "")
		{
			if (currentCart > maxCart[0])
			{ 
				maxCart[0] = currentCart; 
				sort(maxCart.begin(), maxCart.end());
			}
			currentCart = 0;
		}
		else
		{
			int cartEntry = 0;
			try {
				cartEntry = stoi(token);
			}
			catch (invalid_argument const& ex) { cout << "Malformed entry, skipped."; }
			catch (out_of_range const& ex) { cout << "Entry out of range, skipped."; }
			currentCart += cartEntry;
		}
	}

	int totalCart = 0;
	for (int cartEntry : maxCart)
		totalCart += cartEntry;

	cout << "Total cart identified:\n";
	cout << totalCart << "\n";
}
