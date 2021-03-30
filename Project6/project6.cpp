/*
Adam Huonder
Paolo De Palma
2-12-21
CPSC 122
Project 6 - Affine Cipher
*/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <ctime>

using namespace std;

void keyGen(string keyFile);
char encrypt(char ch, int alpha, int beta);
char decrypt(char ch, int alpha, int beta, int MI[]);
void fileControl(string keyFile, string fileIn, string fileOut, int mode);
void fileOpen(fstream&, string name, char mode);

int makePos = 650;
int MI [27] = { 0, 1, 0, 9, 0, 21, 0, 15, 0, 3, 0, 19, 0, 0, 0, 7, 0, 23, 0, 11, 0, 5, 0, 17, 0, 25, 0 };

int main (int argc, char * argv[])
{
	//strings for file names that are put in command line arguments
	string keyfile;
	string fileIn;
	string fileOut;
	
	int mode = atoi(argv[1]);
	keyfile = argv[2]; 
	
	//determines if file in and file out can be named
	if (argc > 3)
	{
		fileIn = argv[3];
		fileOut = argv[4];
	}
	
	//determines if mode is zero or else
	if (mode == 0)
		keyGen(keyfile);
	else
		fileControl(keyfile, fileIn, fileOut, mode);

  return 0;
}

/*
Description: generates the key for the affine cipher
Input: the keyfile name
Output: alpha and beta values in a key file
*/
void keyGen(string keyFile)
{
	int aVals [12] = { 1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25 };
	int alpha, beta;
	fstream outfile;
	
	//opens keyfile with sting name
	outfile.open(keyFile);
	
	unsigned seed = time(0);
	srand(time(0));
	
	/*
	chooses random numbers for the key file
	1-8 for alpha so it selects a number from the array
	1-25 for beta
	*/
	alpha = aVals[(rand() % 12)];
	
	beta = (rand() % 25) + 1;
	
	cout << alpha << ", " << beta << endl;
	
	outfile << alpha << endl << beta << endl;

	outfile.close();
}


/*
Description: encrypts an upper case character using affine cipher
Input: upper case char, alpha and beta values
Output: encrypted char
*/
char encrypt(char ch, int alpha, int beta)
{
	
	int pos = ch -'A';
	
	pos = (alpha * pos + beta) % 26;
	ch = pos + 65;
	
	return ch;

}

/*
Description: decrypts a char using the affine cipher
Input: a char, alpha and beta values, and the multiplicative inverses array
Output: a decrypted char
*/
char decrypt(char ch, int alpha, int beta, int MI[])
{
	int pos = ch -'A';
	int AI = MI[alpha];
	
	
	pos = ((AI * pos) - (AI * beta) + makePos) % 26;
	ch = pos + 65;
	
	return ch;
}

/*
Description: executes encryption or decryption of files based on mode
Input: names of files and mode
Output: an encrypted file or a decrypted file
*/
void fileControl(string keyFile, string fileIn, string fileOut, int mode)
{
	char ch;
	int alpha, beta;
	
	fstream infile;
	fstream outfile;
	fstream key;
	
	fileOpen(key, keyFile, 'r');
	fileOpen(infile, fileIn, 'r');
	fileOpen(outfile, fileOut, 'w');
	
	key >> alpha;
	key >> beta;
	
	//structure encrypts or decrypts based on mode
	if (mode == 1)
	{		
		while(infile.peek() != EOF)
  	{
  		ch = infile.get();
 	  	if (isalpha(ch))
 	  	{
  	    ch = toupper(ch);
  	  	ch = encrypt(ch, alpha, beta);
    	}  
    	outfile.put(ch); 
  	}
	}
	else if (mode == 2)
	{
		while(infile.peek() != EOF)
  	{
  		ch = infile.get();
 	  	if (isalpha(ch))
 	  	{
  	    ch = toupper(ch);
  	  	ch = decrypt(ch, alpha, beta, MI);
    	}  
    	outfile.put(ch); 
  	}
	}
	
	key.close();
	infile.close();
	outfile.close();
}

/*
Description: function opens a file
Input: file stream object reference, name of file, mode of open
Output: input file name is opened
*/
void fileOpen(fstream& file, string name, char mode)
{
	string fileType;
	
	if (mode == 'r')
		fileType = "input";
	if (mode == 'w')
		fileType = "output";

	if (mode == 'r')
		file.open(name, ios::in);  //available thorugh fstream
	if (mode == 'w')
		file.open(name, ios::out);  //available through fstream;
	
	if (file.fail()) //error condition 
	{
		cout << "Error opening " << fileType << " file" << endl; 
		exit(EXIT_FAILURE);
	}
}









