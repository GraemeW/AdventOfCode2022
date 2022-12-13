# Advent of Code 2022

> Santa's reindeer typically eat regular reindeer food, but they need a lot of magical energy to deliver presents on Christmas. For that, their favorite snack is a special type of star fruit that only grows deep in the jungle. The Elves have brought you on their annual expedition to the grove where the fruit grows.
> 
> To supply enough magical energy, the expedition needs to retrieve a minimum of fifty stars by December 25th. Although the Elves assure you that the grove has plenty of fruit, you decide to grab any fruit you see along the way, just in case.
> 
> Collect stars by solving puzzles. Two puzzles will be made available on each day in the Advent calendar; the second puzzle is unlocked when you complete the first. Each puzzle grants one star. Good luck!

## Progress Summary

**Total Score:** 8

| Day | Puzzle 1 | Puzzle 2 | Notes |
|:---:|:--------:|:--------:|:----- |
| [1](AdventOfCode2022/Day1/README.md) | X | X | 1. Sum numbers, track max entry 2. Sum numbers, track max 3 entries |
| [2](AdventOfCode2022/Day2/README.md) | X | X | 1. Decode rock paper scissors matches, calculate score 2. Infer RPS hand from opponent hand + win condition |
| [3](AdventOfCode2022/Day3/README.md) | X | X | 1. Split cart in half, find unique entries / half, find common item 2. Find common entry in 3 carts |
| [4](AdventOfCode2022/Day4/README.md) | X | X | 1. Range -> vector, intersect carts & check length vs. carts 2. Count intersected cart length |
| [5](AdventOfCode2022/Day5//README.md) |  |  |  |
| 6 |  |  |  |
| 7 |  |  |  |
| 8 |  |  |  |
| 9 |  |  |  |
| 10 |  |  |  |
| 11 |  |  |  |
| 12 |  |  |  |
| 13 |  |  |  |
| 14 |  |  |  |
| 15 |  |  |  |
| 16 |  |  |  |
| 17 |  |  |  |
| 18 |  |  |  |
| 19 |  |  |  |
| 20 |  |  |  |
| 21 |  |  |  |
| 22 |  |  |  |
| 23 |  |  |  |
| 24 |  |  |  |
| 25 |  |  |  |

## Running the Solutions

[AdventOfCode2022.cpp](AdventOfCode2022/AdventOfCode2022.cpp)

Adjust selectors in main() to execute specific day/question as:
```
int main()
{
	// Main Selection
	AOC::AdventDay daySelector = AOC::AdventDayThree;
	int partSelector = 1;
...
```

I'm playing around with resource loading in this project, so using some Windows-specific libraries on GCM() function.  This can be swapped out for more typical filestream.  Text files are set up to copy over on compile (or otherwise need to be manually copied).
