# Pandas

df_foo = df[df['Column1'].str.contains('foo', na=False)]
df_bar = df[df['Column1'].str.contains('bar', na=False)]
df_baz = df[df['Column1'].str.contains('baz', na=False)]

df_foo = df[df['Column1'].str.contains('foo', case=False, na=False)]
df_bar = df[df['Column1'].str.contains('bar', case=False, na=False)]
df_baz = df[df['Column1'].str.contains('baz', case=False, na=False)]
