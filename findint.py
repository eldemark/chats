
def find_nearest_integer(sorted_list, n):
    nearest = sorted_list[0]
    min_difference = abs(sorted_list[0] - n)

    for num in sorted_list:
        difference = abs(num - n)
        if difference < min_difference:
            nearest = num
            min_difference = difference

    return nearest

# Example usage:
sorted_list = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21,\
               23, 25, 27, 29, 31, 33, 35, 37, 39, 41,\
               43, 45, 47]
n = 8
result = find_nearest_integer(sorted_list, n)
print(result)  # Output: 7
