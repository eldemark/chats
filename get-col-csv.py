import csv

def get_column_data(file_path, header_name):
    """
    Reads a CSV file and returns the data of the specified column.

    Parameters:
    file_path (str): The path to the CSV file.
    header_name (str): The name of the column header.

    Returns:
    list: A list of floating point numbers from the specified column.
    """
    try:
        with open(file_path, 'r') as csvfile:
            reader = csv.DictReader(csvfile)
            if header_name not in reader.fieldnames:
                return f"Header '{header_name}' not found in the file."

            return [float(row[header_name]) for row in reader if row[header_name]]
    except FileNotFoundError:
        return "File not found."
    except Exception as e:
        return f"An error occurred: {e}"

# Example usage
file_path = '/path/to/your/data.csv'
column_data = get_column_data(file_path, 'x')  # Replace 'x' with the desired header name
print(column_data)
