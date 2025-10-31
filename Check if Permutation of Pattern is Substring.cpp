/*
Topic:
1. Sliding Window Technique
*/

// C++ Program to check if any permutation of pattern
// is substring by checking all possible substrings

#include <iostream>
#include <vector>
using namespace std;

const int MAX_CHAR = 26;

// check if all characters have 0 frequency
bool check(vector<int> &freq)
{
    for (int i = 0; i < MAX_CHAR; i++)
    {
        if (freq[i] != 0)
            return false;
    }
    return true;
}

bool search(string &txt, string &pat)
{
    int n = txt.length();
    int m = pat.length();

    vector<int> freq(MAX_CHAR, 0);

    // construct the first window
    for (int i = 0; i < m; i++)
    {
        freq[txt[i] - 'a'] += 1;
        freq[pat[i] - 'a'] -= 1;
    }

    // Check for first window
    if (check(freq))
        return true;

    for (int i = m; i < n; i++)
    {
        // Add the ith character into the window
        freq[txt[i] - 'a'] += 1;

        // Remove the (i - m)th character from the window
        freq[txt[i - m] - 'a'] -= 1;

        // Check for the current window
        if (check(freq))
            return true;
    }

    return false;
}

bool arePermutations_navie(string &txt, int startIdx, string &pat)
{
    vector<int> freq(MAX_CHAR, 0);
    for (int i = 0; i < pat.length(); i++)
    {

        // Decrement the count of character in txt
        freq[txt[startIdx + i] - 'a'] -= 1;

        // Increment the count of character in pat
        freq[pat[i] - 'a'] += 1;
    }

    for (int i = 0; i < MAX_CHAR; i++)
    {
        if (freq[i] != 0)
            return false;
    }
    return true;
}

bool search_naive(string &txt, string &pat)
{
    int n = txt.length();
    int m = pat.length();

    for (int i = 0; i < n - m + 1; i++)
    {

        // Check if substring in txt starting from i
        // is a permutation of pat
        if (arePermutations_navie(txt, i, pat))
            return true;
    }

    return false;
}

int main()
{
    string txt = "geeks";
    string pat = "eke";
    if (search_naive(txt, pat))
        cout << "true";
    else
        cout << "false";
    return 0;
}