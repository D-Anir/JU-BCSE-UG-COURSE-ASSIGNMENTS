import itertools

even_select = [0]*20
odd_select = [0]*20

numbers = [0]*20

for i in range(1, 21):
    numbers[i-1] = i
    if i%2:
        even_select[i-1] = False
        odd_select[i-1] = True
    else:
        even_select[i-1] = True
        odd_select[i-1] = False


evens = itertools.compress(numbers, even_select)
odds = itertools.compress(numbers, odd_select)

print("First 10 evens:")
for i in evens:
    print(i)

print("\nFirst 10 odds:")
for i in odds:
    print(i)

