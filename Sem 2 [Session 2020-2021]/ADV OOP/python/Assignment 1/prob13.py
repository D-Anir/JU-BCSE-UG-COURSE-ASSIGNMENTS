def generateGP(a, r):
    print("\n")
    for i in range(0, 10000):
        current = a*pow(r,i)
        if current > 100000:
            return
        print(current, end=" ")

a = 1
r = 3

generateGP(a, r)
print("\n")