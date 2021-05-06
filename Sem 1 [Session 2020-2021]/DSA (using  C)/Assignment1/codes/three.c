#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int b_search(int arr[], int l, int r, int x){ //binary search on integer array
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        if (arr[mid] == x) 
            return mid; 

        if (arr[mid] > x) 
            return b_search(arr, l, mid - 1, x); 

        return b_search(arr, mid + 1, r, x); 
    }
    return -1; 
}

int lsearch1(float a[],int n,float x){ //linear search for float array
	for(int i=0;i<n;i++){
		if(a[i]==x)
			return 1;
	}
	return 0;
}

int lsearch2(char **Array, const char *key, int n) { //liner search for char array
    for (int i = 0; i < n; ++i) {
        if (strcmp(Array[i], key) == 0)
            return i;
    }
    return 0;
}


int main(){ //main
	int n; 
	printf("Enter number of elements: ");
	scanf("%d",&n);
	int ai[n];
	float af[n];
	char* words[n];
	for(int i=0;i<n;i++){
		words[i]=malloc(10*sizeof(char));
		printf("Enter integer %d: ",i+1);
		scanf("%d",&ai[i]);
		printf("Enter float %d: ",i+1);
		scanf("%f",&af[i]);
		printf("Enter word %d: ",i+1);
		scanf("%s",words[i]);
		printf("\n");
	}
	int k;float j;char a[10];
	printf("Enter the integer to be searched: ");
	scanf("%d",&k);
	printf("Enter the float to be searched: ");
	scanf("%f",&j);
	printf("Enter the word to be searched: ");
	scanf("%s",a);

	if(b_search(ai,0,n-1,k)!=0)
		printf("Integer found\n");
	else
		printf("Integer not found\n");
	
	if(lsearch1(af,n,j)!=0)
		printf("Float found\n");
	else
		printf("Float not found\n");
	
	if(lsearch2(words,a,n)!=0)
		printf("Word found\n");
	else
		printf("Word not found\n");
	
	return 0;
}