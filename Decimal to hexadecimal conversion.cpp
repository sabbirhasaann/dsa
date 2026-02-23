// 2026/02/23 06:38:03
// https://www.geeksforgeeks.org/dsa/decimal-to-hexadecimal-conversion/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void DecToHexIoMap(){
    int number = 255;

    // Print the number in hexadecimal format
    cout << "Decimal: " << number << endl;
    cout << "Hexadecimal: " << hex << number << endl;

    // Use std::uppercase to print A-F as capital letters
    cout << "Hexadecimal (uppercase): " << uppercase << number << endl;

    // Use std::setfill and std::setw to format with leading zeros (e.g., FF instead of ff)
    // Note: std::hex persists for subsequent integer outputs on the same stream unless changed back with std::dec
    cout << "Formatted Hex: 0x" << setfill('0') << setw(2) << hex << number << endl;
}

string intToHexSstream(int value) {
    stringstream ss;
    ss << hex << value; // Use std::hex to format the output
    return ss.str();
}

// void DecToHexCPP20(){
//     int number = 255;
    
//     // Format as lowercase hex ("ff")
//     string hexLower = format("{:x}", number);

//     // Format as uppercase hex with "0x" prefix and minimum width of 2 ("0xFF")
//     string hexUpperFormatted = format("0x{:02X}", number); 

//     cout << "C++20 std::format example:" << endl;
//     cout << "Lowercase: " << hexLower << endl;
//     cout << "Formatted: " << hexUpperFormatted << endl;
// }


string DecToHex(int n){
    string s;
    while(n){
        char ch;
        int rem = n%16;
        if(rem>9)
            // s += ((rem-10) + 'A');
            s += rem + 55;
        else
            // s += (rem + '0'); 
            s += rem + 48;

        n/=16;
    }

     
    int i = 0, j = s.size() - 1;
    while(i <= j)
    {
      swap(s[i], s[j]);
      i++;
      j--;
    }

    return s;
}

void decToHexa(int n) { cout << hex << n << endl; }

int main(){
    ios_base::sync_with_stdio(false);

    cout <<"Decimal to hexadecimal using iomanip: " << endl << endl;
    DecToHexIoMap();
    cout << endl;

    int number = 42;
    string hexString = intToHexSstream(number);
    cout << "The integer " << number << " in hexadecimal is: " << hexString << endl;


    cout << DecToHex(1111165) << endl;
    decToHexa(1111165);
    return 0;
}