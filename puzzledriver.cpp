#include <iostream>
#include <string>
#include "NPCPuzzle.h"

using namespace std;


int main()
{
	string riddle_answer;

    NPCPuzzle the_puzzle("riddles.txt");

    // play puzzle
    cout << " get a riddle - " << the_puzzle.getRiddle() << endl;
    cout << endl;
    cout << "enter your answer " << endl;
    cin >> riddle_answer;
   
    cout << the_puzzle.checkAnswer(riddle_answer) << endl;

    cout << " get a riddle - " << the_puzzle.getRiddle() << endl;
    cout << endl;
    cout << "enter your answer " << endl;
    cin >> riddle_answer;
   
    cout << " Is riddle solved  " << the_puzzle.checkAnswer(riddle_answer) << endl;
}