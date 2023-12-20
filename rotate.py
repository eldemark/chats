import pandas as pd
import math

# Define the rotation function
def rotate_point(x, y, theta):
    theta_rad = math.radians(theta)
    x_new = x * math.cos(theta_rad) - y * math.sin(theta_rad)
    y_new = x * math.sin(theta_rad) + y * math.cos(theta_rad)
    return x_new, y_new

# Sample DataFrame
data = {
    'x': [1, 0, 1],
    'y': [0, 1, 1]
}
df = pd.DataFrame(data)

# Angle of rotation
theta = 45  # degrees

# Apply the rotation to each row
df[['x1', 'y1']] = df.apply(lambda row: rotate_point(row['x'], row['y'], theta), axis=1, result_type='expand')

print(df)
