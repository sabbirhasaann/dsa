// 2026/02/23 07:19:37
// https://www.geeksforgeeks.org/dsa/decimal-to-octal-conversion/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void DecToOctIoManip(){
    int decimal_num = 125;
    cout << "Decimal number: " << decimal_num << endl;
    cout << "Octal equivalent: " << oct << decimal_num << endl;

}

string DecToOct(int n){
    string s;
    while(n){
        // s += (n%8 + '0');
        s += n%8 + 48;

        n/=8;
    }
    reverse(s.begin(), s.end());
    return s;
}

string decimalToOctal(int n) {
    if (n == 0) return "0";

    bool isNegative = (n < 0);
    long long num = abs(static_cast<long long>(n)); // Work with absolute value
    string octal_str = "";

    while (num > 0) {
        int remainder = num % 8;
        octal_str += to_string(remainder);
        num /= 8;
    }

    reverse(octal_str.begin(), octal_str.end()); // Reverse the remainders
    
    if (isNegative) {
        octal_str.insert(0, "-");
    }

    return octal_str;
}

void decToOctal(int n)
{
    // Array to store octal number
    int octalNum[100];

    // Counter for octal number array
    int i = 0;
    while (n != 0) {
        // Storing remainder in octal array
        octalNum[i] = n % 8;
        n = n / 8;
        i++;
    }

    // Printing octal number array in
    // reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << octalNum[j];
}

int main(){
    ios_base::sync_with_stdio(false);

    DecToOctIoManip();
    cout << DecToOct(125) << endl;
    cout << decimalToOctal(110) << endl;
    decToOctal(INT_MAX);
    return 0;
}