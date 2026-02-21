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

string decToBin32bitUnsigned(unsigned int n){
    string s;
    for(int i=0;i<32;++i){
        if(n & (1<<i))
            s += '1';
        else
            s += '0';       
    }
    return s;
}

int reverseBits(int n){
    int rev = 0;
    for (int i = 0; i < 32; i++) {
        rev <<= 1;
        if (n & 1) {
            rev |= 1;
        }
        n >>= 1;
    }
    return rev;
}

string decToBinaryUniversal(int n) { // whether the number is negative or positive
    // Use unsigned int to get the correct 2's complement bit pattern
    unsigned int num = n; 
    string bin = "";
    for (int i = 0; i < 32; ++i) {
        // Use bitwise AND to check the least significant bit
        bin += ((num & 1) ? '1' : '0'); 
        // Right shift the number by 1
        num >>= 1; 
    }
    reverse(bin.begin(), bin.end()); // Reverse to get correct order
    return bin;
}

void builtinDecToBin(){
    int32_t num = -5;
    // bitset<32> displays the 32-bit binary representation
    std::cout << "Binary of -5 is: " << std::bitset<32>(num) << std::endl; 
    // Output: Binary of -5 is: 11111111111111111111111111111011
}

int main()
{
    cout << decToBinDiv2(12) << endl;
    cout << decToBinBitwise(12) << endl;
    cout << decToBinaryR(12) << endl;
    cout << decToBinary(12) << endl;
    cout << decToBin32bitUnsigned(2147483644) << endl;
    cout << decToBinaryUniversal(-10) << endl;

}