/*
Name: Paul De Palma
Class: CPSC 122, Section 1
Date Submitted: April 2nd, 2021
Assignment: Project 11
Description: doubly linked list with dummy notes at head and tail
*/

#include <iostream>
#include <climits>
using namespace std;

#include "4-ListD.h"

   
ListD::ListD()
{
  length = 0;
 
  //create dummy nodes;
  head = new doubleNode;
  tail = new doubleNode;

  //set values for head dummy node;
  head->prev = NULL;
  head->item = INT_MIN;
  head->next = tail;

  //set values for tail dummy node;
  tail->prev = head; 
  tail->item = INT_MAX;
  tail->next = NULL;
}

ListD::ListD(ListD* lst)
{
  length = 0; 
 
  //create dummy nodes;
  head = new doubleNode;
  tail = new doubleNode;

  //set values for head dummy node;
  head->prev = NULL;
  head->item = INT_MIN;
  head->next = tail;

  //set values for tail dummy node;
  tail->prev = head; 
  tail->item = INT_MAX;
  tail->next = NULL;

  //returns pointer to the first node, which is what we want here
  doubleNode* cur = lst->FindPosition(2);
  for (int i = 1; i <= lst->length; i++)
  {
    Insert(cur->item,i);
    cur = cur->next;
  }
}

ListD::~ListD()
{
  while(length > 0)
  {
    Delete(1);
  }
    delete []head;
    delete []tail;
    
    head = NULL;
    tail = NULL;
}

doubleNode* ListD::FindPosition(int pos)
{
  //Inserting at the tail is a special case.  It can be made much more efficient than
  //this.
  doubleNode* cur = head;
  int i = 0;  //begin at the dummy node
  while (i < pos - 1)
  {
    cur = cur->next;
    i++;
  }
  return cur;
} 
  
void ListD::Insert(itemType item, int pos)
{
  //new node goes between these two nodes
  doubleNode* insertPtA = FindPosition(pos);  
  doubleNode* insertPtB = insertPtA->next; 

  //create new node and set its values
  doubleNode* tmp = new doubleNode; 
  tmp->prev = insertPtA;
  tmp->item = item;
  tmp->next = insertPtB;

  //set pointers for nodes before and after the insertion point
  insertPtA->next = tmp;
  insertPtB->prev = tmp;

  length++;
}

void ListD::PrintForward()
{
  doubleNode*  cur = head->next;

  int i = 0;
  while (i < length)
  {
    cout << cur->item << endl;
    cur = cur->next;
    i++;
  }
}

void ListD::PrintBackward()
{
  doubleNode*  cur = tail->prev;

  int i = 0;
  while (i < length)
  {
    cout << cur->item << endl;
    cur = cur->prev;
    i++;
  }
}

void ListD::Delete(int pos)
{
  doubleNode* find = head->next;
  int posCount = 1;
  
  while (posCount != pos)
  {
    find = find->next;
    posCount++;
  }
  
  doubleNode* pre  = find->prev;
  doubleNode* post = find->next;
  
  pre->next = post;
  
  if (post != NULL)
    post->prev = pre;
  
  delete []find;
  length--;
  
  find = NULL;
  pre = NULL;
  post = NULL;
}

int ListD::DeleteAll(itemType item)
{
  int deleteCount = 0;
  int pos = 1;
  doubleNode* find = head->next;
  
  while (find != tail)
  {
    if (item == find->item)
    {
      Delete(pos);
      deleteCount++;
    }
    else
      pos++;
    
    find = find->next;
  }
  
  
  return deleteCount;
}

void ListD::Sort()
{
  doubleNode* switchSpot = head->next;
  doubleNode* cur = head->next;
  doubleNode* minPointer = head->next;
  itemType item1;
  itemType item2;
  itemType temp;
  
  while (switchSpot != tail)
  {
    cur = switchSpot->next;
    minPointer = switchSpot;
    
    while(cur != tail)
    {
      if (cur->item < minPointer->item)
        minPointer = cur;
      
      cur = cur->next;
    }
    if (minPointer != switchSpot)
    {
      temp = switchSpot->item;
      switchSpot->item = minPointer->item;
      minPointer->item = temp;
    }
    switchSpot = switchSpot->next;
  }
}



















 
