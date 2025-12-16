#include <bits/stdc++.h>
using namespace std;

// Function to calculate the product of all
// elements except the current element
vector<int> productExceptSelfNaive(vector<int> &arr)
{
    int n = arr.size();

    // Fill result array with 1
    vector<int> res(n, 1);

    for (int i = 0; i < n; i++)
    {

        // Compute product of all elements except arr[i]
        for (int j = 0; j < n; j++)
        {
            if (i != j)
                res[i] *= arr[j];
        }
    }

    return res;
}

// Function to calculate the product of all
// elements except the current element
vector<int> productExceptSelfBetter(vector<int> &arr)
{
    int n = arr.size();
    vector<int> prefProduct(n), suffProduct(n), res(n);

    // Construct the prefProduct array
    prefProduct[0] = 1;
    for (int i = 1; i < n; i++)
        prefProduct[i] = arr[i - 1] * prefProduct[i - 1];

    // Construct the suffProduct array
    suffProduct[n - 1] = 1;
    for (int j = n - 2; j >= 0; j--)
        suffProduct[j] = arr[j + 1] * suffProduct[j + 1];

    // Construct the result array using
    // prefProduct[] and suffProduct[]
    for (int i = 0; i < n; i++)
        res[i] = prefProduct[i] * suffProduct[i];

    return res;
}

// Function to calculate the product of all elements
// except the current element
vector<int> productExceptSelfExpected(vector<int> &arr)
{
    int zeros = 0, idx = -1;
    int prod = 1;

    // Count zeros and track the index of the zero
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] == 0)
        {
            zeros++;
            idx = i;
        }
        else
        {
            prod *= arr[i];
        }
    }

    vector<int> res(arr.size(), 0);

    // If no zeros, calculate the product for all elements
    if (zeros == 0)
    {
        for (int i = 0; i < arr.size(); i++)
            res[i] = prod / arr[i];
    }
    // If one zero, set product only at the zero's index
    else if (zeros == 1)
        res[idx] = prod;

    return res;
}

vector<int> productExceptSelf(vector<int> &arr)
{
    int n = arr.size();
    vector<int> res(n);
    long long product = 1;
    for (int i = 0; i < n; i++)
        product *= arr[i];

    for (int i = 0; i < n; i++)
        res[i] = product / arr[i];
    return res;
}

void printArray(vector<int> v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}

int main()

{
    vector<int> arr = {10, 3, 5, 6, 2};
    printArray(productExceptSelf(arr));
}