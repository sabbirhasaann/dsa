#include <bits/stdc++.h>
using namespace std;

int sum_natural_no(int n)
{
    if (n == 1)
        return 1;
    return n + sum_natural_no(n - 1);
}

int fact(int n){
    if(n==0)
        return 1;
    return n * fact(n-1);
}

void printFun(int test)
{
    if (test < 1)
        return;
    else {
        cout << test << " ";
        printFun(test - 1); // statement 2
        cout << test << " ";
        return;
    }
}

int fib(int n)
{
    // Stop condition
    if (n == 0)
        return 0;

    // Stop condition
    if (n == 1 || n == 2)
        return 1;

    // Recursion function
    else
        return (fib(n - 1) + fib(n - 2));
}

int main()
{
    cout << "Sum of natural number upto n : " << sum_natural_no(10) << endl;
    cout << "Factorial upto n : " << fact(5) << endl;
    cout <<"printFun(test) : ";
    printFun(3);
    cout << endl;
    cout << "Fibonacci series of nth: " << fib(7) << endl;

}