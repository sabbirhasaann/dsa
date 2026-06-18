// 2026/06/18 07:51:36
// https://www.geeksforgeeks.org/dsa/substring-of-length-k-having-maximum-frequency-in-the-given-string/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

string maximumOccurringStringEfficient(string s, int k)
{
    map<deque<char>, int> mp;
    deque<char> d;
    int n = s.length();

    for (int i = 0; i < k; ++i)
        d.push_back(s[i]);

    ++mp[d];
    d.pop_front();

    for (int i = k; i < n; ++i)
    {
        d.push_back(s[i]);
        ++mp[d];
        d.pop_front();
    }

    deque<char> ans;
    int maxi = INT_MIN;

    for (auto it : mp)
    {
        deque<char> chars = it.first;
        int freq = it.second;
        if (maxi < freq)
        {
            maxi = freq;
            ans = chars;
        }
    }
    string str;
    for (char c : ans)
        str += c;

    return str;
}
string maximumOccurringStringTrulyEfficient(std::string s, int k)
{
    if (k <= 0 || s.length() < k)
        return "";

    // Maps the substring view to its frequency
    std::unordered_map<std::string_view, int> freq_map;
    std::string_view max_str = "";
    int max_freq = 0;

    // Sliding window using string_view (zero memory allocation)
    for (size_t i = 0; i <= s.length() - k; ++i)
    {
        std::string_view window(&s[i], k);
        freq_map[window]++;

        if (freq_map[window] > max_freq)
        {
            max_freq = freq_map[window];
            max_str = window;
        }
    }

    return std::string(max_str);
}
int main()
{
    ios_base::sync_with_stdio(false);

    string s = "bbbbbaaaaabbabababa";
    int k = 5;
    cout << maximumOccurringStringEfficient(s, k) << endl;

    s = "heisagoodboy";
    k = 5;
    cout << maximumOccurringStringEfficient(s, k) << endl;

    return 0;
}