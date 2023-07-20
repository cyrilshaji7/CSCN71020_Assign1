
#include "random.h"


//global string to store random string
char result[11];
char* getRandomUsername()
{
	const char* base = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";  // base for all the alphanumerics
	for (int i = 0; i < 10; i++)
		result[i] = base[(rand() % 60) + 1];  // taking a random number and getting that alphanumeric from the base
	result[10] = '\0'; //setting last index to '\0' to let the compiler know when to stop
	return result;
}

int getRandomLevel()
{
	return (rand() % 60) + 1;  //getting random number between 1 and 60 for level
}

int getRandomFaction()
{
	return (rand() % 3) + 1;   // getting random number between 1 and 3 for faction color
}
