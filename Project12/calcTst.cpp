/*
Name: Adam Huonder
Class: CPSC 122, Section 1
Date Submitted: 4/10/21
Assignment: project 12 
Description: Part 1 of Calculator Assignment 
To Compile: make
To Execute: ./calc "(121+12)"
*/

#include <iostream>
using namespace std;

#include "calc.h"

int main(int argc, char* argv[])
{
  if (argc == 2)
  {
    Calc* C = new Calc(argv[1]);
    C->DisplayInFix();
    delete C;
  }
  else if (argc == 1)
  {
    cout << "No equation given." << endl;
  }
  else
  {
    cout << "Too many arguments." << endl;
  }
  return 0;
}
