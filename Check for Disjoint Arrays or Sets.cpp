// C++ program to check if the given arrays are disjoint
// using two nested loops

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool areDisjoint_expected(vector<int> &a, vector<int> &b)
{
    unordered_set<int> st;

    // Insert all elements of array
    // a into the hash set
    for (int ele : a)
        st.insert(ele);

    for (int ele : b)
    {

        // If an element from b is found in the
        // hash set, arrays are not disjoint
        if (st.find(ele) != st.end())
            return false;
    }

    return true;
}

bool areDisjoint_better(vector<int> &a, vector<int> &b)
{

    // Sorting both the arrays
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Initializing pointers at the
    // beginning of both the arrays
    int i = 0, j = 0;

    while (i < a.size() && j < b.size())
    {

        // If any common element is found, then
        // given arrays are not disjoint
        if (a[i] == b[j])
            return false;

        // Incrementing the pointer
        // having smaller value
        if (a[i] < b[j])
            i++;
        else
            j++;
    }

    return true;
}

bool areDisjoint_naive(vector<int> &a, vector<int> &b)
{

    // Take every element of array a
    // and search it in array b
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            // If any common element is found
            // given arrays are not disjoint
            if (a[i] == b[j])
                return false;
        }
    }

    return true;
}

int main()
{
    vector<int> a = {12, 34, 11, 9, 3};
    vector<int> b = {7, 2, 1, 5};

    if (areDisjoint_naive(a, b))
        cout << "True";
    else
        cout << "False";

    cout << endl;
    if (areDisjoint_better(a, b))
        cout << "True";
    else
        cout << "False";
    cout << endl;
    if (areDisjoint_expected(a, b))
        cout << "True";
    else
        cout << "False";
    cout << endl;
    return 0;
}