#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

// Define the struct
struct MyStruct {
    std::string name;
    double value1;
    double value2;
    double value3;
};

int main() {
    // Example vector of structs
    std::vector<MyStruct> myVector = {
        {"ItemA", 3.4, 2.1, 4.5},
        {"ItemB", 1.2, 3.3, 0.4},
        {"ItemC", 5.6, 7.8, 9.0}
    };

    // Sorting the vector based on value1
    std::sort(myVector.begin(), myVector.end(), 
              [](const MyStruct &a, const MyStruct &b) -> bool {
                  return a.value1 < b.value1;
              });

    // Display the sorted vector
    for (const auto &item : myVector) {
        std::cout << item.name << ": " 
                  << item.value1 << ", " 
                  << item.value2 << ", " 
                  << item.value3 << std::endl;
    }

    return 0;
}

