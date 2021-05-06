import itertools

num = [i for i in range(1, 20)];

check = 1

even_check = [ check for n in num if n%2==0 else check = 0 ]                        
odd_check = [ check for n in num if n%2==1 else check = 0 ]

even = itertools.compress(num, even_check)
odd = itertools.compress(num, odd_check)

for i in even:
    print(even)

for i in odd:
    print(odd)