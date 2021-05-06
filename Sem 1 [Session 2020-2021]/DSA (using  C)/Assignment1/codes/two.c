#include<stdio.h>

int fibo_iter(int n){ //generating fibonacci using iteration
	if(n<=1){
		return n;
	}
	int a[n+1];
	a[0]=0;a[1]=1;
	for(int i=2;i<n+1;i++){
		a[i]=a[i-1]+a[i-2];
	}
	return a[n];
}

int fibo_recur(int n){ //generating fibonacci using recursion
	if(n<=1)
		return n;
	return fibo_recur(n-1)+fibo_recur(n-2);
}

int fibMax(){ //finding overflow in storing fibonacci
	int temp;
    int last = 1;
    int fib = 1;
	while (fib+last>fib) {
        temp=fib;
        fib+=last;
        last=temp;
    }
    return fib;
}

int main(){ //main
	int n;
	printf("Enter the number:");
	scanf("%d",&n);
	printf("%dth fibonacci using iterative and recursive approach respectively is: %d %d\n",n,fibo_iter(n),fibo_recur(n));
	printf("\nThe largest integer <int> for which fibonacci can be calculated is: %d\n",fibMax());
	return 0;
}