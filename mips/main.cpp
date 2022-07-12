#include <iostream> 
#include <string>
#include <sstream>
#include <cmath>
#include <stdio.h>     
#include <math.h>  
using namespace std;
string getdata();
string HexToBin(string);
string determin_type(string);
int r_typept1(string);
int r_typept2(string);
int r_typept3(string);
int r_typept4(string);
int i_type(string);
int bintodec (string);
string converter(int);


int main(){
int register_y[32];
for(int i=0;i<32;i++){
  register_y[i]=0;
}
int amount;
cout<<"How many instructions?";
cin>>amount;
for(int i=0;i!=amount;i++){
string binary_num=HexToBin(getdata());
string type=determin_type(binary_num);
if ("000000"==type){
int x = r_typept1(binary_num);
int y = r_typept2(binary_num);
int z = r_typept3(binary_num);
int a = r_typept4(binary_num); 
cout<<"Instruction is R-Format "<<endl;
if(a==32){
  cout<<"Add $"<< z <<",$"<< x <<",$"<< y <<endl;
  cout<<"current register ammount= " << register_y[z];
  register_y[z]=register_y[x]+register_y[y];
}else if(a==34){
  cout<<"Sub $"<< z <<",$"<< x <<",$"<< y<<endl;
  cout<<"current register ammount= " << register_y[z];
 register_y[z]=register_y[x]-register_y[y];
}else if(a==37){
string newbinary_num;
cout<<"Or $"<< z <<",$"<< x <<",$"<< y;
cout<<"current register ammount= " << register_y[z];
for(int i=6;i<11;i++){

  if((binary_num[i]=='0')&&(binary_num[i*2]=='0')){
    newbinary_num+="0";
  }else{
    newbinary_num+="1";
  }
}
register_y[z]=bintodec(newbinary_num);
 
}else if(a==41){
  string newbinary_num;
  cout<<"And $"<< z <<",$"<< x <<",$"<< y;
  cout<<"current register ammount= " << register_y[z];
 for(int i=6;i<11;i++){
  if(binary_num[i]==binary_num[i*2]){
    newbinary_num+=binary_num[i];
  }else{
    newbinary_num+="0";
  }
}
register_y[z]=bintodec(newbinary_num);
}
}else{
int x = r_typept1(binary_num);
int y = r_typept2(binary_num);
int z= i_type(binary_num);
cout<< "Instruction is I-Format"<<endl;
if(type=="001000"){
  string hex;
cout<<"Addi $"<< y <<",$"<< x <<","<< z <<endl;
cout<<"current register ammount= " << register_y[y];
register_y[y]=z+register_y[x];
}else if(type=="100011"){
cout<<"lw $"<< y <<",$"<< x <<","<< z <<endl;
cout<<"current register ammount= " << register_y[y];
register_y[y]=register_y[x+z];
}else if(type=="101011"){
cout<<"sw $"<< y <<",$"<< x <<","<< z <<endl;
cout<<"current register ammount= " << register_y[y];
register_y[x+z]=register_y[y];
}else if(type=="000010"){
cout<<"beq $"<< y <<",$"<< x <<","<< z <<endl;
cout<<"current register ammount= " << register_y[y];
if(register_y[y]==register_y[x]){
  cout << "Branching with offset: " << z << endl;
  
}
}else if(type=="000011"){
cout<<"bne $"<< y <<",$"<< x <<","<< z <<endl;
cout<<"current register ammount= " << register_y[y];
if(register_y[y]!=register_y[x]){
  cout << "Branching with offset: " << z << endl;

}
}
}
cout<<endl<<"Registers:"<<endl;
for(int i=0;i<32;i++){
  cout<<"$"<<i<<"="<<register_y[i]<<endl;
}
}
}


int bintodec (string binNumber) {
  int decNumber = 0;
  int length = binNumber.length(); 
  for (int i = 1; i <= length; i++) {
    if (binNumber[length-i] == '1') {
      decNumber += pow(2, i-1); 
    }
  }
  return decNumber; 
}

int i_type(string x){
int num=16;
int result=0;
int power=15;
for(int i=0;i<16;i++){
  if (x[i+num]=='1'){
result+=pow(2,power-i);
  }else{
    result+=0;
  }
  
}
return result;
}
int r_typept1(string x){
int num=6;
int result=0;
int power=4;
for(int i=0;i<5;i++){
  if (x[i+num]=='1'){
result+=pow(2,power-i);
  }else{
    result+=0;
  }
  
}
return result;
}

int r_typept2(string x){
int num=11;
int result=0;
int power=4;
for(int i=0;i<5;i++){
  if (x[i+num]=='1'){
result+=pow(2,power-i);
  }else{
    result+=0;
  }
  
}
return result;
}

int r_typept3(string x){
  int num=16;
int result=0;
int power=4;
for(int i=0;i<5;i++){
  if (x[i+num]=='1'){
result+=pow(2,power-i);
  }else{
    result+=0;
  }
}
return result;
}
int r_typept4(string x){
int num=26;
int result=0;
int power=5;
for(int i=0;i<=5;i++){
  if (x[i+num]=='1'){
result+=pow(2,power-i);
  }else{
    result+=0;
  }
}
return result;
}


string determin_type(string x){
  string type;
  for(int i =0; i<6; i++){
   type+=x[i];
  }
  return type;
}

string getdata(){
  char hexnum[100];
  cout<< "Enter hexidecimal value";
  cin>>hexnum;
  cout<< "hex value is "<< hexnum <<endl;
  return hexnum;
}

string HexToBin(string x){
 string binarynum;

 long int i = 0;
 while(x[i]){
switch (x[i]) {
case '0':
 binarynum+="0000";
  break;
case '1':
 binarynum+="0001";
  break;
case '2':
 binarynum+="0010";
  break;
case '3':
  binarynum+="0011";
  break;
case '4':
  binarynum+="0100";
  break;
case '5':
  binarynum+="0101";
  break;
case '6':
  binarynum+="0110";
  break;
case '7':
  binarynum+="0111";
  break;
case '8':
  binarynum+="1000";
  break;
case '9':
  binarynum+="1001";
  break;
case 'A':
case 'a':
  binarynum+="1010";
  break;
case 'B':
case 'b':
  binarynum+="1011";
  break;
case 'C':
case 'c':
  binarynum+="1100";
  break;
case 'D':
case 'd':
  binarynum+="1101";
  break;
case 'E':
case 'e':
  binarynum+="1110";
  break;
case 'F':
case 'f':
  binarynum+="1111";
  break;
default:
  cout << "Invalid hexadecimal digit "
  << x[i];
        }
        i++;
    }
    cout<<"binary value is "<<binarynum<<endl;
    return binarynum;
}
