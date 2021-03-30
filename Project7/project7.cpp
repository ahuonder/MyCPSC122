/*
Adam Huonder
Paolo De Palma
2-18-21
CPSC 122
Project 7 - Transposition Cipher
*/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <ctime>

using namespace std;

void keyGen(string keyFile);
void fileControl(string keyFile, string fileIn, string fileOut, int mode);
char transform(char ch, int encDec[]);
void fileOpen(fstream& file, string name, char mode);

const int ALPH_SIZE = 4;

int main(int argc, char * argv[])
{
  string keyFile;
  string fileIn;
  string fileOut; 
  
  int mode = atoi(argv[1]);
	keyFile = argv[2]; 
	
	//determines if file in and file out can be named
	if (argc > 3)
	{
		fileIn = argv[3];
		fileOut = argv[4];
	}
	
	//determines if mode is zero or else
	if (mode == 0)
		keyGen(keyFile);
	else
		fileControl(keyFile, fileIn, fileOut, mode);

	return 0;
}

/*
Description: Opens key file for writing.  Generates and stores encrypt and decrypt 
keys in the key file.   This can be stored any way that you like as long as two arrays 
can be constructed from the file, one for encryption and one for decryption. 
Input: name of the file in which to store generated keys
Output: file holds generated encryption and decryption keys 

*/
void keyGen(string keyFile)
{
  int key[2][ALPH_SIZE];
  int deKey[2][ALPH_SIZE];
  bool valid[ALPH_SIZE];
  int i, k, pos, temp1, temp2, min, minSpot;
  fstream fout;
  
  unsigned seed = time(0);
	srand(time(0));
  
  fileOpen(fout, keyFile, 'w');
  
  //fills in the valid array with false
  for (i = 0; i < ALPH_SIZE; i++)
  {
    valid[i] = false;
  }
  
  //first column in numeric order
  for (i = 0; i < ALPH_SIZE; i++)
  {
    key[0][i] = i;
  }
  
  //randomly generates the encrypt key
  pos = 0;
  while (pos < ALPH_SIZE)
  {
    k = rand() % ALPH_SIZE;
    
    if (valid[k] == false)
    {
      valid[k] = true;
      key[1][pos] = k;
      pos++;
    }
  }
  
  for (i = 0; i < ALPH_SIZE; i++)
  {
    //change to output file when ready
    fout << key[1][i] << endl;
  }
  //*************************************************************************
  
  //flips the key
  for (int j = 0; j < ALPH_SIZE; j++)
  {
    deKey[0][j] = key[1][j];
    deKey[1][j] = key[0][j];
  }
  
  for (int j = 0; j < ALPH_SIZE; j++)
  {
    min = deKey[0][j];
    minSpot = j;
    
    for (i = j; i  < ALPH_SIZE; i++)
    {
      if (deKey[0][i] < min)
      {
        min = deKey[0][i];
        minSpot = i;
      }
    }
    
    temp1 = deKey[0][minSpot];
    deKey[0][minSpot] = deKey[0][j];
    deKey[0][j] = temp1;
    
    temp1 = deKey[1][minSpot];
    deKey[1][minSpot] = deKey[1][j];
    deKey[1][j] = temp1;
  }
    
  for (i = 0; i < ALPH_SIZE; i++)
  {   
    fout << deKey[1][i] << endl;
  }
}


/*
Description: Processes files, invokes function to encrypt/decrypt characters
1. Reads key file. Constructs a two arrays, one for encryption, one for decryption.
2. Closes key file
2. Opens the character input file.  This could be plain text or cipher text.
3. Opens the character output file  This could be plain text or cipher text.
4. Reads the input file a character at a time.  Passes transform (see below) the character to 
be encrypted/decrypted and a reference to  the encrypt or decrypt array depending on the mode.
5. Writes a character (encrypted/decrypted/passed over) to the output file.
6. Close the input file and output file
Output: writes a character to the output file
*/
void fileControl(string keyFile, string fileIn, string fileOut, int mode)
{
  fstream infile;
	fstream outfile;
	fstream key;
	
	char ch;
	int i;
	int encKey[ALPH_SIZE];
	int unKey[ALPH_SIZE];
	
	fileOpen(key, keyFile, 'r');
	fileOpen(infile, fileIn, 'r');
	fileOpen(outfile, fileOut, 'w');

	for (i = 0; i < ALPH_SIZE; i++)
	{
	  key >> encKey[i];
	}
	
	
	for (i = 0; i < ALPH_SIZE; i++)
	{
	  key >> unKey[i];
	}
	
	if (mode == 1)
	{		
		while(infile.peek() != EOF)
  	{
  		ch = infile.get();
 	  	if (isalpha(ch))
 	  	{
  	    ch = toupper(ch);
  	  	ch = transform(ch, encKey);
  	  	cout << ch << endl;
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
  	  	ch = transform(ch, unKey);
    	}  
    	outfile.put(ch); 
  	}
	}
	
	key.close();
	infile.close();
	outfile.close();
}

/*
Description: Encrypts/Decrypts an upper case alphabetic character using the 
transposition cipher. Operation depends on whether it is sent the encrypt or decrypt key
Input: upper case alphabetic character, encryption or decryption array
Returns: encrypted or decrypted  version of ch
*/
char transform(char ch, int encDec[])
{
  int charNum;
  
  charNum = ch - 65;
  
  ch = encDec[charNum] + 65;
  
  return ch;
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








