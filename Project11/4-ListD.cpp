/*
Name: Adam Huonder
Class: CPSC 122, Section 1
Date Submitted: April 2nd, 2021
Assignment: Project 11
Description: doubly linked list with dummy notes at head and tail
*/

#include <iostream>
#include <climits>
using namespace std;

#include "4-ListD.h"

template <typename T>
ListD<T>::ListD()
{
  length = 0;
 
  //create dummy nodes;
  head = new doubleNode<T>;
  tail = new doubleNode<T>;

  //set values for head dummy node;
  head->prev = NULL;
  head->item = INT_MIN;
  head->next = tail;

  //set values for tail dummy node;
  tail->prev = head; 
  tail->item = INT_MAX;
  tail->next = NULL;
}

template <typename T>
ListD<T>::ListD(ListD* lst)
{
  length = 0; 
 
  //create dummy nodes;
  head = new doubleNode<T>;
  tail = new doubleNode<T>;

  //set values for head dummy node;
  head->prev = NULL;
  head->item = INT_MIN;
  head->next = tail;

  //set values for tail dummy node;
  tail->prev = head; 
  tail->item = INT_MAX;
  tail->next = NULL;

  //returns pointer to the first node, which is what we want here
  doubleNode<T>* cur = lst->FindPosition(2);
  for (int i = 1; i <= lst->length; i++)
  {
    Insert(cur->item,i);
    cur = cur->next;
  }
}

template <typename T>
ListD<T>::~ListD()
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

template <typename T>
doubleNode<T>* ListD<T>::FindPosition(int pos)
{
  //Inserting at the tail is a special case.  It can be made much more efficient than
  //this.
  doubleNode<T>* cur = head;
  int i = 0;  //begin at the dummy node
  while (i < pos - 1)
  {
    cur = cur->next;
    i++;
  }
  return cur;
} 

template <typename T>
void ListD<T>::Insert(T item, int pos)
{
  //new node goes between these two nodes
  doubleNode<T>* insertPtA = FindPosition(pos);  
  doubleNode<T>* insertPtB = insertPtA->next; 

  //create new node and set its values
  doubleNode<T>* tmp = new doubleNode<T>; 
  tmp->prev = insertPtA;
  tmp->item = item;
  tmp->next = insertPtB;

  //set pointers for nodes before and after the insertion point
  insertPtA->next = tmp;
  insertPtB->prev = tmp;

  length++;
}

template <typename T>
void ListD<T>::PrintForward()
{
  doubleNode<T>*  cur = head->next;

  int i = 0;
  while (i < length)
  {
    cout << cur->item << endl;
    cur = cur->next;
    i++;
  }
}

template <typename T>
void ListD<T>::PrintBackward()
{
  doubleNode<T>*  cur = tail->prev;

  int i = 0;
  while (i < length)
  {
    cout << cur->item << endl;
    cur = cur->prev;
    i++;
  }
}

template <typename T>
void ListD<T>::Delete(int pos)
{
  doubleNode<T>* find = head->next;
  int posCount = 1;
  
  while (posCount != pos)
  {
    find = find->next;
    posCount++;
  }
  
  doubleNode<T>* pre  = find->prev;
  doubleNode<T>* post = find->next;
  
  pre->next = post;
  
  if (post != NULL)
    post->prev = pre;
  
  delete []find;
  length--;
  
  find = NULL;
  pre = NULL;
  post = NULL;
}

template <typename T>
int ListD<T>::DeleteAll(T item)
{
  int deleteCount = 0;
  int pos = 1;
  doubleNode<T>* find = head->next;
  
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

template <typename T>
void ListD<T>::Sort()
{
  doubleNode<T>* switchSpot = head->next;
  doubleNode<T>* cur = head->next;
  doubleNode<T>* minPointer = head->next;
  T item1;
  T item2;
  T temp;
  
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



















 
