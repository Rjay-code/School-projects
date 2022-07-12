// Implementation file for Unsorted.h

#include "unsortedArray.h"
using namespace std;
#include <iostream>

UnsortedTypeArray::UnsortedTypeArray()
{
  length = 0;
}
bool UnsortedTypeArray::IsFull() const
{
  return (length == MAX_ITEMS);
}
int UnsortedTypeArray::GetLength() const
{
  return length;
}

ItemType UnsortedTypeArray::GetItem(ItemType item, bool& found) 
// Pre:  Key member(s) of item is initialized. 
// Post: If found, item's key matches an element's key in the 
//       list and a copy of that element has been returned;
//       otherwise, item is returned. 
{
  bool moreToSearch;
  int location = 0;
  found = false;

  moreToSearch = (location < length);

  while (moreToSearch && !found) 
  {
    switch (item.ComparedTo(info[location]))
    {
      case LESS    : 
      case GREATER : location++;
                     moreToSearch = (location < length);
                     break;
      case EQUAL   : found = true;
                     item = info[location];
                     break;
    }
  }
  return item;
}
void UnsortedTypeArray::MakeEmpty()
// Post: list is empty.
{
  length = 0;
}
void UnsortedTypeArray::PutItem(ItemType item)
// Post: item is in the list.
{
  info[length] = item;
  length++;
}
void UnsortedTypeArray::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
  int location = 0;

  while (item.ComparedTo(info[location]) != EQUAL)
    location++;

  info[location] = info[length - 1];
  length--;
}
void UnsortedTypeArray::ResetList()
// Post: currentPos has been initialized.
{
  currentPos = -1;
}

ItemType UnsortedTypeArray::GetNextItem()
// Pre:  ResetList was called to initialized iteration.
//       No transformer has been executed since last call.
//       currentPos is defined.
// Post: item is current item.
//       Current position has been updated.
{
  currentPos++;
  return info[currentPos];
}
void  UnsortedTypeArray::head()
  //Precondition: list has been initialized and is not empty.
 //Postcondition: return value is the last item inserted in the list.
 //This is O(1) or constant time
 {
   if(GetLength() == 0)
   cout << info[NULL]; 
   else  
   cout << info[length];  
 }
 void UnsortedTypeArray::tail()
 //Precondition: list has been initialized and is not empty.
 //Postcondition: return value is a new list with the last item inserted in the list removed.
 //This is O(1) or constant time
{
  if(GetLength() == 0)
  cout << info[NULL];
  else
  cout << info[length-1];
}
