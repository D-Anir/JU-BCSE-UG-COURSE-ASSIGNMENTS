#include<stdio.h>


int fact_iter(int n){ //function to implement factorial using iteration
	int f=1;
	for(int i=2;i<=n;i++)
		f*=i;
	return f;
}

int fact_recur(int n){ //function to implement factorial using recursion
	if(n==1)
		return 1;
	else
		return n * fact_recur(n-1);
}

int findMaxValue() //function to find max factorial of an int data
{ 
    int res = 1; 
    int fact = 2; 
    while(1) 
    { 
        if(fact<0) 
            break; 
        res++; 
        fact*=res; 
    } 
    return res-1; 
}

int findMaxValueLong() //function to find max factorial of a long data
{ 
    int res = 2; 
    long long int fact = 2; 
    while(1) 
    { 
        if(fact<0) 
            break; 
        res++; 
        fact*=res; 
    } 
    return res-1; 
}

int main(){ //main
	int n;
	printf("Enter the number:");
	scanf("%d",&n);
	printf("Factorial of %d using iterative and recursive approach respectively is: %d %d\n",n,fact_iter(n),fact_recur(n));
	printf("\nThe largest integer for which factorial can be calculated is: %d",findMaxValue());
	printf("\nThe largest integer for which factorial can be calculated is: %d\n",findMaxValueLong());
	return 0;
}