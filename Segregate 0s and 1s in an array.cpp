#include <bits/stdc++.h>
using namespace std;



// Function to segregate 0s and 1s
void segregate0and1Naive(vector<int>& arr) {
  
    // Count 0s
    int count = 0; 
    for (int x : arr)
        if (x == 0)
            count++;

    // Fill the vector with 0s until count
    for (int i = 0; i < count; i++)
        arr[i] = 0;

    // Fill the remaining vector space with 1s
    for (int i = count; i < arr.size(); i++)
        arr[i] = 1;
}



void segregate0and1Expected(vector<int> &arr){
    int idx = 0, n = arr.size();
    for(int i=0;i<n;i++)
    {
        if(arr[i] != 1)
        {
            swap(arr[i], arr[idx]);
            idx++;
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
    vector<int> arr = {0, 1, 0, 1, 0, 0, 1, 1, 1, 0};
    segregate0and1Naive(arr);
    printArray(arr);

    arr = {0, 1, 0, 1, 0, 0, 1, 1, 1, 0};
    segregate0and1Expected(arr);
    printArray(arr);


}