// C++ code for finding rank of string
#include <bits/stdc++.h>
using namespace std;

// Factorial
int fact(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
        res *= i;
    return res;
}

// A utility function to count
// smaller characters on right of arr[low]
int findSmallerInRight(string str, int low)
{
    int countRight = 0;
    for (int i = low + 1; i < str.size(); ++i)
        if (str[i] < str[low])
            ++countRight;
    return countRight;
}

// A function to find rank of a string in all permutations
// of characters
int findRank4(string &str)
{
    int n = str.size();
    int mul = fact(n);
    int rank = 1;

    // Using a vector of size 26 for lowercase letters
    vector<int> count(26, 0);

    // Populate the count array for each character in string
    for (int i = 0; i < n; ++i)
        ++count[str[i] - 'a'];

    // Convert count to cumulative sum
    for (int i = 1; i < 26; ++i)
        count[i] += count[i - 1];

    for (int i = 0; i < n; ++i)
    {
        mul /= (n - i);

        // Get index of current character in count array
        int charIndex = str[i] - 'a';

        // Add count of characters smaller than current character
        if (charIndex > 0)
            rank += count[charIndex - 1] * mul;

        // Update count array
        for (int j = charIndex; j < 26; ++j)
            --count[j];
    }

    return rank;
}

// A function to find rank of a string
// in all permutations of characters
int findRank3(string str)
{
    int n = str.size();
    int mul = fact(n);
    int rank = 1;
    int countRight;

    for (int i = 0; i < n; ++i)
    {
        mul /= (n - i);

        // Count number of chars smaller than str[i]
        // from str[i+1] to str[len-1]
        countRight = findSmallerInRight(str, i);

        rank += countRight * mul;
    }

    return rank;
}

// A function to find rank of a string
// in all permutations of characters
int findRank2(string str)
{
    int n = str.size();

    // 1 to be added to smaller count
    int rank = 1;
    int countRight;

    for (int i = 0; i < n; ++i)
    {

        // Count number of chars smaller than str[i]
        // from str[i+1] to str[len-1]
        countRight = findSmallerInRight(str, i);

        rank += countRight * fact(n - i - 1);
    }

    return rank;
}

// A function to find rank of a string in all permutations
// of characters
int findRank(string &str)
{

    // Create a copy of the original
    // string to keep it unchanged
    string original = str;

    // Sort the string to get the first
    // permutation in lexicographic order
    sort(str.begin(), str.end());

    int rank = 1;

    // Keep generating next permutation
    // until we find the original string
    while (str != original)
    {
        next_permutation(str.begin(), str.end());
        rank++;
    }

    return rank;
}

int main()
{
    string str = "string";
    cout << findRank(str) << endl;
    cout << findRank2(str) << endl;
    cout << findRank3(str) << endl;
    cout << findRank4(str) << endl;

    return 0;
}