numArr = [num for num in range(1,51)]

myList = list(filter(lambda x: (x%5 == 0), numArr))

print(myList)