arr = [num for num in range(1,100)]

filteredArr = list(filter(lambda x: (x%2 == 1), arr))

myArr = list(map(lambda x: x*x, filteredArr))

print(myArr)