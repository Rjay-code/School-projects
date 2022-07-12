#include "account.h"
peachstate::peachstate()
{
  age=0;
}
peachstate::peachstate(string first,string second,int third)
{
  first_name = first;
  last_name = second;
  age = third;
}
void peachstate :: print()
{
  cout << first_name;
}
user::user()
{
}
void user::create()
{
  cout << "Lets create you an account";
  cout << endl << first_name << " " << last_name << " please create a username";
  cin >> username;
  cout << endl << first_name << " " <<last_name << " please create a password";
  cin >> password;
  cout << "Please pick a challenge by picking A,B,C,D" << endl;
  cout << "A.I-75 Challenge length of 350" << endl;
  cout << "B.I-85 Challenge length of 180" << endl;
  cout << "C.I-285 Challenge length of 64" << endl;
  cout << "D.Peach State Challenge length of 594" << endl;
  cin >> race_type;
}
void user::login()
{
  bool access = true ;
  string x;
  string y;
  while(access){
  cout<< "Please Enter you username and password";
  cin>>x;
  cin>>y;
   if(x== username && y== password)
   {
     cout<< "Access granted";
     access = false;
   }
   else
   {
     cout << "Access denied";
   }
  }


}

race::race()
{
 total_miles = 0;
 current_miles_ran = 0;
}

race::race(int numOfMiles)
{
  current_miles_ran = numOfMiles;
  if(race_type == 'A')
  {
    total_miles = 350;
    race_name = "I-75 Challenge";
  }
  else if(race_type == 'B')
  {
    total_miles = 180;
    race_name = "I-85 Challenge";
  }
  else if(race_type == 'C')
  {
    total_miles = 64;
    race_name = "I-285 Challenge";
  }
  else
  {
    total_miles = 594;
    race_name = "Peach State Challenge";
  }
}
void race::view_progress()
{
  string user = username;
  string nam = first_name;
  string name = last_name;
  float precent_done = current_miles_ran/total_miles;
  int miles_left = total_miles-current_miles_ran;
  cout<< endl << endl << endl;
  cout<< "Username: "  << user << endl;
  cout<< "Name: " << nam << " " << name << endl;
  cout << "Age: " << age << endl;
  cout << race_name << " length of " << total_miles << " miles" << endl;
  cout << "current progress " << current_miles_ran << " out of " << total_miles << " miles" << endl;
  cout << " you have completed " << precent_done <<"% of your current challenge any you have " << miles_left << " miles left";
}
