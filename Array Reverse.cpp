#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reverseArrayBuilt(vector<int> &arr)
{
    reverse(arr.begin(), arr.end());
}

void reverseArrayExpected2(vector<int> &arr)
{
    int n = arr.size();

    // Iterate over the first half and
    // for every index i,
    // swap arr[i] with arr[n - i - 1]
    for (int i = 0; i < n / 2; i++)
        swap(arr[i], arr[n - i - 1]);
}

void reverseArrayExpected1(vector<int> &arr)
{

    // Initialize left to the beginning
    // and right to the end
    int left = 0, right = arr.size() - 1;

    // Iterate till left is less than right
    while (left < right)
    {

        // Swap the elements at left
        // and right position
        swap(arr[left], arr[right]);

        // Increment the left pointer
        left++;

        // Decrement the right pointer
        right--;
    }
}

void reverseArray(vector<int> &arr)
{
    int n = arr.size();

    // Temporary array to store elements
    // in reversed order
    vector<int> temp(n);

    // Copy elements from original array
    // to temp in reverse order
    for (int i = 0; i < n; i++)
        temp[i] = arr[n - i - 1];

    // Copy elements back to original array
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
    vector<int> arr = {1, 4, 3, 2, 6, 5};

    reverseArray(arr);
    printArray(arr);

    arr = {1, 4, 3, 2, 6, 5};
    reverseArrayExpected1(arr);
    printArray(arr);

    arr = {1, 4, 3, 2, 6, 5};
    reverseArrayExpected2(arr);
    printArray(arr);

    arr = {1, 4, 3, 2, 6, 5};
    reverseArrayBuilt(arr);
    printArray(arr);
    return 0;
}