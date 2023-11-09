#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

std::vector<double> getColumnData(const std::string& file_path, const std::string& column_header) {
    std::ifstream file(file_path);
    std::vector<double> column_data;
    
    if (!file) {
        throw std::runtime_error("Cannot open file.");
    }

    std::string line;
    // Skip initial comments
    while (std::getline(file, line)) {
        if (line.empty() || line[0] != '#') {
            break;
        }
    }

    // Tokenize the header line and find the column index
    std::istringstream iss(line);
    std::vector<std::string> headers{ std::istream_iterator<std::string>{iss},
                                      std::istream_iterator<std::string>{} };
    
    auto it = std::find(headers.begin(), headers.end(), column_header);
    if (it == headers.end()) {
        throw std::runtime_error("Column header not found.");
    }

    size_t column_index = std::distance(headers.begin(), it);
    
    // Read the data lines
    while (std::getline(file, line)) {
        if (!line.empty() && line[0] != '#') {
            iss.clear();
            iss.str(line);
            std::vector<std::string> tokens{ std::istream_iterator<std::string>{iss},
                                             std::istream_iterator<std::string>{} };
            if (tokens.size() > column_index) {
                column_data.push_back(std::stod(tokens[column_index]));
            }
        }
    }

    return column_data;
}

int main() {
    const std::string filename = "data.txt"; // Replace with your file path
    const std::string column_header = "hdr1"; // Replace with your column header

    try {
        std::vector<double> data = getColumnData(filename, column_header);

        // Print the data
        for (double value : data) {
            std::cout << value << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
