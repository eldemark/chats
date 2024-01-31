#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

void sortTable(std::vector<std::vector<std::string>>& table, size_t columnIndex) {
    // Custom comparison function
    auto compare = [columnIndex](const std::vector<std::string>& row1, const std::vector<std::string>& row2) {
        // Ensure the column index is within the bounds of both rows to avoid out-of-range errors
        if (columnIndex < row1.size() && columnIndex < row2.size()) {
            return row1[columnIndex] < row2[columnIndex];
        }
        return false; // In case of out-of-range, don't attempt to sort
    };

    // Sort the table using the custom comparison function
    std::sort(table.begin(), table.end(), compare);
}

int main() {
    // Example table data
    std::vector<std::vector<std::string>> table = {
        {"Alice", "Smith", "24"},
        {"Bob", "Johnson", "30"},
        {"Charlie", "Williams", "28"}
    };

    // Sort the table based on the third column (age)
    sortTable(table, 2);

    // Print the sorted table
    for (const auto& row : table) {
        for (const auto& col : row) {
            std::cout << col << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
