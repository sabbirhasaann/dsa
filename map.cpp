#include <iostream>
#include <map>
#include <string>
#include<bits/stdc++.h>

int main() {
    std::map<int, std::string> myMap;
    myMap[3] = "three";
    myMap[1] = "one";
    myMap[2] = "two";

    // Iterating through the map will show elements sorted by key
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }


    /// sort by value
    std::map<std::string, int> mymap;
    mymap["apple"] = 5;
    mymap["banana"] = 2;
    mymap["cherry"] = 8;

    // Copy map elements to a vector of pairs
    std::vector<std::pair<std::string, int>> vec(mymap.begin(), mymap.end());

    // Sort the vector by value (ascending)
    std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    // Print the sorted vector
    for (const auto& pair : vec) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    return 0;
}