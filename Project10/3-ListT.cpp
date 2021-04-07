/*
Name: Adam Huonder
Class: CPSC 122, Section 1
Date Submitted: March 18th, 2021
Assignment: Project 9 
Description: Program illustrates a linked list with both head and tail pointers 
*/

#include <iostream>
using namespace std;

#include "3-ListT.h"

List::List()
{       
  length = 0;
  head = NULL;
  tail = NULL;
}


List::~List()
{
  int i;
  if (length != 0) {
    while (length > 0)
    {
      //delete using one of my functions
      //make sure to change length in delete function
    }
  }
  
  head = NULL;
  tail = NULL;
  length = 0;
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

void List::PutItemH(const itemType itemIn)
{
  node* tmp = new node;
  tmp->item = itemIn;
  tmp->next = head;
  head = tmp;
  length++;
  if (length == 1)
    tail = tmp;
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

void List::PutItemT(const itemType itemIn)
{
  node* tmp = new node;
  
  if (length == 0)
  {
    tmp->item = itemIn;
    tail = tmp;
    tail->next = NULL;
    length++;
  }
  else
  {
    tmp->item = itemIn;
    tail->next = tmp;
    tail = tmp;
    tail->next = NULL;
    length++;
  }
  if (length == 1)
    head = tmp;
  tmp = NULL;
}

itemType List::GetItemT() const
{
  return tail->item;
}

void List::DeleteItemT()
{
  if (tail == NULL)
  {
    cout << "list is empty you cannot delete" << endl;
    return;
  }
  node* tmpNode;
  tmpNode = PtrTo();
  delete []tail;
  tail = tmpNode;
  tmpNode = NULL;
  length--;
}

void List::Print() const
{
  node* tmpNode = head;
  
  while (tmpNode != tail)
  {
    cout << tmpNode->item << endl;
    tmpNode = tmpNode->next;
  }
  if (tail != NULL)
    cout << tail->item << endl;
}

int List::FindItem(const itemType target) const
{
  int found = 0;
  
  node* tmpNode = head;
  
  while (tmpNode != tail)
  {
    if (tmpNode->item == target) {
      found++;
    }
    tmpNode = tmpNode->next;
  }
  if (tail->item == target) {
    found++;
  }
  return found;
}

int List::DeleteItem(const itemType target)
{
  int numDel = 0;
  
  node* tmpPre = NULL;
  node* tmpCur;
  node* tmpPost;
  
  if (length == 0)
  {
    cout << "Need a list before you delete a target item" << endl;
    return -1;
  }
  
  tmpCur = head;
  tmpPost = head->next;
  
  while (tmpCur != tail)
  {
    if ((tmpCur->item == target) && (tmpCur == head))
    {
      tmpCur = tmpCur->next;
      if (tmpPost != NULL) {
        tmpPost = tmpPost->next;
      }
      DeleteItemH();
      numDel++;
    }
    else if (tmpCur->item == target)
    {
      tmpPre->next = tmpPost;
      delete []tmpCur;
      tmpCur = tmpPost;
      tmpPost = tmpPost->next;
      length--;
      numDel++;
    }
    else if (tmpCur->item != target)
    {
      tmpPre = tmpCur;
      tmpCur = tmpPost;
      tmpPost = tmpPost->next;
    }
  }
  
  if ((tmpCur->item == target) && (tmpCur == tail))
  {
    DeleteItemT();
    numDel++;
  }
  return numDel;
}

node* List::PtrTo()
{
  node* tmpNode = head;
  
  while (tmpNode != tail)
  {
    if (tmpNode->next == tail)
    {
      break;
    }
    tmpNode = tmpNode->next;
  }
  return tmpNode;
}

