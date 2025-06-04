// C++ code for finding rank of string
#include <bits/stdc++.h>
using namespace std;

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
    cout << findRank(str);
    return 0;
}