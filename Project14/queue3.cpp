//Queue using List and composition 
#include <iostream>
using namespace std;
#include "queue3.h"

PQueue::PQueue() : Queue()
{

}

PQueue::PQueue(PQueue* q) : Queue(q)
{

}

void PQueue::Enqueue(itemType newItem)
{
  node* temp = new node;
  
  //if the list is empty case
  if (length == 0)
  {
    head = temp;
    tail = head;
    temp->next = NULL;
  }
  else
  {
    temp->next = PtrTo(newItem);
  }
  temp->item = newItem;
  
  if (head->item >= newItem && length > 0)
  {
    PutItemH(newItem);
    return;
  }
  else if (tail->item < newItem && length > 0)
  {
    PutItemT(newItem);
    return;
  }
  
  node* pre = head;
  
  if (length > 0 && temp->next != head)
  {
    while (pre != tail->next)
    {
      if (pre->next == temp->next)
      {
        pre->next = temp;
        cout << "pre is pointing to: " << pre->item << endl;
        break;
      }
      pre = pre->next;
    }
  }
  
  temp = NULL;
  pre = NULL;
  length++;
}

node* PQueue::PtrTo(itemType newItem)
{
  node* inPt = head;
  
  while (inPt != tail->next)
  {
    if (inPt->item >= newItem)
      return inPt;
    
    inPt = inPt->next;
  }
  
  if (newItem > tail->item)
  {
    return NULL;
  }
  //shouldn't get here
  return NULL;
}
	
