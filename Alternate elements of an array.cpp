// Iterate C++ Program to print alternate elements
// of the array

#include <iostream>
#include <vector>
using namespace std;

void getAlternatesRec(vector<int> &arr, int idx, vector<int> &res)
{
    if (idx < arr.size())
    {
        res.push_back(arr[idx]);
        getAlternatesRec(arr, idx + 2, res);
    }
}

vector<int> getAlternates_iterative(vector<int> &arr)
{
    vector<int> res;

    // Iterate over all alternate elements
    for (int i = 0; i < arr.size(); i += 2)
        res.push_back(arr[i]);
    return res;
}

void printArray(vector<int> &v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50};
    vector<int> res = getAlternates_iterative(arr), res1;
    printArray(res);
    getAlternatesRec(arr, 0, res1);
    printArray(res1);
}