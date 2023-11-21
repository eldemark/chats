
def baz(x):
    return lambda y: y + x

df['foo'] = df['bar'].map(baz(x))

number = 123.456789
print("{:.2f}".format(number))

print(f"{number:.2f}") # 3.6+


import pandas as pd

# Sample DataFrame
data = {'widget': ['foo', 'foo', 'foo', 'foo', 'bar', 'bar', 'bar', 'baz', 'baz', 'baz'],
        'code': ['x', 'x', 'z', 'z', 'x', 'x', 'z', 'z', 'z', 'z']}
df = pd.DataFrame(data)

# Nested Dictionary
foo_paths = {'x': 'path1', 'z': 'path2'}
bar_paths = {'x': 'path3', 'z': 'path4'}
baz_paths = {'x': 'path5', 'z': 'path6'}
wpaths = {'foo': foo_paths, 'bar': bar_paths, 'baz': baz_paths}

# Function for nested dictionary lookup
def get_path(widget, code):
    return wpaths[widget][code]

# Create new column 'tpath' using 'map' and a lambda function
df['tpath'] = df.apply(lambda row: get_path(row['widget'], row['code']), axis=1)

print(df)
