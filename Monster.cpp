// Group People: Shehan Rajapakse Ashley Cody

#include <iostream>
#include <fstream>
#include "Monster.h"
#include "Party.h"

using namespace std;

int split(string input_string, char separator, string arr[], int arr_size)
{
    /*
    first, if input_string.length is 0, return 0
    define int counter = 0, each time the delimiter is found, increase by one
    at the end, if this counter is still 0, then there is no delimiter in the provided string-
    return 1
    define int segment_length = 0, this will be used to track the location of previous delimiter
    in order to make the segment being inserted into arr the right length
    for an int iterator i = 0, increasing by one each time to go through each item in input_string,
    while i < length of input_string, 
    check if each item at input_string != separator
    if yes, 
        check if counter + 1 >= arr_size - counter tracks indices of arr_size, and highest index + 1 = size of array,
        if the highest index + 1 is higher than the size of the array, then we will overfill the array, return -1
        
        else, take the substring of input_string from segment_length to i - segment_length and 
        place that in arr[counter], then increase counter by 1, set segment_length = i to 
        count from this point for the next operation
    .
    
    
    after the for loop has ended, add the remaining substr from segment_length to the size of the string - segment_length in order to 
    add the final substring to the array 
    lastly, return the value of counter + 1 to get the number of items inserted into the array,
    or in other words, the number of substrings the input string was broken into    
    */

    if(input_string.length() == 0) return 0;

    // define necessary values for calculation
    int counter = 0, segment_length = 0;
    
    for(int i = 0; i < input_string.length(); i++)
    {
        // test output to track iterator and counter values at runtime
        // cout << endl << "Iteration number " << i + 1 << endl << "Current i value: " << i << endl << "Next expected counter value:" << counter + 1 << endl;
        if(input_string[i] == separator)
        {
            
            if(counter + 1 >= arr_size)
            {
                // add the last value possible, then return 0
                arr[counter] = input_string.substr(segment_length, i - segment_length);
                return -1;
            }
            else
            {
                // test output to track locating separators and finding substrings at runtime
                // cout << "Current i value where a separator was found:" << i << endl << "Substring to be inserted: " << input_string.substr(segment_length, i - segment_length) << endl;
                arr[counter] = input_string.substr(segment_length, i - segment_length);
                counter += 1;
                // segment_length goes to i + 1, i is currently at a delimiter and we want to skip it
                segment_length = i + 1;
            }
        }
    }

    // test output to find what the final substring to be added is
    // cout << "Final segment starting point: " << segment_length << endl << "Final length of substring: " << input_string.length() - segment_length << endl << "Final substring to be printed:" << input_string.substr(segment_length, input_string.length() - segment_length) << endl;
    arr[counter] = input_string.substr(segment_length, input_string.length() - segment_length);
    return counter + 1;
}


Monster::Monster(string monstername, int monsterpower)
{
	name = monstername;
	powerlevel = monsterpower;
} // monster reads from given value

Monster::Monster(int line, string filename)
{
	// if line given is below 1, then there is no data that can be read! abort immediately
	if(line < 1)
	{
		cout << "error at monster declaration through file read: " << endl << "line number invalid (< 1)-- " << endl;
		abort();
	}

	// read monster value off of file, at given line
	ifstream fin;
	fin.open(filename);
	if(fin.fail())
	{
		// if file not opened, then monster cannot be defined this way
		// the issues this can cause are hard to predict- so throw an error message and abort immediately
		cout << "error at monster declaration through file read: " << endl << filename << " not found in directory!-- " << endl;
		abort();
	}
	string linedata = "";


	// loop through lines of file until number of lines read matches given value
	for(int i = 0; i < line; i++)
	{
		getline(fin, linedata);
	}
	// hold data from split function, use to 
	string monsterdata[2] = {};
	int returnvalue = split(linedata, ',', monsterdata, 2);

	name = monsterdata[0];

	try
	{
		powerlevel = stoi(monsterdata[1]);
	}
	catch(const std::exception& e)
	{
		cout << "error at monster declaration through file read: " << endl << filename << " contains invalid data! (powerlevel int not convertible from str to int)-- " << endl;
		abort();
	}
	
	powerlevel = stoi(monsterdata[1]);
} 

string Monster::getName()
{
	return name;
}
int Monster::getPower()
{
	return powerlevel;
}

// void Monster::readMonster(string filename)
// {
// 	// read data for the monster off of file
// }