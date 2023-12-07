#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

int main() {
    std::string binary_file_path = "input_file.bin"; // Replace with your binary file path
    std::string csv_file_path = "output_file.csv";   // Replace with your desired CSV file path

    std::ifstream binary_file(binary_file_path, std::ios::binary);
    std::ofstream csv_file(csv_file_path);

    if (!binary_file.is_open() || !csv_file.is_open()) {
        std::cerr << "Error opening files!" << std::endl;
        return 1;
    }

    std::string line;
    int num_columns;

    // Read the number of columns
    std::getline(binary_file, line);
    std::istringstream(line) >> num_columns;

    // Read and write the column headers
    std::getline(binary_file, line);
    csv_file << line << "\n";

    // Process the binary data
    while (!binary_file.eof()) {
        for (int i = 0; i < num_columns; ++i) {
            float value;
            binary_file.read(reinterpret_cast<char*>(&value), sizeof(value));

            if (binary_file.eof()) break;

            csv_file << value;
            if (i < num_columns - 1) csv_file << ",";
        }
        csv_file << "\n";
    }

    binary_file.close();
    csv_file.close();

    return 0;
}
