/*
Name: Adam Huonder
Class: CPSC 122, Section 1
Date Submitted: March 5th, 2021
Assignment: Project 8
Description: Program illustrates using class MyString 
*/

#include "8-MyString.h"
#include <iostream> 
using namespace std;


int main(int argc, char* argv[])
{
  MyString str1(argv[1]);
  MyString* str2 = new MyString(argv[1]);
  
  char* test;
  test = new char[2];
  test[0] = 'z';
  test[1] = 'z';
  
  /*
  //Test of myDisplay
  cout << "***************************************" << endl;
  cout << "*****Test 1 myDisplay*****" << endl;
  cout << "static test" << endl;
  cout << "output should be the command line input" << endl;
  str1.myDisplay();
  cout << endl;
  cout << "*****Test 2  myDisplay*****" << endl;
  cout << "dynamic test" << endl;
  cout << "output should be the command line input" << endl;
  str2->myDisplay();
  cout << endl;
  cout << "***************************************" << endl;
  //End Test of myDisplay
  */
  
  /*
  //test of myStrcpy
  cout << "***************************************" << endl;
  cout << "*****Test 1 myStrcpy*****" << endl;
  cout << "static test" << endl;
  cout << "output should be zz not the command line input" << endl;
  str1.myStrcpy(test);
  str1.myDisplay();
  cout << endl;
  cout << "*****Test 2  myStrcpy*****" << endl;
  cout << "dynamic test" << endl;
  cout << "output should be zz not the command line input" << endl;
  str2->myStrcpy(test);
  str2->myDisplay();
  cout << endl;
  cout << "***************************************" << endl;
  //End Test of myStrcpy
  */
  
  /*
  //Test of myStrlen
  cout << "***************************************" << endl;
  cout << "*****Test 1 myStrlen*****" << endl;
  cout << "static test" << endl;
  cout << "output should be the length of the string" << endl;
  cout << str1.myStrlen();
  cout << endl;
  cout << "*****Test 2  myStrlen*****" << endl;
  cout << "dynamic test" << endl;
  cout << "output should be the length of the string" << endl;
  cout << str2->myStrlen();
  cout << endl;
  cout << "***************************************" << endl;
  //End Test of myStrlen
  */
  
  /*
  //Test of isEqual
  cout << "***************************************" << endl;
  cout << "*****Test 1 isEqual*****" << endl;
  cout << "static test" << endl;
  cout << "output should be true if the input is zz, false if anything else" << endl;
  if (str1.isEqual(test) == true)
    cout << "true";
  else
    cout << "false";
  cout << endl;
  cout << endl;
  cout << "*****Test 2  myDisplay*****" << endl;
  cout << "dynamic test" << endl;
  cout << "output should be true if the input is zz, false if anything else" << endl;
  if (str2->isEqual(test) == true)
    cout << "true";
  else
    cout << "false";
  cout << endl;
  cout << "***************************************" << endl;
  //End Test of isEqual
  */
  
  /*
  //Test of find
  cout << "***************************************" << endl;
  cout << "*****Test 1 find*****" << endl;
  cout << "static test" << endl;
  cout << "output should be an index if the command line input has zz in it, -1 if not" << endl;
  cout << str1.find(test);
  cout << endl;
  cout << "*****Test 2  find*****" << endl;
  cout << "dynamic test" << endl;
  cout << "output should be an index if the command line input has zz in it, -1 if not" << endl;
  cout << str2->find(test);
  cout << endl;
  cout << "***************************************" << endl;
  //End Test of find
  */
  
  /*
  //Test of concat
  cout << "***************************************" << endl;
  cout << "*****Test 1 concat*****" << endl;
  cout << "static test" << endl;
  cout << "output should be the command line input with zz added to the end" << endl;
  str1.concat(test);
  str1.myDisplay();
  cout << endl;
  cout << "*****Test 2  concat*****" << endl;
  cout << "dynamic test" << endl;
  cout << "output should be the command line input with zz added to the end" << endl;
  str2->concat(test);
  str2->myDisplay();
  cout << endl;
  cout << "***************************************" << endl;
  //End Test of concat
  */
  
  delete str2;
  return 0;  
}












