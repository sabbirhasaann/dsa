#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void recurPermutation(int index, string &s, vector<string> &ans)
{
    if (index == s.size())
    {
        ans.push_back(s);
        return;
    }

    for (int i = index; i < s.size(); i++)
    {
        swap(s[index], s[i]);
        recurPermutation(index + 1, s, ans);
        swap(s[index], s[i]);
    }
}

vector<string> findPermutation(string s)
{
    vector<string> ans;

    recurPermutation(0, s, ans);

    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    vector<string> ans = findPermutation(s);
    for (auto i : ans)
        cout << i << endl;
}