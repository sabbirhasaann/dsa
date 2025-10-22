#include <iostream>
#include <vector>
using namespace std;

int subarraySum(vector<int> &arr)
{

    int n = arr.size();
    int result = 0;

    // computing sum of subarray using formula
    for (int i = 0; i < n; i++)
        result += (arr[i] * (i + 1) * (n - i));

    // return all subarray sum
    return result;
}
int subarraySumNaive(vector<int> &arr)
{

    int n = arr.size();
    int result = 0, temp = 0;

    // pick starting point
    for (int i = 0; i < n; i++)
    {

        // pick ending point
        temp = 0;
        for (int j = i; j < n; j++)
        {

            // sum subarray between current
            // starting and ending points
            temp += arr[j];
            result += temp;
        }
    }
    return result;
}

int main()
{
    vector<int> arr = {1, 4, 5, 3, 2};
    int n = arr.size();
    cout << subarraySumNaive(arr) << endl;
    cout << subarraySum(arr) << endl;
    return 0;
}