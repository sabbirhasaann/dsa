#include <iostream>
#include <vector>
using namespace std;

void modifyArray_expected(vector<int> &arr)
{
    int i = 0;
    while (i < arr.size())
    {

        // Swap if the element arr[i] is not at arr[arr[i]]
        if (arr[i] != -1 && arr[i] != arr[arr[i]])
        {
            swap(arr[i], arr[arr[i]]);
        }
        else
        {

            // Increment i if element is at its correct position
            i++;
        }
    }
}

// Function to rearrange the array such that arr[i] = i.
void modifyArray_better(vector<int> &arr)
{
    int n = arr.size();
    vector<int> temp(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != -1)
        {
            temp[arr[i]] = arr[i];
        }
    }

    // Update the original array
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}

void modifyArray_naive(vector<int> &arr)
{
    int n = arr.size();

    // Move i to arr[i] if present
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == i)
            {
                swap(arr[i], arr[j]);
                break;
            }
        }
    }

    // Put -1 for places where i is
    // not present
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i)
        {
            arr[i] = -1;
        }
    }
}

void printArray(vector<int> &v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}
int main()
{
    vector<int> arr;
    arr = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
    modifyArray_naive(arr);
    printArray(arr);

    arr = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
    modifyArray_better(arr);
    printArray(arr);

    arr = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
    modifyArray_expected(arr);
    printArray(arr);
    return 0;
}