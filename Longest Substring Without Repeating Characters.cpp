// 2025/11/06 11:56:06

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void soln()
{
    string s;
    cin >> s; // geeksforgeeks
    unordered_map<char, int> um;
    vector<pair<char, int>> res;
    // um[s[0]]++;
    um[s[0]] = 1;
    // for (auto p : um)
    //     cout << p.first << " " << p.second << endl;
    int max_len = 1;
    int idx_start = 0, idx_end = 0;
    for (int i = 1; i < s.size(); i++)
    {
        if (um.find(s[i]) == um.end())
        {
            // um[s[i]]++;
            um[s[i]] = i;
        }
        else
        {

            if (um.size() > max_len)
            {
                auto p1 = *um.begin();
                max_len = um.size();
            }
            um.clear();
            um[s[i]]++;
        }
    }
    cout << max_len << endl;
    // for (int i = idx_start; i <= idx_end; i++)
    //     cout << s[i];
    // cout << endl;
}

int longestUniqueSubstr_expected2(string &s)
{
    int n = s.size();
    int res = 0;

    vector<int> lastIndex(26, -1);

    // Initialize start of current window
    int start = 0;

    // Move end of current window
    for (int end = 0; end < n; end++)
    {

        start = max(start, lastIndex[s[end] - 'a'] + 1);

        // Update result if we get a larger window
        res = max(res, end - start + 1);

        // Update last index of s[end]
        lastIndex[s[end] - 'a'] = end;
    }
    return res;
}

int longestUniqueSubstr_expected(string &s)
{
    if (s.length() == 0 || s.length() == 1)
        return s.length();

    int res = 0;
    vector<bool> vis(26, false);

    // left and right pointer of sliding window
    int left = 0, right = 0;
    while (right < s.length())
    {

        // If character is repeated, move left pointer marking
        // visited characters as false until the repeating
        // character is no longer part of the current window
        while (vis[s[right] - 'a'] == true)
        {

            vis[s[left] - 'a'] = false;
            left++;
        }

        vis[s[right] - 'a'] = true;

        // The length of the current window (right - left + 1)
        // is calculated and answer is updated accordingly.
        res = max(res, (right - left + 1));
        right++;
    }
    return res;
}

int longestUniqueSubstr_naive(string &s)
{
    int n = s.size();
    int res = 0;

    for (int i = 0; i < n; i++)
    {

        // Initializing all characters as not visited
        vector<bool> vis(26, false);

        for (int j = i; j < n; j++)
        {

            // If current character is visited
            // Break the loop
            if (vis[s[j] - 'a'] == true)
                break;

            // Else update the result if this window is larger,
            // and mark current character as visited.
            else
            {
                res = max(res, j - i + 1);
                vis[s[j] - 'a'] = true;
            }
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    soln();
    string s = "geeksforgeeks";
    cout << longestUniqueSubstr_naive(s) << endl;

    cout << longestUniqueSubstr_expected(s) << endl;

    cout << longestUniqueSubstr_expected2(s) << endl;

    return 0;
}