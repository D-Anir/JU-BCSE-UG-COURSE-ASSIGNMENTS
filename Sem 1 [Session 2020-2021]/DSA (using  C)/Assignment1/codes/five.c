#include<stdio.h>
#include<time.h>
#include<stdbool.h>
#include<stdlib.h>

int main(){ //main
	FILE *fptr;
	fptr = fopen("assign5.txt","w");
	// srand(time(NULL));
	int n;
	printf("Enter the number of strings to be stored: ");
	scanf("%d",&n);

	bool arr[100000]={0}; 
	time_t t; 
  	srand((unsigned)time(&t));

  	char alpha[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};  //alphabet array used to generate randomn permutatons of them
	char res[10];
	
	for(int i=0;i<n;++i) { 
	    int r=rand()%100000;

	    for(int j=0;j<10;j++){
	    	res[j] = alpha[rand() % 26];  //generating random permutations
		}

		if(!arr[r]){
		    for(int j=0;j<10;j++){
	    		fprintf(fptr,"%c",res[j]); //writing in file
			}
			fprintf(fptr,"\n"); 
		}
		else 
			i--; 
		arr[r]=1;
	}
	printf("Strings generated! Check Text File!\n");
	fclose(fptr); //closing file pointer
	return 0;
}