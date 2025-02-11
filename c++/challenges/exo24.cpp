//print all primes that there degits are in ascending order
#include <iostream>
#include <cmath>
#define MAXSIZE 1000
using namespace std;

int temp[MAXSIZE];
int prime_nums[MAXSIZE];
int start = 0;
int End = 0;
int n = 0;

bool isPrime(int n1)
{
    int i = 2;
    while (i <= n1 / 2)
    {
        if (n1 % i == 0)
            return false;
        else
            i++;
    }
    return true;
}

int main(int argc, char* argv[])
{
    for (int k = 1; k <= 9; k++)
    {
        temp[End++] = k;
    }

    while (start < End)
    {
        int value = temp[start++];
        if (isPrime(value))
        {
            prime_nums[n++] = value;
        }
        for (int k = value % 10 + 1; k <= 9; k++)
        {
            temp[End++] = value * 10 + k;
        }
    }
    for (int k = 0; k < n; k++)
    {
        cout << prime_nums[k] << " ";
    }

    return 0;
}


