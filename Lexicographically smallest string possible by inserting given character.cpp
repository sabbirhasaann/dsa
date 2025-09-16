// C++ Program to implement the
// above approach
#include <bits/stdc++.h>
using namespace std;

// Function to obtain lexicographically
// smallest string possible by inserting
// character c in the string s
string SmallestString(string s, char c)
{

    // Traverse the string
    for (int i = 0; i < s.size(); i++)
    {

        // If the current character is greater
        // than the given character
        if (s[i] > c)
        {

            // Insert the character before
            // the greater character
            s.insert(i, 1, c);

            // Return the string
            return s;
        }
    }

    // Append the character at the end
    s += c;

    // Return the string
    return s;
}

// Driver Code
int main()
{
    string S = "acd";
    char C = 'b';

    cout << SmallestString(S, C) << endl;

    return 0;
}