# TODO

# Import get_string function from cs50 library
from cs50 import get_string

# Prompt user for card number
while True:
    number = get_string("Enter card number: ")
    if len(number) > 0 and number.isnumeric() == True:
        break

# Create a list, idex each char in number
number_list = number[::-1]

# Implement Algorithm
sum_every_other = sum([2 * int(i) // 10 + ((2 * int(i)) % 10) for i in number_list[1::2]])
sum_1 = sum([int(i) for i in number_list[0::2]])
total_sum = sum_every_other + sum_1

# Configure card type
if total_sum % 10 == 0:
    if len(number) == 15 and number[0:2] in ["34", "37"]:
        print("AMEX")
    elif len(number) == 16 and 51 <= int(number[0:2]) <= 55:
        print("MASTERCARD")
    elif len(number) in [13, 16] and number[0] == "4":
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")