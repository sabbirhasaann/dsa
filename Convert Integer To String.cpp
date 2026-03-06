#include <iostream> // For input/output operations
#include <string>   // For std::to_string() and std::string
using namespace std;

int main()
{
    int number = 123;
    string str_number = to_string(number);

    cout << "The integer number is: " << number << endl;
    cout << "The string representation is: " << str_number << endl;

    // You can now concatenate the string with other strings
    string message = "The converted number is: " + str_number;
    cout << message << endl;

    return 0;
}