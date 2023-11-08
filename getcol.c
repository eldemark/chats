#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 100
#define MAX_HEADER_NAME_LENGTH 256

// Function to trim whitespace from a string (in-place)
char* trimwhitespace(char *str) {
  char *end;

  // Trim leading space
  while(isspace((unsigned char)*str)) str++;

  if(*str == 0)  // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && isspace((unsigned char)*end)) end--;

  // Write new null terminator
  *(end+1) = 0;

  return str;
}

// Function to find a column by its header name and return its data as doubles
int get_column_data(const char *file_path, const char *column_header, double *data, int *data_size) {
    char line[MAX_LINE_LENGTH];
    int column = -1;
    int data_index = 0;

    FILE *file = fopen(file_path, "r");
    if (!file) {
        perror("Error opening file");
        return -1;
    }

    // Skip comments at the beginning
    while (fgets(line, sizeof(line), file)) {
        if (line[0] != '#') {
            break;
        }
    }

    // Now 'line' contains the headers
    char *headers[MAX_COLUMNS];
    char *token = strtok(line, " \t");
    int index = 0;
    while (token && index < MAX_COLUMNS) {
        headers[index++] = trimwhitespace(token);
        token = strtok(NULL, " \t");
    }

    // Find the index of the column
    for (int i = 0; i < index; i++) {
        if (strcmp(headers[i], column_header) == 0) {
            column = i;
            break;
        }
    }

    // If the column wasn't found, return an error
    if (column == -1) {
        fclose(file);
        return -2;
    }

    // Read each line and extract the column data
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        if (line[0] == '#') { // skip comments
            continue;
        }
        
        // Extract the column data
        token = strtok(line, " \t");
        index = 0;
        while (token != NULL) {
            if (index == column) {
                data[data_index++] = strtod(trimwhitespace(token), NULL);
                break;
            }
            token = strtok(NULL, " \t");
            ++index;
        }
    }

    *data_size = data_index; // Set the size of the data array
    fclose(file);
    return 0; // Success
}

int main() {
    const char *filename = "data.txt"; // Replace with your file path
    const char *column_header = "hdr1"; // Replace with your column header
    double data[MAX_LINE_LENGTH]; // Replace MAX_LINE_LENGTH with your expected number of data points
    int data_size = 0;

    int result = get_column_data(filename, column_header, data, &data_size);
    if (result == -1) {
        printf("File could not be opened.\n");
        return 1;
    } else if (result == -2) {
        printf("Column not found.\n");
        return 2;
    }

    // Print the data
    for (int i = 0; i < data_size; i++) {
        printf("%f\n", data[i]);
    }

    return 0;
}
