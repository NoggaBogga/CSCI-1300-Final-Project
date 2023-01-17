// Group People: Shehan Rajapakse Ashley Cody

#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>

using namespace std;

int split(string input_string, char separator, string arr[], int arr_size);

class Monster
{
    private:
    string name = "";
    int powerlevel = 0;

    public:
    Monster(string monstername, int monsterpower); // monster reads from given value
    Monster(int line, string filename); // constructor reads off of file

    string getName();
    int getPower();

    void readMonster(string filename);
    
};
#endif