#include <iostream>
#include <vector>
#include <algorithm> // Required for std::transform

int main()
{
    std::vector<int> arr = {10, 20, 30, 40, 50};
    int value_to_add = 5;
    int value_to_subtract = 3;

    // Addition
    std::transform(arr.begin(), arr.end(), arr.begin(),
                   [value_to_add](int element)
                   { return element + value_to_add; });
    std::cout << "Array after addition: ";
    for (int x : arr)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Subtraction
    std::transform(arr.begin(), arr.end(), arr.begin(),
                   [value_to_subtract](int element)
                   { return element - value_to_subtract; });
    std::cout << "Array after subtraction: ";
    for (int x : arr)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}