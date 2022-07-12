#include "shapemaker.h"
//default constructer
shapemaker::shapemaker()
{
NewWidth=0;
NewLength=0;
}
//Overload function
shapemaker::shapemaker(int width, int length, char sym)
{
  NewWidth=width;
  NewLength=length;
  Symbol=sym;
}
//draw a horzontal line
void shapemaker::draw_horzontal_line()
{
  int width = NewWidth;
  int length = NewLength;
  char sym = Symbol;
  int total = length-2;
  int middle = length/2;
  for(int i=1; i<=width;i++)
  {
    cout<<sym;
  }
  cout << endl;
  while(total !=0)
  {
    for(int i=1; i<=width;i++)
    {
      if(i==1 || i==width)
      {
        cout << sym; 
      }
      else if(total == middle)
      {
        cout << "-";
      }
      else if(i!=1 && i!=width)
      {
        cout << " ";
      }
      
    }
    cout<<endl;
    total--;
  }
  for(int i=1; i<=width;i++)
  {
    cout<<sym;
  }
}
//draw a vertical line
void shapemaker::draw_vertical_line()
{
int width = NewWidth;
  int length = NewLength;
  char sym = Symbol;
  int total = length-2;
  int middle = width/2;
  if (width%2 != 0)
  {
    middle+=1;
  }
  for(int i=1; i<=width;i++)
  {
    cout<<sym;
  }
  cout << endl;
  while(total !=0)
  {
    for(int i=1; i<=width;i++)
    {
      if(i==1 || i==width)
      {
        cout << sym; 
      }
      else if(i == middle)
      {
        cout << "|";
      }
      else if(i!=1 && i!=width)
      {
        cout << " ";
      }
      
    }
    cout<<endl;
    total--;
  }
  for(int i=1; i<=width;i++)
  {
    cout<<sym;
  }
}
//draw a filled square
void shapemaker::draw_filled_canvas()
{
  int width=NewWidth;
  int length = NewLength;
  char sym = Symbol;
  int total=length-2;
  for(int i=1; i<=width;i++)
  {
    cout<<sym;
  }
  cout << endl;
  while(total !=0)
  {
    for(int i=1; i<=width;i++)
    {
      cout << sym; 
    }
    cout<<endl;
    total--;
  }
  for(int i=1; i<=width;i++)
  {
    cout<<sym;
  }
}
// open canvas
void shapemaker::draw_open_canvas()
{
  int width = NewWidth;
  int length = NewLength;
  char sym = Symbol;
  int total = length-2;
  for(int i=1; i<=width;i++)
  {
    cout<<sym;
  }
  cout << endl;
  while(total !=0)
  {
    for(int i=1; i<=width;i++)
    {
      if(i == 1 || i == width)
      {
        cout << sym; 
      }
      else
      {
        cout << " ";
      }
    }
    cout << endl;
    total--;
  }
  for(int i=1; i<=width;i++)
  {
    cout<<sym;
  }
}
/*// drawing a smile
 void shapemaker::draw_a_smiling_face()
 {
  int width = NewWidth;
  int length = NewLength;
  char sym = Symbol;
  int total = length-2;

  int eye1=
  int eye2=
  for(int i=1; i<=width;i++)
  {
    cout<<sym;
  }
  cout << endl;
  while(total !=0)
  {
    for(int i=1; i<=width;i++)
    {
      if(i == 1 || i == width)
      {
        cout << sym; 
      }
      else if(i ==  || i == width-1)
      {
        if(total == length-2)
        {
        cout << ".";
        }
        else
        {
          cout << " ";
        }
      }
      else
      {
        cout << " ";
      }
    }
    cout << endl;
    total--;
  }
  for(int i=1; i<=width;i++)
  {
    cout<<sym;
  }
 }*/
  