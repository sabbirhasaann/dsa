#include <bits/stdc++.h>
using namespace std;

long long find_max_x(long long n) {
    // Calculate the cube root as a floating-point number
    double cbrt_n = cbrt(static_cast<double>(n));

    // Use std::floor and cast to long long to get the integer part
    long long x = static_cast<long long>(std::floor(cbrt_n));
    
    // Due to floating point inaccuracies, we might need slight adjustments
    // Check the value and increment/decrement if needed to ensure x^3 <= n
    while (x * x * x > n) {
        x--;
    }
    while ((x + 1) * (x + 1) * (x + 1) <= n) {
        x++;
    }
    
    return x;
}

long long find_max_x_binary(long long n) {
    long long left = 0;
    long long right = 100000; // An appropriate upper bound (e.g. cbrt(LONG_MAX) is around 2097151)
    long long ans = 0;

    // A more accurate upper bound can be cbrt(n) or a large enough constant
    if (n < 0) {
        // Handle negative cases if needed (range would be different, left = n, right = 0)
        // For simplicity, this example assumes n >= 0
        return find_max_x_binary(-n) * -1; // Basic handling, needs refinement for edge cases
    }
    
    // Binary search to find the largest x such that x*x*x <= n
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        // Check for potential overflow when calculating mid*mid*mid
        if (mid * mid * mid <= n) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int main() {
    long long n;
    cout << "Enter a number n: ";
    cin >> n;

    long long result = find_max_x(n);
    cout << "The highest integer x such that x^3 <= n is: " << result << endl;


    result = find_max_x_binary(n);
    cout << "The highest integer x such that x^3 <= n is: " << result << endl;

    return 0;
}
