#include <iostream>
#include "shapemaker.h"
using namespace std;


//checks lenght of canvas
void checklengthorwidth(int, string);

//length of canvas
int length;

//width of canvas
int width;

//main function
int main() 
{
 char symbol;
 int radi;
 cout << "What is the length of the canvas?" << endl;
 cin >> length;
 checklengthorwidth(length,"length");
 cout << "What is the width of the canvas?" << endl;
 cin >> width;
 checklengthorwidth(width,"width");
 cout << "What is the symbol for the canvas?" << endl;
 cin >> symbol;
 cout << endl;
 shapemaker shape1(width,length,symbol);
 shape1.draw_horzontal_line();
 shape1.draw_vertical_line();
 shape1.draw_filled_canvas();
 shape1.draw_open_canvas();
 shape1.draw_a_smiling_face();
 
 return 0;
}

void checklengthorwidth(int x,string y)
{
  if(x<5)
  {
    cout << "Please enter a number larger than 5."<< endl;
  }
  while(x>100)
  {
    cout<< y << "is to large please enter a smaller value." << endl;
    if(y=="length")
    {
     cout << "What is the length of the canvas?" <<endl;
     cin>>length;
    }else
    {
     cout << "What is the width of the canvas?" <<endl;
     cin>>width;
    }
  } 
}