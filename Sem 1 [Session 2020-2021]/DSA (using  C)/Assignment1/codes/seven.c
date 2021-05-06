#include <stdio.h>
#include<stdlib.h>

int isprime[10000];
void sieve()	// generating prime status of numbers using sieve of eratosthenes
{
	int n = 1e4;
	for(int i = 2; i < n; ++i)
	{
		if(!isprime[i])
		{
			for(int j = 2 * i; j < n; j += i)
				isprime[j] = 1;
		}
	}
}	

int main()
{
	int L[20];
	for(int i = 0; i < 20; ++i)
	{
		int high = 1e8;
		L[i] = high + rand() % high;	// generating 20 large random numbers
	}
	
	int primes[8];
	sieve();
	int cnt = 0;
	for(int i = 1001; cnt < 8; ++i)	// taking first 8 4-digit prime numbers
	{
		if(!isprime[i])
		{
			primes[cnt++] = i;
		}
	}
	
	for(int i = 0; i < 8; ++i)
	{
		printf("When mod = %d:\n", primes[i]);
		for(int j = 0; j < 20; ++j)
		{
			printf("%d %% %d = %d\n", L[j], primes[i], (L[j] % primes[i]));	// printing the corresponding remainders
		}
	}
	
	return 0;
}
