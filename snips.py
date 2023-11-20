
def baz(x):
    return lambda y: y + x

df['foo'] = df['bar'].map(baz(x))

number = 123.456789
print("{:.2f}".format(number))

print(f"{number:.2f}") # 3.6+
