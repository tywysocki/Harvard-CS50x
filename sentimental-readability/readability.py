# TODO

# Import get_string from cs50 library
from cs50 import get_string

# Prompt user to enter text
text = get_string("Enter text: ")

# Calculate # of spaces in text
spaces = 0
for i in range(len(text)):
    if text[i] == " ":
        spaces += 1

# Calculate # words in text
words = spaces + 1

# Calculate # special characters in text
specials = 0
for i in range(len(text)):
    if text[i] == "." or text[i] == "!" or text[i] == "?":
        specials += 1

# Calculate # of sentences in text
sentences = specials

# Calculate # of letters in text
letters = len(text) - spaces - specials

# Calculate L, S, and index
L = (letters / words) * 100
S = (sentences / words) * 100
index = 0.0588 * L - 0.296 * S - 15.8

# Show the user which grade is required to read the text
if index < 1:
    print("Before Grade 1")
elif index >= 1 and index < 16:
    if index > 4.95 and index < 4.98:
        print("Grade 5")
    else:
        print(f"Grade {index}")
elif index >= 16:
    print("Grade 16+")