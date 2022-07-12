#include <iostream>
using namespace std;
struct Car{
  string make;
  string model;
  int year;
};
Car* getdata(int);

void printdata(struct Car*,int);

int main() {
  int number;
  cout << "How many cars do you want?";
  cin>> number;

Car* x=getdata(number);
printdata(x,number);

delete []x;
return 0;

}
Car* getdata(int size){
Car* x= new Car[size];
  cout<<"Enter make model and year.";
  for(int i=0;i<size;i++){
    cin>>(x+i)->make>>(x+i)->model>>(x+i)->year;
  }
return x;
}
void printdata(struct Car* x,int size){
  for(int y=0;y<size;y++){
    cout<<(x+y)->make<<" "<<(x+y)->model<<" "<<(x+y)->year<< endl;
  }
}