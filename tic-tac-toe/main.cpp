#include <iostream>
using namespace std;
//##################################
//get player data
//#################################
string get_player();
//##################################
//run game
//#################################
void run_game(string);
//##################################
//print
//#################################
void print(string);
//##################################
//print out the game table
//#################################
void print_table();
//##################################
//check if game is over
//#################################
bool check();
//##################################
//finds player one
//#################################
string find_player1(string, string);
//##################################
//determins looser
//#################################
bool find_loser( char);

//##################################
//array of numbers used forgame board
//#################################
char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
bool continue_playing(bool);
//##################################
//struct for person data
//#################################
struct player{
  string name;
  char gamepice;

};

int main(){
  
    player one;
    player two;
    string person1=get_player();
    cout<<"person 1 is "<<person1<< endl;
    string person2=get_player();
    cout<<"person 2 is "<<person2<< endl;
 if(find_player1(person1,person2)==person1){
    one.name=person1;
    two.name+=person2;
   
 }else{
    one.name+=person2;
    two.name+=person1;
   }
char gamepiece;
  cout<<"Player one is "<<one.name<<  " do you want to be x or o?";
 cin>>gamepiece;
 if(gamepiece=='x'){
   one.gamepice='X';
   two.gamepice='O';
 }else{
two.gamepice='X';
one.gamepice='O';
 }
 print_table();
 for(int i=0;i<10;i++){
  if(i%2==0){
   int x;
  cout<<"pick a number "<<one.name;
  cin>>x;
  square[x]=one.gamepice;
  print_table();
  if(check()){
    break;
  }
 }else{
   int x;
  cout<<"pick a number "<<two.name;
  cin>>x;
  square[x]=two.gamepice;
  print_table();
  if(check()){
    break;
  }
 }
 }
 string loser;
 if(find_loser(one.gamepice )){
   loser=two.name;
   cout<< one.name<<" wins!!";
 }else{
   loser=one.name;
   cout<< two.name<<" wins!!";
 }
 
 while(continue_playing(check())){
   run_game(loser);
 
 }
}
//##################################
//finds the loser
//#################################
bool find_loser( char x){
  if ((square[1] == x && square[2] == x && square[3]==x)||(square[4]==x && square[5]==x && square[6==x])||(square[7] == x && square[8] == x && square[9]== x)||(square[1] == x && square[4] == x && square[7]== x)||(square[2] == x && square[5]==x && square[8]==x)||(square[3] == x && square[6]==x && square[9]==x)||(square[1] ==x && square[5] ==x && square[9]==x)||(square[3] ==x && square[5] ==x && square[7]==x)){
return true;
}
return false;
}
//##################################
//decides if the game will continue or not
//#################################
bool continue_playing(bool x){
  if (x){
    string answer;
    cout <<endl<<"The game is over would you like to play again?";
    cin>>answer;
    if(answer=="yes"){
    return true;
    }else{
      return false;
    }
  }
return true;
}
//##################################
//prints data
//#################################
void print(string x){
  cout<<x;
}
//##################################
//runs the game
//#################################
void run_game(string x ){
   if(x==x){
    player one;
    player two;
    string person1=x;
    cout<<"person 1 is "<<person1<< endl;
    string person2=get_player();
    cout<<"person 2 is "<<person2<< endl;
 if(find_player1(person1,person2)==person1){
    one.name=person1;
    two.name+=person2;
   
 }else{
    one.name+=person2;
    two.name+=person1;
   }
   
char gamepiece;
  cout<<"Player one is "<<one.name<<  " do you want to be x or o?";
 cin>>gamepiece;
 if(gamepiece=='x'){
   one.gamepice='X';
   two.gamepice='O';
 }else{
two.gamepice='X';
one.gamepice='O';
 }
 
 print_table();
 for(int i=0;i<10;i++){
  if(i%2==0){
   int x;
  cout<<"pick a number "<<one.name;
  cin>>x;
  square[x]=one.gamepice;
  print_table();
  if(check()){
    break;
  }
 }else{
   int x;
  cout<<"pick a number "<<two.name;
  cin>>x;
  square[x]=two.gamepice;
  print_table();
  if(check()){
    break;
  }
 }
 }
}
}
//##################################
//get player info
//#################################
string get_player(){
  string person1;
  cout<< "Enter first name and enter last name.";
  getline(cin,person1);
  return person1;
} 
//##################################
//finds player one
//#################################
string find_player1(string one, string two){
  char char1;
  char char2;
  int x;
  int y;
for(int i=0;i>=0;i++){
  if(one[i]==' '){
    char1=one[i+1];
    break;
   }
}
for(int i=0;i>=0;i++){
  if(two[i]==' '){
    char2=two[i+1];
    break;
   }
}
switch (char1){
  case 'A':
  case 'a':
  x=26;
  break;
  case 'b':
  case 'B':
x=25;
break;
  case 'C':
  case 'c':
x=24;
break;
  case 'd':
  case 'D':
x=23;break;
  case 'e':
  case 'E':
x=22;break;
  case 'f':
  case 'F':
x=21;break;
  case 'g':
  case 'G':
 x=20; break;
  case 'H':
  case 'h':
 x=19; break;
  case 'i':
  case 'I':
x=18;break;
  case 'J':
  case 'j':
x=17;break;
  case 'k':
  case 'K':
 x=16; break;
  case 'l':
  case 'L':
  x=15;break;
  case 'm':
  case 'M':
  x=14;break;
  case 'n':
  case 'N':
  x=13;break;
  case 'O':
  case 'o':
  x=12;break;
  case 'p':
  case 'P':
  x=11;break;
  case 'q':
  case 'Q':
x=10;break;
  case 'r':
  case 'R':
  x=9;break;
  case 's':
  case 'S':
  x=8;break;
  case 't':
  case 'T':
  x=7;break;
  case 'u':
  case 'U':
  x=6;break;
  case 'v':
  case 'V':
  x=5;break;
  case 'W':
  case 'w':
  x=4;break;
  case 'x':
  case 'X':
  x=3;break;
  case 'y':
  case 'Y':
  x=2;break;
  case 'z':
  case 'Z':
  x=1;break;
}
switch (char2){
  case 'A':
  case 'a':
  y=26;break;
  case 'b':
  case 'B':
y=25;break;
  case 'C':
  case 'c':
y=24;break;
  case 'd':
  case 'D':
y=23;break;
  case 'e':
  case 'E':
y=22;break;
  case 'f':
  case 'F':
y=21;break;
  case 'g':
  case 'G':
  y=20;break;
  case 'H':
  case 'h':
  y=19;break;
  case 'i':
  case 'I':
y=18;break;
  case 'J':
  case 'j':
y=17;break;
  case 'k':
  case 'K':
  y=16;break;
  case 'l':
  case 'L':
  y=15;break;
  case 'm':
  case 'M':
  y=14;break;
  case 'n':
  case 'N':
  y=13;break;
  case 'O':
  case 'o':
  y=12;break;
  case 'p':
  case 'P':
  y=11;break;
  case 'q':
  case 'Q':
y=10;break;
  case 'r':
  case 'R':
  y=9;break;
  case 's':
  case 'S':
  y=8;break;
  case 't':
  case 'T':
  y=7;break;
  case 'u':
  case 'U':
  y=6;break;
  case 'v':
  case 'V':
  y=5;break;
  case 'W':
  case 'w':
  y=4;break;
  case 'x':
  case 'X':
  y=3;break;
  case 'y':
  case 'Y':
  y=2;break;
  case 'z':
  case 'Z':
  y=1;break;
}
if(x>y){
  return one;
}else if(y>x){
  return two;
}else{
  return two;
}
}
//##################################
//prints the table
//#################################
void print_table(){
  cout <<endl;
  cout<<"+---+---+---+"<<endl;
  cout<<"| "<<square[1]<< " | " << square[4]<<" | "<<square[7]<<" |"<<endl;
  cout<<"+---+---+---+"<<endl;
  cout<<"| "<<square[2]<<" | "<<square[5]<<" | "<<square[8]<<" |"<<endl;
  cout<<"+---+---+---+"<<endl;
  cout<<"| "<<square[3]<<" | "<<square[6]<<" | "<<square[9]<<" |"<<endl;
  cout<<"+---+---+---+"<<endl;
} 
//##################################
//checks for winner
//#################################
bool check(){
if ((square[1] == square[2] && square[2] == square[3])||(square[4] == square[5] && square[5] == square[6])||(square[7] == square[8] && square[8] == square[9])||(square[1] == square[4] && square[4] == square[7])||(square[2] == square[5] && square[5] == square[8])||(square[3] == square[6] && square[6] == square[9])||(square[1] == square[5] && square[5] == square[9])||(square[3] == square[5] && square[5] == square[7])){
return true;
}
return false;
}