import re

def get_column_data(file_path, column_header):
    with open(file_path, 'r') as file:
        # Skip initial comments
        line = file.readline()
        while line.startswith('#'):
            line = file.readline()
        
        # The line now contains headers; strip leading/trailing spaces
        headers = line.strip().split()
        
        # Find the index of the column
        try:
            column_index = headers.index(column_header)
        except ValueError:
            return None, "Column not found"
        
        # Read the data
        data = []
        for line in file:
            if not line.strip() or line.startswith('#'):  # Skip empty lines and comments
                continue
            
            # Split the line into columns based on fixed width
            columns = re.findall(r'(\S+)', line)
            try:
                # Convert the string to a float and append to the data list
                data.append(float(columns[column_index]))
            except (ValueError, IndexError):
                # Handle the case where conversion to float fails or index is out of range
                return None, "Data conversion error or index out of range"
        
        return data, None  # Return the list of floats

# Example usage:
file_path = 'data.txt'
column_header = 'hdr1'
data, error = get_column_data(file_path, column_header)

if data is not None:
    print(f"Data for column '{column_header}':")
    for value in data:
        print(value)
else:
    print(error)
