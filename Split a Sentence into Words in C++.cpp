// C++ Program to Split a Sentence into Words using stringstream
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>

using namespace std;

vector<string> split_sentence_strtok(char *sen)
{

    // Vector to store the words
    vector<string> words;

    const char delimiter[] = " ";

    // Use strtok to split the sentence into words
    char *word = strtok(sen, delimiter);

    // Loop through each word
    while (word != nullptr)
    {

        // Add the current word to the vector
        words.push_back(word);

        // Get the next word using strtok
        word = strtok(nullptr, delimiter);
    }

    // Return the vector containing words
    return words;
}

vector<string> split_sentence_manual(string sen)
{

    // Vector to store the words
    vector<string> words;

    // Temporary string to hold each word
    string word = "";

    // Iterate through each character in the sentence
    for (char c : sen)
    {
        if (c == ' ')
        {

            // If a space is found, add the word to the vector
            words.push_back(word);

            // Reset the word
            word = "";
        }
        else
        {
            // Append the character to the current word
            word += c;
        }
    }

    // Add the last word to the vector
    if (!word.empty())
    {
        words.push_back(word);
    }

    // Return the vector containing words
    return words;
}

vector<string> split_sentence_find_substr(string sen)
{

    // Vector to store the words
    vector<string> words;

    // Initial index position
    size_t start = 0;

    // Variable to store the position of space
    size_t end;

    // Loop to find and extract words
    while ((end = sen.find(' ', start)) != string::npos)
    {

        // Extract the word using substr
        words.push_back(sen.substr(start, end - start));

        // Update the starting index
        start = end + 1;
    }

    // Add the last word to the vector
    words.push_back(sen.substr(start));

    return words;
}

vector<string> split_sentence_getline_custom_delimeter(string sen)
{

    // Create a stringstream object
    stringstream ss(sen);

    // Variable to hold each word
    string word;

    // Vector to store the words
    vector<string> words;

    // Extract words using getline with space as the delimiter
    while (getline(ss, word, ' '))
    {

        // Add the word to the vector
        words.push_back(word);
    }

    return words;
}

vector<string> split_sentence(string sen)
{

    // Create a stringstream object
    stringstream ss(sen);

    // Variable to hold each word
    string word;

    // Vector to store the words
    vector<string> words;

    // Extract words from the sentence
    while (ss >> word)
    {

        // Add the word to the vector
        words.push_back(word);
    }

    return words;
}

void printArrayStr(vector<string> s)
{
    for (string w : s)
        cout << w << endl;
    cout << endl;
}

int main()
{
    string sen = "Geeks for Geeks";
    char sen1[] = "Geeks for Geeks";

    // Call the function to split the sentence
    printArrayStr(split_sentence(sen));

    printArrayStr(split_sentence_getline_custom_delimeter(sen));

    printArrayStr(split_sentence_find_substr(sen));

    printArrayStr(split_sentence_manual(sen));

    printArrayStr(split_sentence_strtok(sen1));

    return 0;
}