#include <iostream> // For input/output operations
#include <string>   // For std::to_string() and std::string

int main()
{
    int number = 123;
    std::string str_number = std::to_string(number);

    std::cout << "The integer number is: " << number << std::endl;
    std::cout << "The string representation is: " << str_number << std::endl;

    // You can now concatenate the string with other strings
    std::string message = "The converted number is: " + str_number;
    std::cout << message << std::endl;

    return 0;
}