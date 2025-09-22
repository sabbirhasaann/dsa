// C++ Program to right rotate the array by d positions
// by rotating one element at a time

#include <bits/stdc++.h>
using namespace std;

// Function to rotate an array by d elements to the right
void rotateArrReversal(vector<int> &arr, int d)
{
    int n = arr.size();

    // Handle the case where d > size of array
    d %= n;

    // Reverse the entire array
    reverse(arr.begin(), arr.end());

    // Reverse the first d elements
    reverse(arr.begin(), arr.begin() + d);

    // Reverse the remaining n-d elements
    reverse(arr.begin() + d, arr.end());
}

// Function to rotate vector
void rotateArrJuggling(vector<int> &arr, int d)
{
    int n = arr.size();

    // Handle the case where d > size of array
    d %= n;

    // Calculate the number of cycles in the rotation
    int cycles = __gcd(n, d);

    // Process each cycle
    for (int i = 0; i < cycles; i++)
    {

        // Start index of current cycle
        int currIdx = i;
        int currEle = arr[currIdx];

        // Rotate elements till we reach the start of cycle
        do
        {
            int nextIdx = (currIdx + d) % n;
            int nextEle = arr[nextIdx];

            // Update the element at next index with the current element
            arr[nextIdx] = currEle;

            // Update the current element to next element
            currEle = nextEle;

            // Move to the next index
            currIdx = nextIdx;
        } while (currIdx != i);
    }
}

// Function to rotate vector
void rotateArrTemp(vector<int> &arr, int d)
{
    int n = arr.size();

    // Handle case when d > n
    d %= n;

    // Storing rotated version of array
    vector<int> temp(n);

    // Copy last d elements to the front of temp
    for (int i = 0; i < d; i++)
        temp[i] = arr[n - d + i];

    // Copy the first n - d elements to the back of temp
    for (int i = 0; i < n - d; i++)
        temp[i + d] = arr[i];

    // Copying the elements of temp in arr
    // to get the final rotated vector
    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
}

// Function to right rotate array by d positions
void rotateArr(vector<int> &arr, int d)
{
    int n = arr.size();

    // Repeat the rotation d times
    for (int i = 0; i < d; i++)
    {

        // Right rotate the array by one position
        int last = arr[n - 1];
        for (int j = n - 1; j > 0; j--)
            arr[j] = arr[j - 1];
        arr[0] = last;
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
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int d = 2;

    rotateArr(arr, d);
    printArray(arr);

    arr = {1, 2, 3, 4, 5, 6};
    rotateArrTemp(arr, d);
    printArray(arr);

    arr = {1, 2, 3, 4, 5, 6};
    rotateArrJuggling(arr, d);
    printArray(arr);

    arr = {1, 2, 3, 4, 5, 6};
    rotateArrReversal(arr, d);
    printArray(arr);

    return 0;
}