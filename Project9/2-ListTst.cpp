/*
Name: Adam Huonder
Class: CPSC 122, Section 1
Date Submitted: March 24th, 2021
Assignment: Project 9 
Description: Program illustrates a linked list with a head pointer
*/

#include <iostream>
using namespace std;

#include "2-List.h"

int main()
{
  List lst;
  List* lst1 = new List;
  /****************************************************************************
  
  
  
  
  
  
  Please uncomment the tests one at a time, uncommenting all at the same time
  will result in the tests not working. The print function is used in many
  of the tests, these should serve as tests of the print function as well.
  Thank you!
  
  
  
  
  
  
  
  ****************************************************************************/
  
  
  // length test
  for (int i = 0; i < 5; i++) 
    lst.PutItemH(i);

  for (int i = 0; i < 5; i++)
    lst1->PutItemH(i);
  
  cout << "************************GetLength Test*************************\n";
  cout << "the lists, static and dynamic, are filled with 0-4.\nThe resulting values should be 5" << endl;
  cout << lst.GetLength() << endl;
  cout << lst1->GetLength() << endl;
  cout << "***************************************************************\n";
  
  
  /*
  // is empty test
  for (int i = 0; i < 5; i++)
    lst1->PutItemH(i);
  
  bool empty;
  bool empty2;
  
  empty = lst.IsEmpty();
  empty2 = lst1->IsEmpty();
  cout << "************************IsEmpty Test*************************\n";
  cout << "The static list is empty, the dynamic has 0-4.\nThe result should be first being empty and the second not being empty.\n";
  if (empty == true)
    cout << "the list is empty" << endl;
  else
    cout << "the list is not empty" << endl;
  
  if (empty2 == true)
    cout << "the list is empty" << endl;
  else
    cout << "the list is not empty" << endl;
  cout << "*************************************************************\n";
  */
  
  /*
  //put item h test
  for (int i = 0; i < 5; i++) 
    lst.PutItemH(i);

  for (int i = 0; i < 5; i++)
    lst1->PutItemH(i);
  cout << "************************PutItemH Test*************************\n";
  cout << "Both lists have 4,3,2,1,0 stored in them.\nBoth of them will be printed for confirmation that the function works.\n";
  lst.Print();
  cout << endl;
  
  lst1->Print();
  cout << endl;
  cout << "**************************************************************\n";
  */
  
  /*
  //get item h test
  cout << "************************GetItemH Test*************************\n";
  lst.PutItemH(7);
  lst1->PutItemH(8);
  cout << "The head of the first list is 7, the second, 8.\nBoth should be printed below.\n"; 
  cout << lst.GetItemH() << endl;
  cout << lst1->GetItemH() << endl;
  cout << "**************************************************************\n";
  */
  
  /*
  //delete item H test
  cout << "************************DeleteItemH Test*************************\n";
  lst.PutItemH(7);
  lst.PutItemH(4);
  
  lst1->PutItemH(8);
  lst1->PutItemH(4);
  
  lst.Print();
  
  cout << endl;
  
  lst1->Print();
  
  lst.DeleteItemH();
  lst1->DeleteItemH();
  
  cout << "Both lists start with 4 then go to 7 and 8 respectively.\nThe 4 should be deleted by the DeleteItemH function.\n";
  
  lst.Print();
  cout << endl;
  lst1->Print();
  cout << endl;
  cout << "*****************************************************************\n";
  */
  
  /*
  //find item test
  cout << "************************Find Test*************************\n";
  int num1, num2;
  lst.PutItemH(1);
  lst.PutItemH(2);
  lst.PutItemH(3);
  lst.PutItemH(4);
  lst.PutItemH(5);
  
  lst1->PutItemH(1);
  lst1->PutItemH(2);
  lst1->PutItemH(3);
  lst1->PutItemH(4);
  lst1->PutItemH(5);
  cout << "Each list is 5,4,3,2,1.\nThe FindItem function target is 4 and should return 2 for both.\n";
  num1 = lst.Find(4);
  num2 = lst1->Find(4);
  
  cout << num1 << ", " << num2 << endl;
  cout << "**********************************************************\n";
  */
  
  /*
  //delete item test
  cout << "************************DeleteItem Test*************************\n";
  int num3, num4;
  lst.PutItemH(5);
  lst.PutItemH(2);
  lst.PutItemH(2);
  lst.PutItemH(2);
  lst.PutItemH(5);
  
  lst1->PutItemH(5);
  lst1->PutItemH(2);
  lst1->PutItemH(2);
  lst1->PutItemH(2);
  lst1->PutItemH(5);
  cout << "Each list is 5,2,2,2,5.\nThe DeleteItem function target is 5.\n";
  cout << "Each list should be changed to 5,2,2,2.\n";
  lst.DeleteItem(1);
  lst1->DeleteItem(1);
  
  lst.Print();
  cout << endl;
  lst1->Print();
  cout << endl;
  cout << "*****************************************************************\n";
  */
  
  cout << endl;
  
  return 0;
}










