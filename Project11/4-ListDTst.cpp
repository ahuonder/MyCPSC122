/*
Name: Paul De Palma
Class: CPSC 122, Section 1
Date Submitted: April 2nd, 2021
Assignment: Project 11
Description: doubly linked list with dummy notes at head and tail
*/

#include <iostream>
using namespace std;

#include "4-ListD.h"

void TestInsert();
void TestPrintBackward();
void TestDelete();
void TestDeleteAll();
void TestSort();

int main()
{
 /************************************************************
 
 
 
 
 Please uncomment the tests one at a time. Uncommenting all
 of the tests will result in some not working. Thank you!
 
 
 
 
 ************************************************************/
 //TestInsert();
 //TestPrintBackward();
 //TestDelete();
 //TestDeleteAll();
 TestSort();
 
 return 0;
}

void TestInsert()
{

  ListD* lst = new ListD;
  for (int i = 1; i <= 6; i++)
    lst->Insert(i,i);

  //test general case insert
  cout << "Passed Insert Test 1 if 1 through 6 appear on subsequent lines" << endl;
  lst->PrintForward();
  cout << endl;

  //test insert at the head
  lst->Insert(0,1);
  cout << "Passed Insert Test 2 if 0 appears in position 1" << endl; 
  lst->PrintForward();
  cout << endl;

  //test insert at the tail 
  lst->Insert(100,8);
  cout << "Passed Insert Test 3 if 100 appears in final position" << endl; 
  lst->PrintForward();
  cout << endl;
 
  //test insert in middle 
  lst->Insert(50,5);
  cout << "Passed Insert Test 4 if 50 appears in middle position" << endl; 
  lst->PrintForward();
  cout << endl;
 
  delete lst;
}

void TestPrintBackward()
{
  ListD* lst = new ListD;
  for (int i = 1; i < 6; i++)
    lst->Insert(i,i);
    
  cout << "List is 1 through 5. Should be printed is reverse numeric order." << endl;
  lst->PrintBackward();
  cout << endl;
  
  delete lst;
}

void TestDelete()
{
  ListD* lst = new ListD;
  for (int i = 1; i < 6; i++)
    lst->Insert(i,i);
  
  cout << "List was assigned 1 through 5. the 3 should be missing, it was deleted." << endl;
  lst->Delete(3);
  lst->PrintForward();
  cout << endl;

  delete lst;
}

void TestDeleteAll()
{
  int deleteNum = 0;
  ListD* lst = new ListD;
  
  for (int i = 1; i < 4; i++)
    lst->Insert(6,i);
  
  for (int i = 4; i < 6; i++)
    lst->Insert(9,i);
  
  cout << "List is 3 sixes followed by 2 nines. The nines should be missing and the number of deleted items should be 2." << endl;
  
  deleteNum = lst->DeleteAll(9);
  lst->PrintForward();
  cout << endl << "number of deletions: " << deleteNum << endl; 

  delete lst;
}

void TestSort()
{
  int pos = 1;
  ListD* lst = new ListD;

  lst->Insert(38,1);
  lst->Insert(16,2);
  lst->Insert(7,3);
  lst->Insert(24,4);
  lst->Insert(31,5);
  lst->Insert(80,6);
  
  cout << "The list is:" << endl;
  
  lst->PrintForward();
  cout << endl;
  
  lst->Sort();
  
  cout << "The list should now be ordered least to greatest." << endl;
  
  lst->PrintForward();
  
  delete lst;
}

