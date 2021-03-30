/*
Adam Huonder
Paul De Palma
CPSC 122
1/28/21
Project 4 - prime number generator
*/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

bool isPrime(int num, int& primeCount);
bool checkArguments(int numArg);

int main(int argc, char * argv[])
{
	//variables
	ofstream outfile;
	int primeNums;
	int cols;
	int primeCount = 0;
	int x = 2;
	int count = 0;
	
	//checks if there was the correct amount of arguments
	checkArguments(argc);
	
	//opens the file with the name input in command line arguments
	outfile.open(argv[1]);
	
	//asks the user how many prime nums they want
	cout << "How many prime numbers would you like generated?" << endl;
	cin >> primeNums;
	
	//asks the user how many columns they want
	cout << "How many columns would you like the numbers to be displayed in?" << endl;
	cin >> cols;
	
	//while loop continues until program generates desired amount of prime numbers
	while (primeCount < primeNums)
	{
		//if number is prime, writes to output file
		if (isPrime(x, primeCount) == true)
		{
			outfile << x << '\t';
    	if (count % cols == cols - 1)
    		outfile << endl;
    	count++;
		}
		//interates x so it can be tested for primality in next loop
		x++;
	}
	return 0;
}


/*
Description: Determines whether input integer is prime
Input: integer whose primality is to be judged
Returns: true if prime, false if not
*/

bool isPrime(int num, int& primeCount)
{
	int i = 2;
	bool prime;
	
	do
	{
		if (num == 2)
		{	
			prime = true;
			break;
		}
		else if (num%i == 0)
		{
			prime = false;
			break;
		}
		else
		{
			prime = true;
		}
		i++;
	} while (i < num/2);
	
	if (prime == true)
		primeCount++;
	return prime;
}

/*
Description: Checks the amount of arguments and exits if it is the wrong amount
Input: number of arguments
Returns: an exit failure or a true boolean
*/
bool checkArguments(int numArg)
{
	if (numArg != 2) {
		cout << "Wrong number of arguments" << endl;
		exit(EXIT_FAILURE);
	}
	else {
		cout << "Correct number of arguments" << endl;
		return true;
	}
}
