#include <bits/stdc++.h>
using namespace std;

int findRandom()
{
    // Generate the random number
    int num = ((int)rand() % 2);

    // Return the generated number
    return num;
}

// Function to generate a random
// binary string of length N
void generateBinaryString1(int N)
{
    srand(time(NULL));

    // Stores the empty string
    string S = "";

    // Iterate over the range [0, N - 1]
    for (int i = 0; i < N; i++) {

        // Store the random number
        int x = findRandom();

        // Append it to the string
        S += to_string(x);
    }

    // Print the resulting string
    cout << S;
}


#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <algorithm>

// Function to generate a random binary string of a given length
string generateRandomBinaryString(size_t length) {
    // Use the current time to seed the random number engine for varied results on each run
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed); // Mersenne Twister engine for high quality pseudo-random numbers

    // Define a uniform integer distribution for the range 0 to 1
    std::uniform_int_distribution<int> distribution(0, 1);

    std::string binaryString;
    binaryString.reserve(length); // Reserve memory for efficiency

    // Generate random 0s or 1s and append them to the string
    for (size_t i = 0; i < length; ++i) {
        // Get a random 0 or 1 from the distribution and convert to character '0' or '1'
        binaryString.push_back(distribution(generator) ? '1' : '0');
    }

    return binaryString;
}



int main()
{
    int N = 40000; // Desired length of the binary string
    string randomBinary = generateRandomBinaryString(N);

    cout << randomBinary << endl;

    // You can also use std::generate_n with std::back_inserter for a more functional approach
    // std::string s;
    // std::generate_n(std::back_inserter(s), N, [&]() { return '0' + distribution(generator); });
    // std::cout << "Using generate_n: " << s << std::endl;
   
}