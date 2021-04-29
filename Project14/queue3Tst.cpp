#include <iostream>
using namespace std;

#include "queue3.h"


int main()
{
  PQueue* que = new PQueue;
  int i = 1;
  
  que->Enqueue(6);
  que->Enqueue(4);
  que->Enqueue(77);
  que->Enqueue(51);
  que->Enqueue(46);
  que->Enqueue(80);
  que->Enqueue(65);
  que->Enqueue(2);
  que->Enqueue(69);
  que->Print();

  que->Enqueue(8);
  que->Print();
  
  delete que;
}
