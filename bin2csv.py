import struct

def convert_binary_to_csv(binary_file_path, csv_file_path):
    with open(binary_file_path, 'rb') as bin_file:
        # Read the number of columns from the first line
        num_columns = int(bin_file.readline().decode().strip())

        # Read the column headers from the second line
        column_headers = bin_file.readline().decode().strip().split()

        # Check if the number of columns matches the number of headers
        if len(column_headers) != num_columns:
            raise ValueError("Number of columns does not match number of headers")

        with open(csv_file_path, 'w') as csv_file:
            # Write the column headers to the CSV file
            csv_file.write(','.join(column_headers) + '\n')

            # Read and write the binary data
            while True:
                # Read 32-bit floats from binary file
                data = bin_file.read(4 * num_columns)

                if not data:
                    break

                # Unpack binary data into floats
                values = struct.unpack(f'{num_columns}f', data)

                # Write the data as comma-separated values
                csv_file.write(','.join(map(str, values)) + '\n')

# Example usage
binary_file_path = 'input_file.bin'  # Replace with your binary file path
csv_file_path = 'output_file.csv'    # Replace with your desired CSV file path

convert_binary_to_csv(binary_file_path, csv_file_path)
