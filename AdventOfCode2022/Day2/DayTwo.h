#pragma once
#include "../Day.h"

class DayTwo : public Day
{
	// Attributes
	private:
		enum RPSType { RPSRock, RPSPaper, RPSScissors, Skip };
		enum MatchOutcomeType { Lose, Draw, Win };
		int rockScore = 1;
		int paperScore = 2;
		int scissorsScore = 3;
		int drawScore = 3;
		int winScore = 6;

	// Methods
	public:
		void CrunchPartOne(string& input) override;
		void CrunchPartTwo(string& input) override;
	private:
		RPSType DecodeOpponentRPSType(char& code);
		RPSType DecodeSelfRPSType(char& code);
		MatchOutcomeType DecodeMatchOutcomeType(char& code);
		RPSType InferSelfRPSType(RPSType opponentRPSType, MatchOutcomeType matchOutcome);
		int GetPlayScore(RPSType rpsType);
		int GetMatchScore(RPSType opponentRPSType, RPSType selfRPSType);
		int GetMatchScore(MatchOutcomeType matchOutcome);
};

