#include <iostream>
#include "account.h"
using namespace std;
int main() 
{
  string first_name;
  string last_name;
  int miles;
  int age;
  cout << "Hello User. Welcome to the Peach State Chllenge!" << endl;
  cout << "Please enter your first name";
  cin >> first_name;
  cout << "Please enter your last name";
  cin >> last_name;
  cout << "Please enter you age";
  cin >> age;
  peachstate useer1(first_name,last_name,age);
  user account;
  account.create();
  account.login();
  race number1q(miles);
  number1q.view_progress();
  
  

  

  }