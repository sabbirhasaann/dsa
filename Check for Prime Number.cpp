#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1)
        return false;

    // Check divisibility from 2 to n-1
    for (int i = 2; i < n; i++)
        {
            if (n % i == 0) return false;
        }

    return true;
}


// Function to check whether a number is prime or not
bool isPrime1(int n) {

    // Numbers less than or equal to 1 are not prime
    if (n <= 1)
        return false;

    // Check divisibility from 2 to the square root of n
    for (int i = 2; i* i <=n; i++)
        if (n % i == 0)  
            return false;

    // If no divisors were found, n is prime
    return true;
}

bool isPrime2(int n) {
  
    // Check if n is 1 or 0
    if (n <= 1)
        return false;

    // Check if n is 2 or 3
    if (n == 2 || n == 3)
        return true;

    // Check whether n is divisible by 2 or 3
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    
    // Check from 5 to square root of n
    // Iterate i by (i+6)
    for (int i = 5; i *i<=n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

int main() {
    int n = 7;
  	if(isPrime(n)) cout << "true";
  	else cout<<"false";
    return 0;
}