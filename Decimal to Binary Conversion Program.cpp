#include <bits/stdc++.h>
using namespace std;

string decToBinDiv2(int n){
    string s;
    while(n){
        int rem = n%2;
        n/=2;
        s += rem + '0';
    }
    reverse(s.begin(), s.end());
    return s;
}

void decToBinaryRec(int n, string &bin) {
  	
  	if (n==0) 
      	return;
  	decToBinaryRec(n/2, bin);
  	bin.push_back(n%2 + '0');
}

string decToBinaryR(int n) {
  	if (n == 0) 
      	return "0";
  
    string bin = "";
  	decToBinaryRec(n, bin);
  	return bin;
}

string decToBinBitwise(int n){
    string s;
    while(n){
        s += (n&1) + '0';
        n>>=1;
    }
    reverse(s.begin(), s.end());
    return s;
}


string decToBinary(int n) {
    
    int len = (int)(log2(n));
  
	// Store in bitset to get the binary representation, 
  	// then convert it to string
  	// and finally remove the prefix zeroes
  	
    return bitset<64>(n).to_string().substr(64 - len - 1);
}

int main()
{
    cout << decToBinDiv2(12) << endl;
    cout << decToBinBitwise(12) << endl;
    cout << decToBinaryR(12) << endl;
    cout << decToBinary(12) << endl;
}