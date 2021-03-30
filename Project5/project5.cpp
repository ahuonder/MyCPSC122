/*
Adam Huonder
Paul De Palma
CPSC 122
2/3/21
Project 5 - Caesar Cipher
*/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <ctime>

using namespace std;

int keyGen();
char encrypt(char ch, int key);
void encryptFile(fstream& plainTextFile, fstream& cipherFile, int key);
char decrypt(char ch, int key);
void decryptFile(fstream& cipherFile, fstream& decryptedFile, int key);
void fileOpen(fstream&, string name, char mode);
void mode0(fstream& keyFile, string keyFileName);
void mode1(fstream& keyFile, fstream& PTfile, fstream& CTfile, string keyFileName, string PTfileName, string CTfileName);
void mode2(fstream& keyFile, fstream& CTfile, fstream& PTEfile, string keyFileName, string CTfileName, string PTEfileName);


int main(int argc, char * argv[])
{
	//variables
	int mode = 4;
	int keyInt;
	fstream keyFile, PTfile, CTfile, PTEfile;
	string keyFileName, PTfileName, CTfileName, PTEfileName;
	
	mode = atoi(argv[1]);
	
	if (mode == 0)
	{
		keyFileName = argv[2]; 
		mode0(keyFile, keyFileName);
	}
	else if (mode == 1)
	{
		keyFileName = argv[2]; 
		PTfileName = argv[3];
		CTfileName = argv[4];
		mode1(keyFile, PTfile, CTfile, keyFileName , PTfileName, CTfileName);
	}
	else if (mode == 2)
	{
		keyFileName = argv[2];
		CTfileName = argv[3];
		PTEfileName = argv[4];
		mode2(keyFile, CTfile, PTEfile, keyFileName, CTfileName, PTEfileName);
	}
	else
	{
		//mode number was not 0, 1, or 2
		cout << "Incorrect mode setting." << endl;
		exit(EXIT_FAILURE);
	}
	
	return 0;
}

/*
Description: Randomly generates an integer in the range 1-25
Input: reference to key file
Output: writes a randomly generated integer in the range 1-25
*/
int keyGen()
{
	int keyNum;
	
	srand(time(0));
	
	keyNum = (rand() % 25) + 1;
	
	return keyNum;
}

/*
Description: Encrypts an upper case alphabetic character using the Caesar cipher
Input: upper case alphabetic cahracter, valid key
Returns: encrypted version of ch
*/
char encrypt(char ch, int key)
{
	int pos = ch -'A';
	
	pos = (pos + key) % 26;
	ch = pos + 65;
	
	return ch;
}

/*
Description: Decrypts an upper case alphabetic character using the Caesar cipher
Input: upper case alphabetic character, valid key
Returns: decrypted version of input
*/
char decrypt(char ch, int key)
{
	int pos = ch -'A';
	
	pos = (pos - key + 26) % 26;
	ch = pos + 65;
	
	return ch;
}

/*
Description:; function opens a file
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

/*
Description: encrypts a file using a Caesar cipher
Input: a plain text file, an output file, the key number
Output: writes an encrypted message to the output file
*/
void encryptFile(fstream& plainTextFile, fstream& cipherFile, int key)
{
	char ch;
	
	while(plainTextFile.peek() != EOF)
  {
  	ch = plainTextFile.get();
 	  if (isalpha(ch))
 	  {
      ch = toupper(ch);
    	ch = encrypt(ch, key);
    }  
    cipherFile.put(ch); 
  }
}

/*
Description: decrypts a Caesar cipher file
Input: cipher file, an output file, the cipher key
Output: writes the decrypted message to the output file
*/
void decryptFile(fstream& cipherFile, fstream& decryptedFile, int key)
{
	char ch;
	
	while(cipherFile.peek() != EOF)
  {
  	ch = cipherFile.get();
 	  if (isalpha(ch))
 	  {
      ch = toupper(ch);
    	ch = decrypt(ch, key);
    }  
    decryptedFile.put(ch); 
  }
}

/*
Description: creates a key and adds to key file
Input: key file and its name
Output: executes all of mode 0
*/
void mode0(fstream& keyFile, string keyFileName)
{
	fileOpen(keyFile, keyFileName, 'w');
	keyFile << keyGen() << endl;
}

/*
Description: encrypts a file
Input: 3 files, the key file, PT file, and CT file, and their names
Output: executes all of mode 1
*/
void mode1(fstream& keyFile, fstream& PTfile, fstream& CTfile, string keyFileName, string PTfileName, string CTfileName)
{
	int keyInt;
	
	//opens necessary files
	fileOpen(keyFile, keyFileName, 'r');		
	fileOpen(PTfile, PTfileName, 'r');
	fileOpen(CTfile, CTfileName, 'w');	
		
	//reads in the key from keyfile and stores into keyInt
	keyFile >> keyInt;
	
	encryptFile(PTfile, CTfile, keyInt);
}

/*
Description: decrypts a file
Input: 3 files, the key file, CT file, and PTE file, and their names
Output: executes all of mode 2
*/
void mode2(fstream& keyFile, fstream& CTfile, fstream& PTEfile, string keyFileName, string CTfileName, string PTEfileName)
{
	int keyInt;

	//opens necessary files
	fileOpen(keyFile, keyFileName, 'r');
	fileOpen(CTfile, CTfileName, 'r');
	fileOpen(PTEfile, PTEfileName, 'w');
	
	//reads in the key from keyfile and stores into keyInt
	keyFile >> keyInt;
		
	decryptFile(CTfile, PTEfile, keyInt);
}





