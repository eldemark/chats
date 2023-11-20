import csv
import argparse

def read_csv(file_path):
    with open(file_path, newline='') as csvfile:
        reader = csv.reader(csvfile)
        return [row for row in reader]

def calculate_widths(rows):
    widths = [len(cell) for cell in rows[0]]
    for row in rows[1:]:
        for i, cell in enumerate(row):
            widths[i] = max(widths[i], len(cell))
    return widths

def print_right_justified(rows, widths):
    for row in rows:
        for i, cell in enumerate(row):
            print(f"{cell.rjust(widths[i])} ", end='')
        print()

def main():
    parser = argparse.ArgumentParser(description='Process a CSV file.')
    parser.add_argument('file_path', help='Path to the CSV file')
    args = parser.parse_args()

    rows = read_csv(args.file_path)
    widths = calculate_widths(rows)
    print_right_justified(rows, widths)

if __name__ == "__main__":
    main()
