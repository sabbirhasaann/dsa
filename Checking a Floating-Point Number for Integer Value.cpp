#include <iostream>
#include <cmath> // For floor() and ceil()

bool isInteger(double num)
{
    // Option 1: Compare with floor()
    return num == floor(num);

    // Option 2: Compare with ceil()
    // return num == ceil(num);
}

int main()
{
    double num1 = 5.0;
    double num2 = 5.7;
    double num3 = -3.0;
    double num4 = -3.2;

    if (isInteger(num1))
        std::cout << num1 << " is an integer." << std::endl;
    else
        std::cout << num1 << " is not an integer." << std::endl;

    if (isInteger(num2))
        std::cout << num2 << " is an integer." << std::endl;
    else
        std::cout << num2 << " is not an integer." << std::endl;

    // ... and so on for num3 and num4
    return 0;
}