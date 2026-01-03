#include <iostream>
#include <algorithm> // Required for std::count
#include <vector>    // Using std::vector for dynamic array
using namespace std;
void soln()
{
    // initializating an Array
    int arr[] = {2, 4, 5, 2, 4, 5, 2, 3, 8};

    // Calculating the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Defining the target number to search for
    int target = 2;
    // Initialize a counter
    int counter = 0;

    // Loop through the array elements
    for (int i = 0; i < n; i++)
    {
        // Check if the current element equals the target
        // number
        if (arr[i] == target)
        {
            counter++;
        }
    }

    // Output the result
    cout << "Number " << target << " occurs " << counter
         << " times in the array.";
}

int main()
{
    std::vector<int> numbers = {1, 2, 3, 2, 4, 2, 5};
    int target_element = 2;

    // Use std::count to find the occurrences
    int count = count(numbers.begin(), numbers.end(), target_element);

    std::cout << "The element " << target_element << " appears " << count << " times in the array." << std::endl;

    // Example with a raw C-style array
    int raw_array[] = {10, 20, 10, 30, 10};
    int raw_array_size = sizeof(raw_array) / sizeof(raw_array[0]);
    int target_raw = 10;

    int raw_count = std::count(raw_array, raw_array + raw_array_size, target_raw);
    std::cout << "The element " << target_raw << " appears " << raw_count << " times in the raw array." << std::endl;

    return 0;
}