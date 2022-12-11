// DayTwo.cpp

// Namespaces
using namespace std;
// Standard Includes
#include<string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
// Other Includes
#include "DayTwo.h"

void DayTwo::CrunchPartOne(string& input)
{
	stringstream ss(input);
	string token;

	int totalScore = 0;
	while (getline(ss, token, '\n')) {
		if (token.length() != 3) { cout << "Malformed entry, skipping."; continue; }
		RPSType opponentRPSType = DecodeOpponentRPSType(token.at(0));
		RPSType selfRPSType = DecodeSelfRPSType(token.at(2));
		if (opponentRPSType == RPSType::Skip || selfRPSType == RPSType::Skip) { "Malformed match, skipping."; continue; }

		totalScore += GetPlayScore(selfRPSType);
		totalScore += GetMatchScore(opponentRPSType, selfRPSType);
	}
	cout << "Final score:\n";
	cout << totalScore;
}

void DayTwo::CrunchPartTwo(string& input)
{
	stringstream ss(input);
	string token;

	int totalScore = 0;
	while (getline(ss, token, '\n')) {
		if (token.length() != 3) { cout << "Malformed entry, skipping."; continue; }
		
		// Get opponent type
		RPSType opponentRPSType = DecodeOpponentRPSType(token.at(0));
		if (opponentRPSType == RPSType::Skip) { cout << "Malformed entry, skipping."; continue; }
		
		// Identify win condition
		MatchOutcomeType matchOutcome = DecodeMatchOutcomeType(token.at(2));
		
		// Infer player hand
		RPSType selfRPSType = InferSelfRPSType(opponentRPSType, matchOutcome);
		if (selfRPSType == RPSType::Skip) { cout << "Malformed entry, skipping."; continue; }

		// Calculate score
		totalScore += GetPlayScore(selfRPSType);
		totalScore += GetMatchScore(matchOutcome);
	}
	cout << "Final score:\n";
	cout << totalScore;
}


DayTwo::RPSType DayTwo::DecodeOpponentRPSType(char& code)
{
	if (code == *"A") { return RPSType::RPSRock; }
	else if (code == *"B") { return RPSType::RPSPaper; }
	else if (code == *"C") { return RPSType::RPSScissors; }
	return RPSType::Skip;
}

DayTwo::RPSType DayTwo::DecodeSelfRPSType(char& code)
{
	if (code == *"X") { return RPSType::RPSRock; }
	else if (code == *"Y") { return RPSType::RPSPaper; }
	else if (code == *"Z") { return RPSType::RPSScissors; }
	return RPSType::Skip;
}

DayTwo::MatchOutcomeType DayTwo::DecodeMatchOutcomeType(char& code)
{
	if (code == *"X") { return MatchOutcomeType::Lose; }
	else if (code == *"Y") { return MatchOutcomeType::Draw; }
	else if (code == *"Z") { return MatchOutcomeType::Win; }
	return MatchOutcomeType::Lose;
}

DayTwo::RPSType DayTwo::InferSelfRPSType(RPSType opponentRPSType, MatchOutcomeType matchOutcome)
{
	if (matchOutcome == MatchOutcomeType::Draw) { return opponentRPSType; }

	switch (opponentRPSType)
	{
		case RPSType::RPSRock:
			if (matchOutcome == MatchOutcomeType::Win) { return RPSType::RPSPaper; }
			else if (matchOutcome == MatchOutcomeType::Lose) { return RPSType::RPSScissors; }
		case RPSType::RPSPaper:
			if (matchOutcome == MatchOutcomeType::Win) { return RPSType::RPSScissors; }
			else if (matchOutcome == MatchOutcomeType::Lose) { return RPSType::RPSRock; }
		case RPSType::RPSScissors:
			if (matchOutcome == MatchOutcomeType::Win) { return RPSType::RPSRock; }
			else if (matchOutcome == MatchOutcomeType::Lose) { return RPSType::RPSPaper; }
	}
	return RPSType::Skip;
}

int DayTwo::GetPlayScore(RPSType rpsType)
{
	switch (rpsType)
	{
		case RPSType::RPSRock: return rockScore;
		case RPSType::RPSPaper: return paperScore;
		case RPSType::RPSScissors: return scissorsScore;
	}
	return 0;
}

int DayTwo::GetMatchScore(RPSType opponentRPSType, RPSType selfRPSType)
{
	if (opponentRPSType == selfRPSType) { return drawScore; }
	
	if ((selfRPSType == RPSType::RPSRock && opponentRPSType == RPSType::RPSScissors)
		|| (selfRPSType == RPSType::RPSPaper && opponentRPSType == RPSType::RPSRock)
		|| (selfRPSType == RPSType::RPSScissors && opponentRPSType == RPSType::RPSPaper))
	{ 
		return winScore; 
	}
	return 0;
}

int DayTwo::GetMatchScore(MatchOutcomeType matchOutcome)
{
	switch (matchOutcome)
	{
		case MatchOutcomeType::Win: return winScore;
		case MatchOutcomeType::Draw: return drawScore;
	}
	return MatchOutcomeType::Lose;
}
