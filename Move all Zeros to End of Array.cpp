#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void pushZerosToEnd_another(vector<int> &arr)
{
    stable_partition(arr.begin(), arr.end(), [](int n)
                     { return n != 0; });
}

void pushZerosToEnd_expected(vector<int> &arr)
{

    // Pointer to track the position
    // for next non-zero element
    int count = 0;

    for (int i = 0; i < arr.size(); i++)
    {

        // If the current element is non-zero
        if (arr[i] != 0)
        {

            // Swap the current element with
            // the 0 at index 'count'
            swap(arr[i], arr[count]);
            // Move 'count' pointer to the
            // next position
            count++;
        }
    }
}

void pushZerosToEnd_better(vector<int> &arr)
{

    // Count of non-zero elements
    int count = 0;

    // If the element is non-zero, replace the element at
    // index 'count' with this element and increment count
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
            arr[count++] = arr[i];
    }

    // Now all non-zero elements have been shifted to
    // the front. Make all elements 0 from count to end.
    while (count < arr.size())
        arr[count++] = 0;
}

void pushZerosToEnd_naive(vector<int> &arr)
{
    int n = arr.size();
    vector<int> temp(n);

    // to keep track of the index in temp[]
    int j = 0;

    // Copy non-zero elements to temp[]
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
            temp[j++] = arr[i];
    }

    // Fill remaining positions in temp[] with zeros
    while (j < n)
        temp[j++] = 0;

    // Copy all the elements from temp[] to arr[]
    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
}

void printArray(vector<int> &v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
    pushZerosToEnd_naive(arr);
    printArray(arr);

    arr = {1, 2, 0, 4, 3, 0, 5, 0};
    pushZerosToEnd_better(arr);
    printArray(arr);

    arr = {1, 2, 0, 4, 3, 0, 5, 0};
    pushZerosToEnd_expected(arr);
    printArray(arr);

    arr = {1, 2, 0, 4, 3, 0, 5, 0};
    pushZerosToEnd_another(arr);
    printArray(arr);

    return 0;
}