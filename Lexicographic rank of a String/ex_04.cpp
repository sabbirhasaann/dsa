// C++ code for finding rank of string
#include <bits/stdc++.h>
using namespace std;

// Factorial
int fact(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++) { res *= i; }
    return res;
}

// A function to find rank of a string in all permutations
// of characters
int findRank(string &str)
{
    int n = str.size();
    int mul = fact(n);
    int rank = 1;

    // Using a vector of size 26 for lowercase letters
    vector<int> count(26, 0);

    // Populate the count array for each character in string
    for (int i = 0; i < n; ++i) {
        ++count[str[i] - 'a'];
    }

    // Convert count to cumulative sum
    for (int i = 1; i < 26; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = 0; i < n; ++i) {
        mul /= (n - i);

        // Get index of current character in count array
        int charIndex = str[i] - 'a';

        // Add count of characters smaller than current character
        if (charIndex > 0) {
            rank += count[charIndex - 1] * mul;
        }

        // Update count array
        for (int j = charIndex; j < 26; ++j) {
            --count[j];
        }
    }

    return rank;
}

int main() {
    string str = "string";
    cout << findRank(str);
    return 0;
}