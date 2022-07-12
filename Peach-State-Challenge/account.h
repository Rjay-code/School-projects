#include <iostream>
using namespace std;
#ifndef PEACHSTATE_H
#define PEACHSTATE_H
class peachstate
{
  public:
  peachstate();
  peachstate(string,string,int);
  void print();

  protected:
  string first_name;
  string last_name;
  int age;
  
};

#endif

#ifndef user_h
#define user_h
class user : public peachstate
{
  public:
  user();
  void create();
  void login();


  protected:
  string username;
  string password;
  char race_type;

};
#endif

#ifndef race_h
#define race_h
class race  : public user
{
 public:
 race();
 race(int);
 void view_progress();

 private:
 string race_name;
 int total_miles;
 int current_miles_ran;
};
#endif