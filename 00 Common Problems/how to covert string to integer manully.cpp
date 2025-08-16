#include <iostream>
#include <string>
#include <cmath> // For std::pow if you want to use it for powers of 10

void automatic()
{
    std::string str = "12345";
    try
    {
        int num = std::stoi(str);
        std::cout << "Converted integer: " << num << std::endl;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Out of range: " << e.what() << std::endl;
    }
}
int stringToIntManual(const std::string &str)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    // Handle leading whitespace
    while (i < str.length() && isspace(str[i]))
    {
        i++;
    }

    // Handle sign
    if (i < str.length() && (str[i] == '-' || str[i] == '+'))
    {
        if (str[i] == '-')
        {
            sign = -1;
        }
        i++;
    }

    // Process digits
    while (i < str.length() && isdigit(str[i]))
    {
        result = result * 10 + (str[i] - '0'); // Convert char digit to int and add to result
        i++;
    }

    return result * sign;
}

int main()
{
    std::string s1 = "123";
    std::string s2 = "-456";
    std::string s3 = "   789";
    std::string s4 = "+10";

    std::cout << "String \"" << s1 << "\" to int: " << stringToIntManual(s1) << std::endl;
    std::cout << "String \"" << s2 << "\" to int: " << stringToIntManual(s2) << std::endl;
    std::cout << "String \"" << s3 << "\" to int: " << stringToIntManual(s3) << std::endl;
    std::cout << "String \"" << s4 << "\" to int: " << stringToIntManual(s4) << std::endl;

    return 0;
}
