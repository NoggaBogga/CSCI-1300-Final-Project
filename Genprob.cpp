// Group People: Shehan Rajapakse Ashley Cody

#include <iostream>
#include "Genprob.h"

using namespace std;



    Genprob::Genprob(){};

    int Genprob::twoPercent()
    {
	    randomIndex = rand() % 100; //Generates a random number between 0 and 99
	    // get the random number between 0 and 9 so it fits the array
	    if (randomIndex >= 0 && randomIndex < 10)
	    {
	       return array2Percent[randomIndex]; // Only one spot in this array is true
	    }
	    else if (randomIndex >= 10 && randomIndex < 20)
	    {
	       randomIndex = (randomIndex - 10); // keep the number between 0 - 9
	       return array2Percentempty[randomIndex]; // all spots are false for array2Percentempty
	    }
	    else if (randomIndex >= 20 && randomIndex < 30)
	    {
	       randomIndex = (randomIndex - 20); // keep the number between 0 - 9
	       return array2Percentempty[randomIndex];
	    }
	    else if (randomIndex >= 30 && randomIndex < 40)
	    {
	       randomIndex = (randomIndex - 30); // keep the number between 0 - 9
	       return array2Percentempty[randomIndex];
	    }
	    else if (randomIndex >= 40 && randomIndex < 50)
	    {
	       randomIndex = (randomIndex - 40); // keep the number between 0 - 9
		   return array2Percent[randomIndex]; // Only one spot in this array is true 
		}
	    else if (randomIndex >= 50 && randomIndex < 60)
	    {
	       randomIndex = (randomIndex - 50); // keep the number between 0 - 9
	       return array2Percentempty[randomIndex];
	    }
	    else if (randomIndex >= 60 && randomIndex < 70)
	    {
	       randomIndex = (randomIndex - 60); // keep the number between 0 - 9
	       return array2Percentempty[randomIndex];
	    }
	    else if (randomIndex >= 70 && randomIndex < 80)
	    {
	       randomIndex = (randomIndex - 70); // keep the number between 0 - 9
	       return array2Percentempty[randomIndex];
	    }
	    else if (randomIndex >= 80 && randomIndex < 90)
	    {
	       randomIndex = (randomIndex - 80); // keep the number between 0 - 9
	       return array2Percentempty[randomIndex];
	    }
	    else if (randomIndex >= 90 && randomIndex < 100)
	    {
	       randomIndex = (randomIndex - 90); // keep the number between 0 - 9
	       return array2Percentempty[randomIndex];
	    }
	    // default return
	    return array2Percentempty[0];
    }

    int Genprob::tenPercent()
    {
	    randomIndex = rand() % 10; //Generates a random number between 0 and 9
	    return array10Percent[randomIndex];
    }



    int Genprob::twentyPercent()
    {
	    randomIndex = rand() % 10; //Generates a random number between 0 and 9
	    return array20Percent[randomIndex];
    }

    int Genprob::twenty5Percent()
    {
	    randomIndex = rand() % 4; //Generates a random number between 0 and 3
	    return array25Percent[randomIndex];
    }
	
	int Genprob::thirtyPercent()
	{
		randomIndex = rand() % 10; // generates number between 0 and 9;
		return array20Percent[randomIndex];
	}

    int Genprob::fortyPercent()
    {
	    randomIndex = rand() % 10; //Generates a random number between 0 and 9
	    return array40Percent[randomIndex];
    }

    int Genprob::fiftyPercent()
    {
	    randomIndex = rand() % 2; //Generates a random number between 0 and 1 
	    return array50Percent[randomIndex];
    }

    int Genprob::sixtyPercent()
    {
	    randomIndex = rand() % 10; //Generates a random number between 0 and 9
	    return array60Percent[randomIndex];
    }