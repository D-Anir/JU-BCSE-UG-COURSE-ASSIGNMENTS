import re

text = input("Enter phone number: ")

pattern = re.search(r'(\d{3})[ -]?(\d{3})[ -]?(\d{4})', text)

if pattern:
    print("Valid Phone Number: {}".format(pattern.string))
else:
    print("Invalid phone number.")

# print(pattern.group())


# *** *** ****
# ***-***-****
# **********