// program to find the difference between the sum of the squares
// of the first one hundred natural numbers and the square of the sum. 
#include <iostream>
using namespace std;

int main()
{
  unsigned sum1 = 0, sum2 = 0, i;
  for (i = 1; i <= 100; i++) {
    sum1 += i*i;
    sum2 += i;
  }
  cout <<"the diffrence is : "<<(sum2*sum2)-sum1<<endl;
  return 0;
}
