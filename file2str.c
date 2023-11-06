
// Read a text file all at once into a c-string.

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char *file_contents;
    long file_size;

    // Open the file for reading
    file = fopen("your_input_file.txt", "rb");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    // Determine the file size
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate memory for the file content as a string
    file_contents = (char *)malloc(file_size + 1);
    if (file_contents == NULL) {
        printf("Memory allocation failed.\n");
        fclose(file);
        return 1;
    }

    // Read the entire file into the string
    size_t bytes_read = fread(file_contents, 1, file_size, file);
    file_contents[bytes_read] = '\0'; // Null-terminate the string

    // Close the file
    fclose(file);

    // Now, the file content is stored in the 'file_contents' string

    // Print the content as an example
    printf("File Content:\n%s\n", file_contents);

    // Free the allocated memory
    free(file_contents);

    return 0;
}

// Return index of first uncommented line in file.

#include <string.h>

// Function to find the index of the first character of the first uncommented line
int findFirstUncommentedLine(const char *fileContents) {
    const char *line = fileContents;

    // Skip leading whitespace and # characters until a non-commented line is found
    while (*line) {
        // Skip leading whitespace
        while (*line && (*line == ' ' || *line == '\t')) {
            line++;
        }

        // Check for a # character indicating a comment
        if (*line == '#') {
            // Skip the rest of the line (until a newline or the end of the string)
            while (*line && *line != '\n') {
                line++;
            }
        } else {
            // A non-commented line is found
            return line - fileContents;
        }

        // Move to the next line
        if (*line) {
            line++;
        }
    }

    // No non-commented line found, return -1 to indicate that
    return -1;
}

int main() {
    const char *fileContents = "  # Commented line\n\n   # Another comment\nUncommented line";

    int index = findFirstUncommentedLine(fileContents);
    if (index != -1) {
        printf("Index of the first uncommented line: %d\n", index);
    } else {
        printf("No uncommented line found.\n");
    }

    return 0;
}

// Return the index of a header field.

#include <stdio.h>
#include <string.h>

int findHeaderIndex(const char *fileContents, int startIndex, const char *headerName) {
    const char *line = fileContents + startIndex;

    // Iterate through the line to find the header
    while (*line && (*line == ' ' || *line == '\t')) {
        line++; // Skip leading whitespace
    }

    // Check if the headerName is present in the line
    while (*line && *line != '\n') {
        // Compare the headerName with the line
        const char *header = headerName;
        const char *linePtr = line;
        while (*header && *linePtr && *header == *linePtr) {
            header++;
            linePtr++;
        }

        // If header is empty, that means a match was found
        if (*header == '\0') {
            return line - fileContents; // Return the index of the header
        }

        line++; // Move to the next character
    }

    // Header not found
    return -1;
}

int main() {
    const char *fileContents = "  # Commented line\nHeader1 Header2   Header3\nUncommented line";

    int startIndex = findFirstUncommentedLine(fileContents);

    if (startIndex != -1) {
        int headerIndex = findHeaderIndex(fileContents, startIndex, "Header2");
        if (headerIndex != -1) {
            printf("Index of 'Header2': %d\n", headerIndex);
        } else {
            printf("Header 'Header2' not found.\n");
        }
    } else {
        printf("No uncommented line found.\n");
    }

    return 0;
}

