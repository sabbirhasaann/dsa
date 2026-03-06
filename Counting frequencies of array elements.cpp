// 2026/03/07 02:08:37
// https://www.geeksforgeeks.org/dsa/counting-frequencies-of-array-elements/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'


vector<vector<int>> countFreqNaive(vector<int>& arr){
    int n = arr.size();
    
    // Mark all array elements as not visited
    vector<bool> visited(n , false);
    vector<vector<int>>ans;
    for (int i = 0; i < n; i++) {
        
        // Skip this element if already processed
        if (visited[i] == true)
            continue;

        // store the frequency
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = true;
                count++;
            }
            
        }
        ans.push_back({arr[i] , count});
    }
    return ans;
}

vector<vector<int>> countFreqBetter(vector<int> &arr){
    int n = arr.size();
    
    // Sort array for binary search
    sort(arr.begin(), arr.end()); 
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
        
        // Find first and last occurrence of arr[i]
        // using lower and upper bound 
        auto firstIter = lower_bound(arr.begin(), arr.end(), arr[i]);
        auto lastIter = upper_bound(arr.begin(), arr.end(), arr[i]);
        int firstIndex = firstIter - arr.begin();
        int lastIndex = lastIter - arr.begin() - 1;
        
        // Calculate frequency
        int fre = lastIndex - firstIndex + 1; 
        ans.push_back({arr[i], fre}); 
        
        // Skip counted elements
        i = lastIndex; 
    }
    return ans;
}


vector<vector<int>> countFreqExpected(vector<int>& arr) {
    
    // stores frequency of each number
    unordered_map<int, int> mp;      
    // stores {number, frequency}
    vector<vector<int>> ans;         

    // count frequency using unordered_map
    for (int num : arr) {
        mp[num]++;
    }

    // build the answer vector from the frequency map
    for (auto &it : mp) {
        ans.push_back({it.first, it.second});
    }

    return ans ;
}


int main(){
    ios_base::sync_with_stdio(false);

    vector <int> arr = {10, 20, 10, 5, 20};
    vector<vector<int>>ans =  countFreq(arr);
    sort(ans.begin(), ans.end()) ;
    for (auto x : ans){
        cout << x[0] << ' '<< x[1] <<'\n';
    }

    return 0;
}