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
#include <cstring>
#include <cmath>


//Write functions in this order.  Constructor and destructor will be built as the
//functions it invokes are written

Calc::Calc(char* argvIn)
{
  inFix = argvIn;
  if (!CheckTokens())
  {
    cout << "Invalid character in equation." << endl;
    exit(EXIT_FAILURE);
  }
  
  MakeValueTbl();
  Parse();
  
  if (!CheckParens())
  {
    cout << "Parentheses are unbalanced." << endl;
    exit(EXIT_FAILURE);
  }
}

Calc::~Calc()
{
  delete []inFix;
  inFix = NULL;
  
  delete []valueTbl;
  valueTbl = NULL;
}

bool Calc::CheckTokens()
{
  int i = 0;
  
  while (inFix[i] != '\0')
  {
    if (inFix[i] < 40 || inFix[i] > 57 || inFix[i] == 46 || inFix[i] == 44)
      return false;
      
    i++;
  }
  return true;
}

void Calc::MakeValueTbl()
{
  valueTbl = new int[26];
  
  for (int i = 0; i < 26; i++)
  {
    valueTbl[i] = 0;
  }
  valueIdx = 0;
}

void Calc::Parse()
{
  int i = 0, x = 0, value = 0, digitPower = 0, inFixLength = 0, parsedEqIdx = 0;
  int lastIdx = 0;
  
  while(inFix[i] != '\0')
  {
    i++;
  }  
  inFixLength = i + 1;
  
  i = 0;
  char* parsedEq = new char[inFixLength];
  
  while (inFix[i] != '\0')
  { 
    if (inFix[i] > 47 && inFix[i] < 58)
    {
      lastIdx = FindLast(i);
      for (x = lastIdx; x >= i; x--)
      {
        value  += (inFix[x] - 48) * pow(10 , digitPower);
        digitPower++;
      }
      i = lastIdx;
      valueTbl[valueIdx] = value;
      value = 0;
      digitPower = 0;
      parsedEq[parsedEqIdx] = valueIdx + 65;
      valueIdx++;
    }
    else
      parsedEq[parsedEqIdx] = inFix[i];   
    
    parsedEqIdx++;
    i++;
  }
  parsedEq[parsedEqIdx] = '\0';
  inFix = parsedEq;
}

bool Calc::CheckParens()
{
  int i = 0;
  int parenBal = 0;
  
  while (inFix[i] != '\0')
  {
    if (inFix[i] == '(')
    {
      parenBal++;
    }
    else if (inFix[i] == ')')
    {
      parenBal--;
    }
    i++;
  }
  if (parenBal == 0)
    return true;
    
  else
    return false;
}

void Calc::DisplayInFix()
{
  int i = 0;
  while (inFix[i] != '\0')
  {
    cout << inFix[i];
    i++;
  }
  cout << endl;
}

int Calc::FindLast(int cur)
{
  while (inFix[cur] != '\0')
  {
    if (inFix[cur] > 47 && inFix[cur] < 58)
      cur++;
    else
      break;
  }
  return cur - 1;
}









