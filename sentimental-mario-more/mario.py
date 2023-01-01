# TODO

# Import the get_int function from cs50
from cs50 import get_int

# Initialize height to aviod error
height = 0

# Ask user for height; accepting only valid heights
while height < 1 or height > 8:
    height = get_int("Height: ")

# Define variables
hash = "#"
space = " "
h = 0
s = height

# Print pyramids
for i in range(height):
    h += 1
    s -= 1
    print(s * space + h * hash + "  " + h * hash)