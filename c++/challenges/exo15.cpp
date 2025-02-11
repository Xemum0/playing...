 //find the sum of the even-valued terms from the terms in the Fibonacci 
 //sequence whose values do not exceed one million
#include <iostream>
using namespace std;

int main()
{
  unsigned int x1 = 1, x2 = 1, x3 = 2, num_sum = 0;
  while (x3 < 1000000) {
    x3 = x1 + x2;
    num_sum += x3 * !(x3%2);
    x1 = x2;
    x2 = x3;
  }
  cout << num_sum<<endl;
  return 0;
}
