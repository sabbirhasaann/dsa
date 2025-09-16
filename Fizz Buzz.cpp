// C++ program for Fizz Buzz Problem
// by checking every integer individually

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> fizzBuzz_expected(int n)
{

    vector<string> res;

    // Hash map to store all fizzbuzz mappings.
    unordered_map<int, string> mp =
        {{3, "Fizz"}, {5, "Buzz"}};

    // List of divisors which we will iterate over.
    vector<int> divisors = {3, 5};

    for (int i = 1; i <= n; i++)
    {
        string s = "";

        for (int d : divisors)
            // If the i is divisible by d, add the
            // corresponding string mapped with d
            if (i % d == 0)
                s.append(mp[d]);

        // Not divisible by 3 or 5, add the number
        if (s.empty())
            s.append(to_string(i));

        // Append the current answer str to the result vector
        res.push_back(s);
    }

    return res;
}

vector<string> fizzBuzz_better(int n)
{
    vector<string> res;
    for (int i = 1; i <= n; i++)
    {

        // Initialize an empty string for the current result
        string s = "";

        // Divides by 3, add Fizz
        if (i % 3 == 0)
            s.append("Fizz");

        // Divides by 5, add Buzz
        if (i % 5 == 0)
            s.append("Buzz");

        // Not divisible by 3 or 5, add the number
        if (s.empty())
            s.append(to_string(i));

        // Append the current res to the result vector
        res.push_back(s);
    }

    return res;
}

vector<string> fizzBuzz_naive(int n)
{
    vector<string> res;
    for (int i = 1; i <= n; ++i)
    {
        // Check if i is divisible by both 3 and 5
        if (i % 3 == 0 && i % 5 == 0)
            // Add "FizzBuzz" to the result vector
            res.push_back("FizzBuzz");

        // Check if i is divisible by 3
        else if (i % 3 == 0)
            // Add "Fizz" to the result vector
            res.push_back("Fizz");

        // Check if i is divisible by 5
        else if (i % 5 == 0)
            // Add "Buzz" to the result vector
            res.push_back("Buzz");

        else

            // Add the current number as a string to the
            // result vector
            res.push_back(to_string(i));
    }

    return res;
}

int main()
{
    int n = 20;
    vector<string> res = fizzBuzz_naive(n);
    for (const string &s : res)
        cout << s << " ";
    cout << endl;

    vector<string> res_better = fizzBuzz_better(n);
    for (const string &s : res_better)
        cout << s << " ";
    cout << endl;

    vector<string> res_expected = fizzBuzz_expected(n);
    for (const string &s : res_expected)
        cout << s << " ";
    cout << endl;
    return 0;
}