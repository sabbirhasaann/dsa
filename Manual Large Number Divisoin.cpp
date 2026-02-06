#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


struct DivisionResult {
    string quotient;
    long long remainder;
};

DivisionResult divideLargeNumber1(string number, long long divisor) {
    string quotient = "";
    long long currentRemainder = 0;

    for (char c : number) {
        // Carry over the remainder and add the next digit
        currentRemainder = currentRemainder * 10 + (c - '0');
        
        // Append the division result to the quotient string
        quotient += (currentRemainder / divisor) + '0';
        
        // Calculate the new remainder
        currentRemainder %= divisor;
    }

    // Clean up leading zeros
    size_t firstDigit = quotient.find_first_not_of('0');
    if (firstDigit == string::npos) {
        quotient = "0";
    } else {
        quotient = quotient.substr(firstDigit);
    }

    return {quotient, currentRemainder};
}

string divideLargeNumber(string number, long long divisor) {
    string quotient;
    long long remainder = 0;

    for (int i = 0; i < number.length(); i++) {
        remainder = remainder * 10 + (number[i] - '0');
        
        quotient += to_string(remainder / divisor);
        
        remainder %= divisor;
    }

    size_t firstRelevance = quotient.find_first_not_of('0');
    if (string::npos == firstRelevance) {
        return "0";
    }
    
    return quotient.substr(firstRelevance);
}

int main() {
    string largeNum;
    largeNum = "123456789012345678901234567890";
    cin >> largeNum;
    long long n = 9;

    // cout << divideLargeNumber(largeNum, n) << endl;

    DivisionResult res = divideLargeNumber1(largeNum, n);

    cout << res.quotient << endl;
    cout << "Remainder: " << res.remainder << endl;

    return 0;
}