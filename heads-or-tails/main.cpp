#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
#include "unsorted.h"
#include "unsortedArray.h"
int main() 
{
  UnsortedTypeArray list;
  UnsortedType linked;
  ItemType item;
  bool found = true;
   int x =rand() %51;
  for(int i = 0; i<50; i++)
  {
    int x = rand() %101;
    item.Initialize(x);
    list.PutItem(item);
    linked.PutItem(item);
   
    if(i == x)
    {
     //cout<<list.head;
     //list.tail; 
    }
  }
  

}
