#include <bits/stdc++.h>
using namespace std;

bool isSubset_expected(vector<int> &a, vector<int> &b)
{

    // Create a hash set and insert all elements of a
    multiset<int> hashSet(a.begin(), a.end());

    // Check each element of b in the hash set
    for (int num : b)
    {
        if (hashSet.find(num) == hashSet.end())
            return false;
        hashSet.erase(hashSet.find(num));
    }

    // If all elements of b are found in the hash set
    return true;
}

bool isSubset_better(vector<int> a, vector<int> b)
{
    // Sort both arrays
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0;
    int m = a.size(), n = b.size();

    while (i < m && j < n)
    {
        if (a[i] < b[j])
            i++; // move in a to catch up

        else if (a[i] == b[j])
        {
            i++;
            j++; // matched one element from b
        }
        else
            // a[i] > b[j] → means b[j] is missing
            return false;
    }

    return (j == n); // all b[] matched
}

bool isSubset_naive(vector<int> a, vector<int> b)
{

    // Iterate over each element in the second array
    int m = a.size(), n = b.size();
    for (int i = 0; i < n; i++)
    {
        bool found = false;

        // Check if the element exists in the first array
        for (int j = 0; j < m; j++)
        {
            if (b[i] == a[j])
            {
                found = true;
                a[j] = -1;
                break;
            }
        }

        // If any element is not found, return false
        if (!found)
            return false;
    }

    // If all elements are found, return true
    return true;
}

int main()
{
    vector<int> a = {11, 1, 13, 21, 3, 7};
    vector<int> b = {11, 3, 7, 1};

    if (isSubset_naive(a, b))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    if (isSubset_better(a, b))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    if (isSubset_expected(a, b))
        cout << "True" << endl;
    else
        cout << "false" << endl;

    return 0;
}