#pragma once
#include "../Day.h"

class DayFour : public Day
{
	//Properties
	private:
		char workerDelimiter = ',';
		char taskDelimiter = '-';

	// Methods
	public:
		void CrunchPartOne(string& input) override;
		void CrunchPartTwo(string& input) override;
	private:
		vector<string> SplitString(string& input, char delimiter);
		void GetCartIndices(vector<string> rangeStrings, int& startIndex, int& endIndex);
		vector<int> GetCart(int startIndex, int endIndex);
		vector<int> GetIntersectedCart(vector<int> cartA, vector<int> cartB);
};

