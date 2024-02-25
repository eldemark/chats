import pandas as pd

# Assuming your CSV file is named 'data.csv'
csv_file = 'data.csv'

# Read the CSV file
df = pd.read_csv(csv_file)

# Initialize an empty dictionary to hold the tag-associated lists of integers
tag_dict = {}

# Iterate over each row in the DataFrame
for index, row in df.iterrows():
    # Extract the tag for the current row
    tag = row['tag']
    
    # Extract the integers from columns A, B, C for the current row
    numbers = [row['A'], row['B'], row['C']]
    
    # If the tag is already in the dictionary, append the numbers to the associated list
    if tag in tag_dict:
        tag_dict[tag].append(numbers)
    # If the tag is not in the dictionary, add it with the current list of numbers
    else:
        tag_dict[tag] = [numbers]

# Print the resulting dictionary
print(tag_dict)

#A,B,C,tag
#1,2,3,tag1
#4,5,6,tag2
#7,8,9,tag1

#{
# 'tag1': [[1, 2, 3], [7, 8, 9]],
# 'tag2': [[4, 5, 6]]
#}
