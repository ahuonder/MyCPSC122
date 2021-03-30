/*
Name: Adam Huonder
Class: CPSC 122, Section 1
Date Submitted: March 5th, 2021
Assignment: Project 8
Description: Program illustrates using class MyString 
*/

#include <iostream>
using namespace std;

#include "8-MyString.h"
#include <cstring>

//Constructor function
MyString::MyString(char const* strIn)
{
  int i = 0;
  
  while (strIn[i] != '\0')
  {
    i++;
  }
  length = i;
  
  str = new char[length + 1];
  
  for (i = 0; i < (length + 1); i++)
  {
    str[i] = strIn[i];
  }
}

//Destructor function
//once you get the constructor working, remove the comments.
MyString::~MyString()
{
  delete []str; 
}

/*
Desc: Displays the contents of MyString 
Pre: None
Post: Contents of MyString are displayed on the screen 
*/ 
void MyString::myDisplay()
{
  int i = 0;
  for (i = 0; i < length; i++)
  {
    cout << str[i];
  }
  cout << endl;
}

/*
Desc: Overwrites contents of MyString.str with what strIn points to 
To clarify: nothing of str remains. strIn replaces it entirely
Pre: strIn is a null-terminated string 
Post: contents of strIn replaces MyString 
*/
void MyString::myStrcpy(char const* strIn)
{
  int inlength;
  int i = 0;
  
  delete []str;
  
  while (strIn[i] != '\0')
  {
    i++;
  }
  inlength = i;
  
  str = new char[inlength + 1];
  
  for (i = 0; i < inlength; i++)
  {
    str[i] = strIn[i];
  }
  
  str[inlength + 1] = '\0';
  
  length = inlength;
}  

/*
Desc: Used to determine the length of MyString.str
Pre:  An instance of MyString exists
Post: Returns the number of characters, excluding the null character
      in MyString. 
*/
int MyString::myStrlen()
{
  return length;
}  

/*
Desc: Determines if MyString.str is equivalent to an input C-String 
Pre:  An instance of MyString exists. strIn is a null-terminated
      string.
Post: Returns true if the strings are equivalent, false otherwise 
*/
bool MyString::isEqual(char const* strIn)
{
  int i = 0;
  int counter = 0;
  
  for (i = 0; i < length; i++)
  {
    if (strIn[i] == str[i])
      counter++;
  }
  if (counter == length)
    return true;
  else
    return false;
} 

/*
Desc: Searches for a substring within MyString 
Pre:  An instance of MyString exists
Post: If strIn is a substring of MyString.str, returns
      the index of its starting positon, -1 otherwise
*/
int MyString::find(char const* strIn)
{
  int i = 0;
  int k = 0;
  int inlength;
  int index = -1;
  
  while (strIn[i] != '\0')
  {
    i++;
  }
  inlength = i;
  
  for (i = 0; i < length; i++)
  {
    if (str[i] == strIn[0])
    {
      for (k = 0; k < inlength; k++)
      {
        if (str[k+i] == strIn[k])
        {
          index = i;
        }
        else
        {
          index = -1;
        }
      }
    }
    if (index != -1)
      break;
  }
  return index;
}

/*
Desc: Concatenates strIn with MyString 
Pre:  An instance of MyString exists. strIn is a null-terminated string
Post: strIn is concatenated with MyString.str.  Ex.
      MyString.str is ABC. strIn is DEF.  MyString is still a null-terminated
      string, but contains: ABCDEF. 
*/
void MyString::concat(char const* strIn)
{
  int inlength = 0;
  int i = 0;
  char* strCat;
  
  while (strIn[i] != '\0')
  {
    i++;
  }
  inlength = i;
  
  strCat = new char[length + inlength + 1];
  
  for (i = 0; i < length; i++)
  {
    strCat[i] = str[i];
  }
  
  for (i = length; i < length + inlength; i++)
  {
    strCat[i] = strIn[i - length];
  }
  
  length += inlength;
  
  strCat[length + inlength + 1] = '\0';
  
  delete []str;
  
  str = strCat;
}



   
   
   
   
