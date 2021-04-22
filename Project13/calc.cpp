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
#include <cstring>
#include <cmath>
#include <stack>

//Write functions in this order.  Constructor and destructor will be built as the
//functions it invokes are written

Calc::Calc(char* argvIn)
{
  inFix = argvIn;
  stk = new Stack;
  
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
  
  InFixToPostFix();
}

Calc::~Calc()
{
  delete []inFix;
  inFix = NULL;
  
  delete stk;
  
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
  parsedEq = NULL;
}

bool Calc::CheckParens()
{
  int i = 0;
  
  while (inFix[i] != '\0')
  {
    if (inFix[i] == '(')
    {
      stk->Push(inFix[i]);
    }
    else if (stk->IsEmpty() && inFix[i] == ')')
    {
      return false;
    }
    else if (inFix[i] == ')')
    {
      stk->Pop();
    }
    i++;
  }
  
  if (stk->IsEmpty())
    return true;

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

void Calc::InFixToPostFix()
{
  int i = 0, inFixLength = 0, postIdx = 0;
  
  while(inFix[i] != '\0')
  {
    i++;
  }  
  inFixLength = i + 1;
  
  i = 0;
  
  postFix = new char[inFixLength];
  
  while(inFix[i] != '\0')
  {
    if (inFix[i] >= 65 && inFix[i] <= 90) //if its a letter
    {
      postFix[postIdx] = inFix[i];
      postIdx++;
    }
    else if (inFix[i] == '+' || inFix[i] == '-' || inFix[i] == '*' || inFix[i] == '/')
    {
      postFix[postIdx] = inFix[i+1];
      postIdx++;
      postFix[postIdx] = inFix[i];
      postIdx++;
      i++;
    }
    i++;
  }
  postFix[postIdx] = '\0';
}

void Calc::DisplayPostFix()
{
  int i = 0;
  
  while (postFix[i] != '\0')
  {
    cout << postFix[i];
    i++;
  }
  cout << endl;
}

int Calc::Evaluate()
{
  int i = 0;
  
  while (postFix[i] != '\0')
  {
    if (postFix[i] >= 'A' && postFix[i] <= 'Z')
    {
      stk->Push(postFix[i]);
    }
    else
    {
      Compute(postFix[i]);
    }
    i++;
  }
  return valueTbl[valueIdx - 1];
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

void Calc::Compute(char operation)
{
  int num1, num2, result;
  
  num1 = valueTbl[stk->Peek() - 65];
  stk->Pop();
  
  num2 = valueTbl[stk->Peek() - 65];
  stk->Pop();
  
  if (operation == '+')
    result = num2 + num1;

  if (operation == '-')
    result = num2 - num1;

  if (operation == '*')
    result = num2 * num1;

  if (operation == '/')
    result = num2 / num1;
  
  valueTbl[valueIdx] = result;
  stk->Push(valueIdx + 65);
  valueIdx++;
  
  return;
}








