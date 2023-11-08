import re

def get_column_data(file_path, column_header):
    header_indices = {}
    data = []

    with open(file_path, 'r') as file:
        # Read the file line by line
        for line in file:
            # Skip comments
            if line.startswith('#'):
                continue
            
            # Detect and process the headers row
            if not header_indices:
                headers = line.split()
                end = 0
                for header in headers:
                    start = line.index(header, end)
                    end = start + len(header)
                    header_indices[header] = (start, end)
                continue
            
            # Extract the column data
            if column_header in header_indices:
                start, end = header_indices[column_header]
                value = line[start:end].strip()
                # Skip if the value cannot be converted to float
                if re.match(r'^-?\d+(?:\.\d+)?$', value):
                    data.append(float(value))
    
    if not data and column_header not in header_indices:
        return None, "Column not found"
    
    return data, None

# Example usage:
# Assuming 'data.txt' is your file and 'ColumnName' is the header of the column you want.
column_data, error = get_column_data('data.txt', 'ColumnName')

if error:
    print(error)
else:
    print(column_data)

