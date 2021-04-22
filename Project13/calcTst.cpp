/*
Name: Adam Huonder
Class: CPSC 122, Section 1
Date Submitted: 4/21/21
Assignment: project 12 
Description: Calculator Assignment 
To Compile: make
To Execute: ./calc "(121+12)"
*/

#include <iostream>
using namespace std;

#include "calc.h"

int main(int argc, char* argv[])
{
  Calc* C = new Calc(argv[1]);
  int answer = 0;
  
  C->DisplayInFix();
  C->DisplayPostFix();
  answer = C->Evaluate();
  cout << answer << endl;
  
  delete C;
  return 0;
}
