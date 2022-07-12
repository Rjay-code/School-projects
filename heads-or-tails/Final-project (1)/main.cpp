#include<iostream>
#include<fstream>
using namespace std;


class BST
{
struct node
{
  int data;
  node* left;
  node* right;
  int height;
};
node* root;

void makeEmpty(node* tree)
{
  if(tree == NULL)
  return;
  makeEmpty(tree->left);
  makeEmpty(tree->right);
  count = 0;
  delete tree;
}

node* insert(int x, node* tree)
{
   if(tree == NULL)
    {
      tree = new node;
      tree->data = x;
      tree->height = 0;
      tree->left = tree->right = NULL;
     
    }
    else if(x < tree->data)
    {
      count+=1;
      tree->left = insert(x, tree->left);
      if(height(tree->left) - height(tree->right) == 2)
       {
         if(x < tree->left->data)
         {
          tree = singleRightRotate(tree);
          count+=1;
         }
          else
          {
          count+=2;
           tree = doubleRightRotate(tree);
          }
        }
    }
    else if(x > tree->data)
    {
      count+=1;
      tree->right = insert(x, tree->right);
      if(height(tree->right) - height(tree->left) == 2)
        {
          if(x > tree->right->data)
          {
            count+=1;
            tree = singleLeftRotate(tree);
          }
            else
            {
              count+=2;
             tree = doubleLeftRotate(tree);
            }
        }
    }
        tree->height = max(height(tree->left), height(tree->right))+1;
    return tree;
}

node* singleLeftRotate(node* &tree)
{
 node* u = tree->right;
 tree->right = u->left;
 u->left = tree;
 tree->height = max(height(tree->left), height(tree->right))+1;
 u->height = max(height(tree->right), tree->height)+1 ;
 return u;
}

node* singleRightRotate(node* &tree)
{
  node* u = tree->left;
  tree->left = u->right;
  u->right = tree;
  tree->height = max(height(tree->left), height(tree->right))+1;
  u->height = max(height(u->left), tree->height)+1;
  return u;
}

node* doubleRightRotate(node* &tree)
{
  tree->left = singleLeftRotate(tree->left);
  return singleRightRotate(tree);
}

node* doubleLeftRotate(node* &tree)
{
  tree->right = singleRightRotate(tree->right);
  return singleLeftRotate(tree);
}

node* findMin(node* tree)
{
  if(tree == NULL)
    return NULL;
  else if(tree->left == NULL)
    return tree;
  else
    return findMin(tree->left);
}

node* findMax(node* tree)
{
  if(tree == NULL)
    return NULL;
  else if(tree->right == NULL)
    return tree;
  else
    return findMax(tree->right);
}

node* remove(int x, node* tree)
{
 node* temp;
  if(tree == NULL)
    return NULL;
  else if(x < tree->data)
    tree->left = remove(x, tree->left);
  else if(x > tree->data)
   tree->right = remove(x, tree->right);
   //Element With 2 kids
  else if(tree->left && tree->right)
  {
    temp = findMin(tree->right);
    tree->data = temp->data;
    tree->right = remove(tree->data, tree->right);
  }
  //one or zero child
  else
  {
    temp = tree;
    if(tree->left == NULL)
      tree = tree->right;
    else if(tree->right == NULL)
      tree = tree->left;
    delete temp;
  }
  if(tree == NULL)
    return tree;
    tree->height = max(height(tree->left), height(tree->right))+1;
  // Left case
  if(height(tree->left) - height(tree->right) == 2)
  {
    // right right case
    if(height(tree->left->left) - height(tree->left->right) == 1)
      return singleLeftRotate(tree);
    // right left case
    else
      return doubleLeftRotate(tree);
  }
  //left case
  else if(height(tree->right) - height(tree->left) == 2)
  {
    // left left case
    if(height(tree->right->right) - height(tree->right->left) == 1)
      return singleRightRotate(tree);
    // left right case
    else
      return doubleRightRotate(tree);
  }
  return tree;
}

int height(node* tree)
{
  return (tree == NULL ? -1 : tree->height);
}

int getBalance(node* tree)
{
  if(tree == NULL)
    return 0;
  else
    return height(tree->left) - height(tree->right);
}

void inorder(node* tree)
{
  if(tree == NULL)
    return;
  inorder(tree->left);
  cout << tree->data << " ";
  inorder(tree->right);
}

public:
BST()
{
  root = NULL;
}

void insert(int x)
{
  root = insert(x, root);
}

void remove(int x)
{
  root = remove(x, root);
}

void display()
{
  inorder(root);
  cout << endl;
}
int count = 0;
};

int main()
{
BST tree;
int count = 0;
long n[10] = {100,200,300,400,500,600,700,800,900,999};

ofstream File;
File.open("bigo.cvs");
for(int t= 0; t<10;t++)
{
count = 0;


for(int i = 0; i < 100;i++)
  {
    int w = 1000000-n[i];
    srand(time(NULL));
    int x = rand() % w + 1;
    tree.insert(x);
  }

  //File << " n  putitem"<< endl;
  File << tree.count << endl;

  

}//tree.display();
File.close();
}