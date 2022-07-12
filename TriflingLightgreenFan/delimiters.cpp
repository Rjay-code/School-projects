#include <iostream>
using namespace std;
#include "StackType.h"

int main() 
{
  char bracket_type;
  string message;
  string correct = "properly delimited";
  string notcorrect = "improperly delimited";
  for(int i= 0;i < 4; i++)
  {
  cout << "enter a string" << endl;
  getline(cin,message);
  if (message[0] == '[' || message[0] == '{' || message[0] == '(')
  {
    bracket_type = message[0];
    if ((message[message.size()-1] == ']' && bracket_type == '[') || (message[message.size()-1] == '}' && bracket_type == '{') || (message[message.size()-1] == '(' && bracket_type == ')'))
  {
    //having problems getting () to be accepted as a properly delimited string
    cout << correct << endl;

  }
  else 
  {
    cout << notcorrect << endl;
  }
  }
  else 
  {
    cout << notcorrect << endl;
  }
  
  
  }
} 