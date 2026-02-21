// 2026/02/21 13:45:57
// https://www.geeksforgeeks.org/dsa/count-set-bits-in-an-integer/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

unsigned int countSetBitsNaive(unsigned int n)
{
    unsigned int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

// recursive function to count set bits
int countSetBitsRecursive(int n)
{
    // base case
    if (n == 0)
        return 0;
    else
        // if last bit set add 1 else add 0
        return (n & 1) + countSetBitsRecursive(n >> 1);
}

unsigned int countSetBitsBrian(int n) //Brian Kernighan's Algorithm
{
    unsigned int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}


int BitsSetTable256[256];

// Function to initialise the lookup table 
void initialize() 
{ 
    // To initially generate the 
    // table algorithmically 
    BitsSetTable256[0] = 0; 
    for (int i = 0; i < 256; i++)
        BitsSetTable256[i] = (i & 1) + BitsSetTable256[i / 2]; 
} 

// Function to return the count 
// of set bits in n 
int countSetBitsLookUpTable(int n) 
{ 
    return (BitsSetTable256[n & 0xff] + 
            BitsSetTable256[(n >> 8) & 0xff] + 
            BitsSetTable256[(n >> 16) & 0xff] + 
            BitsSetTable256[n >> 24]); 
} 


int num_to_bits[16] = { 0, 1, 1, 2, 1, 2, 2, 3,
                        1, 2, 2, 3, 2, 3, 3, 4 };

/* Recursively get nibble of a given number 
and map them in the array */
unsigned int countSetBitsRecMappingNibble(unsigned int num)
{
    int nibble = 0;
    if (0 == num)
        return num_to_bits[0];

    // Find last nibble
    nibble = num & 0xf;

    // Use pre-stored values to find count
    // in last nibble plus recursively add
    // remaining nibbles.
    return num_to_bits[nibble] + countSetBitsRecMappingNibble(num >> 4);
}

// Function to find largest power of 2 such that
// pow(2,k) <= N 
int findk(int n)
{ int k; int i=0; int val=pow(2,i);
  
 while(val<=n)
 { 
     k=i; i++;
    val=pow(2,i);
 }
  return k;
}

// Function to count set bits in a number
int countSetBitsPowerOf2(int N)
{
    int count = 0;
    int k=findk(N);
    int val , x;
  
    // Iterating from largest power to 2 such that 
    // pow(2,k) to 0
    for (int i = k; i >= 0; i--)
    {
        val=pow(2,i);
        x=val & N; //x will store Bitwise AND of N & val
      
       if(x > 0)
       { count++;
       }
    }
    return count;//return count of set bits
}



int main(){
    ios_base::sync_with_stdio(false);

    int n = 19;
    cout << countSetBitsNaive(n) << endl;
    cout << countSetBitsRecursive(n) << endl;
    cout << countSetBitsBrian(n) << endl;
    initialize(); // lookuptable
    cout << countSetBitsLookUpTable(n) << endl;
    cout << countSetBitsRecMappingNibble(n) << endl;
    cout << countSetBitsPowerOf2(n) << endl;
    //builtin
    cout << __builtin_popcount(n) << endl;
    return 0;
}