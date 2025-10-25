// 2025/10/25 23:49:05

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
string rev_string(string str)
{
    int n = str.size();
    for (int i = 0, j = n - 1; i < j;)
    {
        if (str[i] == ' ')
            i++;
        if (str[j] == ' ')
            j--;

        if (str[i] != ' ' && str[j] != ' ')
        {
            swap(str[i], str[j]);
            i++;
            j--;
        }
    }
    return str;
}
void soln()
{
    cout << rev_string("internship at geeks for geeks");
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}