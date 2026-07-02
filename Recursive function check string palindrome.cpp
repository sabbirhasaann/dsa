// 2026/07/02 20:24:42
// https://www.geeksforgeeks.org/dsa/recursive-function-check-string-palindrome/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

bool isPalindrome(string &s, int i, int j)
{
    if (i >= j)
        return true;

    if (s[i] != s[j])
        return false;

    return isPalindrome(s, ++i, --j);
}

int main()
{
    ios_base::sync_with_stdio(false);

    string s = "abbab";
    (isPalindrome(s, 0, s.length() - 1)) ? cout << "YEs\n" : cout << "No\n";

    return 0;
}