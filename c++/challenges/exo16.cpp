#include <iostream>
using namespace std;
int main()
{
  unsigned long long n = 438927456L;
  unsigned long long i;
  for (i = 2ULL; i < n; i++) {
      //ULL means unsigned long long
    while (n % i == 0) {
      n /= i;
    }
  }
    cout <<"the greatest prime number that devid it is : "<<n<<endl;
  return 0;
}
/*
 The reason why this algorithm works is because any composite number 'n' 
 can be written as a product of prime numbers. For example,
  12 = 2 * 2 * 3. Therefore, if we keep dividing 'n' by its prime factors,
   we will eventually end up with the greatest prime factor of 'n'.
 */