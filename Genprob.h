// Group People: Shehan Rajapakse Ashley Cody

#ifndef GENPROB_H
#define GENPROB_H

#include <iostream>

using namespace std;



class Genprob
{
    private:
	int array2Percent[10] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int array2Percentempty[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	// only 1 out of 10 is 1 .. 10% chance of picking 1
	int array10Percent[10] = {0, 0, 0, 0, 0, 1, 0, 0, 0, 0};
	// only 2 out of 10 is 1 .. 20% chance of picking 1
	int array20Percent[10] = {0, 1, 0, 0, 0, 1, 0, 0, 0, 0};
	// only 1 out of 4 is 1 .. 25% chance of picking 1
	int array25Percent[4] = {0, 1, 0, 0};
	// only 3 out of 10 is 1 .. 33% chance of picking 1
	int array30Percent[10] = {0,1,0,0,0,0,1,0,0,1};
	// only 4 out of 10 is 1 .. 40% chance of picking 1
	int array40Percent[10] = {0, 1, 0, 1, 0, 1, 0, 0, 1, 0};
	// only 1 out of 2 is 1 .. 50% chance of picking 1
	int array50Percent[2] = {0, 1};
	// only 6 out of 10 is 1 .. 60% chance of picking 1
	int array60Percent[10] = {0, 1, 0, 1, 1, 1, 1, 0, 1, 0};

	int randomIndex;

    public:
    Genprob();

    int twoPercent();
    int tenPercent();
    int twentyPercent();
    int twenty5Percent();
	int thirtyPercent();
	int thirtythreePercent();
    int fortyPercent();
    int fiftyPercent();
    int sixtyPercent();
};
#endif