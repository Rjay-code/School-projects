#include <iostream>
using namespace std;


struct TreeNode
{
  int info;
  TreeNode* left;
  TreeNode* right;
};
#ifndef AVLTreeADT_h
#define AVLTreeADT_h
class AVLTreeADT
{
public:
  AVLTreeADT(); 
  int BlancedFactor();
  TreeNode* Balance(TreeNode* T);
  void PutItem(int item);
  void Insert(TreeNode*& tree, int item);
  int Find_item(int item);
  void print();
  int count = 0;
private:
  TreeNode* root;
  
  
};
#endif