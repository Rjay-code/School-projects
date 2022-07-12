#include "AVL_TREE.h"
// sets the adt to null constructor
AVLTreeADT::AVLTreeADT()
{
  root = NULL;
 
} 

//gets height of a tree
int get_height (TreeNode* x);
//finds balanced factor 
int AVLTreeADT::BlancedFactor()
{ 
  return get_height(root->left)-get_height(root->right);
}

int get_height (TreeNode* x)
{
  if (x == NULL)
  {
    return 0;
  }
  else 
  {
    int heightLeft  = get_height(x->left);
    int heightRight = get_height(x->right);
    if (heightLeft > heightRight)
      return heightLeft + 1;
  else
      return heightRight + 1;
  
  }
  
}


TreeNode* RotateRight(TreeNode* x)
// Returns the tree node resulting from a right rotation.
{
  TreeNode* S = x->left;
  TreeNode* B = S->right;
  S->right = x;
  x->left = B;
  return S;
}

TreeNode* RotateLeft(TreeNode* x)
// Returns the tree node resulting from a left rotation.
{
  TreeNode* S = x->right;
  TreeNode* B = S->left;
  S->left = x;
  x->right = B;
  return S;
}

TreeNode* RotateRightLeft(TreeNode* x)
// Returns the tree node resulting from a right-left rotation.
{
  TreeNode* S = x->right;
  x->right = RotateRight(S);
  return RotateLeft(x);
}

TreeNode* RotateLeftRight(TreeNode* x)
// Returns the tree node resulting from a left-right rotation.
{
  TreeNode* S = x->left;
  x->left = RotateLeft(S);
  return RotateRight(x);
}
TreeNode* AVLTreeADT:: Balance(TreeNode* T)
// Checks and balances the subtree T.
{
  int x = BlancedFactor();
  if ( x > 1) {
    if (get_height(T->left) > 1)
    {
      return RotateRight(T);
      count+=1;
    }
    else
    {
      return RotateLeftRight(T);
      count+=2;
    }
  }
  else if (x < -1) {
    if (get_height(root->right) > 0)
    {
      return RotateLeft(T);
      count+=1;
    }
    else
    {
      return RotateRightLeft(T);
      count+=2;
    }
  }
  else
    return T;
}
void AVLTreeADT :: Insert(TreeNode*& tree, int item)
// Inserts item into tree.
// Post:  item is in tree; search property is maintained.
{
  if (tree == NULL)
  {// Insertion place found.
    tree = new TreeNode;
    tree->right = NULL;
    tree->left = NULL;
    tree->info = item;
  }
  else if (item < tree->info) 
  {
    count+=1;
    Insert(tree->left, item);    
    tree->left = Balance(tree);
  }
  else 
  {
    count+=1;
    Insert(tree->right, item);   
    tree->right = Balance(tree);
  }
}

 //puts item in tree 
                    
void AVLTreeADT::PutItem(int item)
{
Insert(root, item);
//root = Balance(root);
}

//finds an item in the tree 
bool find (int x,TreeNode* root);
int AVLTreeADT::Find_item (int item)
{
  if (find (item,root))
  {
  return item;
  }
  else
  {
    cout << "Item is not found.";
  }
  return 0;
}

bool find (int item , TreeNode* root)
{
  if (root->info == item)
  return true;
  else if (root->info < item)
  {
  find (item,root->right);
  }
  else
  {
    find (item,root->left);
  }
  return false;
}



void AVLTreeADT::print()
{
 cout << root->info; 
}
