#include<stdio.h>
#include<time.h>
#include<stdbool.h>
#include<stdlib.h>

int main(){ //main
	FILE *fptr; //file pointer
	fptr = fopen("assign4.txt","w");
	// srand(time(NULL));
	int n;
	printf("Enter the number of integers to be stored: ");
	scanf("%d",&n);

	bool arr[100000]={0}; 
	time_t t; //using the time of the system clock to generate random numbers
  	srand((unsigned)time(&t)); 
	for(int i=0;i<n;++i) { 
	    unsigned int r=rand()%100000; 
	    if(!arr[r]) 
	      fprintf(fptr,"%d\n",r); 
	    else 
	      i--; 
	    arr[r]=1;     
	}
	printf("Integers generated! Check Text File!\n");
	fclose(fptr); //closing the file pointer
	return 0;
}