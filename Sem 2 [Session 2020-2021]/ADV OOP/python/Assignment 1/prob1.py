num = int(input("Enter a number: "))
flag = 0


for ele in range(2, num):
   if ele > 1:
       for i in range(2, ele):
           if (ele % i) == 0:
               break
       else:
           print(ele)