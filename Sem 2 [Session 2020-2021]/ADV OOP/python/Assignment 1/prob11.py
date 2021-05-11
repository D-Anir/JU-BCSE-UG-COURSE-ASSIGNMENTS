def pythagoreanTriplets(maxLimit):
    c, m = 0, 2
    while c < maxLimit:
        for i in range(m):
            a = m**2 - i**2
            b = 2*m*i
            c = m**2 + i**2

            if c > maxLimit:
                break
            
            if(a != 0 and b!=0 and c!=0):
                print(a,b,c)

        m = m + 1

pythagoreanTriplets(17)