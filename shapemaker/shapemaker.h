#include <iostream>
using namespace std;


#ifndef shapemakerH
#define shapemakerH

class shapemaker 
{
  public:
  //default constructer
  shapemaker();
  shapemaker(int,int,char);
  void draw_horzontal_line();
  void draw_vertical_line();
  void draw_filled_canvas();
  void draw_open_canvas();
  void draw_a_smiling_face();

  
  private:
  int NewWidth;
  int NewLength;
  int NewRadius;
  char Symbol;

};
#endif