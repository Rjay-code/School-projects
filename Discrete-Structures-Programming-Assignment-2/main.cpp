#include <iostream>
# include <chrono>
using namespace std;

int recursion (int x) 
{
  
  int total = 0;
  if((x == 1)||(x == 2)) 
  {
    return 1;
  }
  else 
  {
    return(recursion(x-1)+recursion(x-2));
  }
}

int iteration(int num) 
{
  int x = 0; 
  int y = 1; 
  int z = 0;
   for (int i = 0; i < num; i++) 
   {
    z = x + y;
    x = y;
    y = z;
   }
  return x;
}
void time_recursion(int x)
{
  auto begin = std::chrono::high_resolution_clock::now();
  recursion(x);
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  printf(" %.12f seconds.\n", elapsed.count() * 1e-9);
  cout<< endl;
}

void time_iteration(int x)
{
  auto begin = std::chrono::high_resolution_clock::now();
  iteration(x);
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  printf(" %.12f seconds.\n", elapsed.count() * 1e-9);
  cout<< endl;
}

int main() 
{
for(int i = 1; i < 6; i++)
{
  cout << "the recursion time is:";
  time_recursion(10*i);
  cout << "the irritave time is:";
  time_iteration(10*i);
}
  
    //the recursive function is slower than the irritive function instead of looping and adding the numbers in the loop together the recursive function is almost like a nested loop because it has to call the previous two cases to get the current case and if the number is big you will most likely call the same number multiple times.
  
  //the only way to call the recursive function only once and have value holders for the two previous cases so that once the two previous cases are found you add them to get the fib of the value you are looking for. for ex if you are looking for fib(5) you would only call fib once instead of twice like my function above and have ints that would update or store the value of fib(3) and fib (4) when you get them then add them to get your expected value

}
  