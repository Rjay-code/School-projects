#include <iostream>
using namespace std;
#include "AVL_TREE.h"

int main()
{
  AVLTreeADT tree;

tree.PutItem(10);
tree.PutItem(15);
tree.PutItem(5);
tree.PutItem(2);
tree.PutItem(1);
 /*for(int i = 0; i < 11;i++)
  {
    int y = i+1;
    y = 1000-y;
    srand(time(NULL));
    int x = rand() % y + 1;
    cout<< x<< endl;
    tree.PutItem(x);
  }*/
  cout<<tree.BlancedFactor();
  
}