/*
Name: Adam Huonder
Class: CPSC 122, Section 1
Date Submitted: March 18th, 2021
Assignment: Project 9 
Description: Program illustrates a linked list with a head pointer
*/

#include <iostream>
using namespace std;

#include "2-List.h"

List::List()
{       
  length = 0;
  head = NULL;
}


List::~List()
{
  
  //int repeat = length;
  //int i;
  while (length != 0) {
    DeleteItemH();
  }
  
}

bool List::IsEmpty() const
{
  if (length == 0)
    return true;
  else
    return false;
}

int List::GetLength() const
{
  return length;
}

void List::PutItemH(const itemType newItem)
{
  node* tmp = new node;
  tmp->item = newItem;
  tmp->next = head;
  head = tmp;
  length++;
  tmp = NULL;
}

itemType List::GetItemH() const
{
  return head->item;
}

void List::DeleteItemH()
{
  if (head == NULL)
  {
    cout << "list is empty you cannot delete" << endl;
    return;
  }
  node* tmpNode;
  tmpNode = head->next;
  delete []head;
  head = tmpNode;
  tmpNode = NULL;
  length--;
}

void List::Print() const
{
  node* tmpNode = head;
  
  if (head == NULL)
  {
    cout << "list is empty you cannot print" << endl;
    return;
  }
  
  while (tmpNode != NULL)
  {
    cout << tmpNode->item << endl;
    tmpNode = tmpNode->next;
  }
  tmpNode = NULL;
}

int List::Find(const itemType item) const
{
  int pos = 0;
  int counter = 0;
  node* tmpNode = head;
  
  while (tmpNode->next != NULL)
  {
    counter++;
    
    if (tmpNode->item == item) {
      pos = counter;
    }
    tmpNode = tmpNode->next;
  }
  return pos;
}

void List::DeleteItem(const int pos)
{
  node* tmpPre = NULL;
  node* tmpCur;
  node* tmpPost;
  int counter = 0;
  
  if (length == 0)
  {
    cout << "Need a list before you delete a target item" << endl;
    return;
  }
  
  tmpCur = head;
  tmpPost = head->next;
  
  while (tmpCur != NULL)
  {
    counter++;
    if (pos == 1)
    {
      DeleteItemH();
      length--;
      return;
    }
    else if (counter != pos)
    {
      tmpPre = tmpCur;
      tmpCur = tmpPost;
      tmpPost = tmpPost->next;
    }
    else if ((counter == pos) && (pos == length))
    {
      tmpPre->next = tmpPost;
      delete []tmpCur;
      tmpCur = tmpPost;
      //tmpPost = tmpPost->next;
      length--;
      break;
    }
    else if (counter == pos)
    {
      tmpPre->next = tmpPost;
      delete []tmpCur;
      tmpCur = tmpPost;
      tmpPost = tmpPost->next;
      length--;
      break;
    }
  }
}

