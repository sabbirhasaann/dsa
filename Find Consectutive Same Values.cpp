// 2025/11/03 15:05:27

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
void method2()
{
    if (arr.empty())
    {
        std::cout << "Array is empty." << std::endl;
        return 0;
    }

    int current_value = arr[0];
    int current_run_length = 1;

    for (size_t i = 1; i < arr.size(); ++i)
    {
        if (arr[i] == current_value)
        {
            current_run_length++;
        }
        else
        {
            std::cout << "Value " << current_value << " repeated " << current_run_length << " times." << std::endl;
            current_value = arr[i];
            current_run_length = 1;
        }
    }
    // Print the last run
    std::cout << "Value " << current_value << " repeated " << current_run_length << " times." << std::endl;
}
void method1()
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans++;
        for (int j = i; j < n; j++)
        {
            if (s[j] != s[i])
            {
                i = j - 1;
                break;
            }
            if (j == n - 1)
            {
                i = 2 * n;
                break;
            }
        }
    }
}
void soln()
{
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}