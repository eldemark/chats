import pandas as pd

# Sample DataFrame
data = {'A': [1, 2, 3, 2, 1],
        'B': ['foo', 'bar', 'baz', 'bar', 'foo']}
df = pd.DataFrame(data)

# Find duplicated rows
duplicated_rows = df[df.duplicated(keep=False)]

print(duplicated_rows)


import pandas as pd

# Sample DataFrame with duplicate rows
data = {'A': [1, 2, 3, 2, 1],
        'B': ['foo', 'bar', 'baz', 'bar', 'foo']}
df = pd.DataFrame(data)

# Sort the DataFrame by all columns to group duplicates together
df_sorted = df.sort_values(by=df.columns.tolist())

print(df_sorted)
