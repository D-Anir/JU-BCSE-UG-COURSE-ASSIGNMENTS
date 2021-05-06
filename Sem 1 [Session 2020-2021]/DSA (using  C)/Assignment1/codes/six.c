#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAXCHAR 100
#define INT 2147483647

// function to count the name without the spaces
unsigned int noc(char *name){

	int cnt = 0,i;
	int len = strlen(name);
	for(i = 0; i != len; i++) {
   		if(!isspace(name[i])) {
       		cnt++;
   		}
	}

	return cnt;
}


int main(void){
	char str[MAXCHAR]; // for input buffer
	FILE *of;
	of = fopen("6th_in.txt","w");

	if(of == NULL){
		fprintf(stderr,"\nError to open the file\n");
		exit(1);
	}

	printf("PRESS CTRL+D to give the EOF \n");
	printf("Enter names of students according to roll numbers: \n");
	while (fgets(str, sizeof(str), stdin))
    	fputs(str,  of); 

    fclose(of);

    FILE *fread;
    if((fread = fopen("6th_in.txt","r")) == NULL){
    	fprintf(stderr,"\nError to open the file\n");
    	exit(1);
    }

    char name[50],temp[50];
    int min = INT,max = 0,numOfNames=0;      

    while(fgets(name,sizeof(name),fread)!= NULL){
      // even though the output works fine wiithout this,just add the character
      if(strchr(name,'\n'))
            name[strlen(name)-1] = '\0';

      // maximum count of characters
	  if(noc(name) > max){
	  	max = noc(name);
	  }

	  // minimum count of characters
	  if(noc(name) < min){
	  	min = noc(name);
	  }
	  numOfNames++; // number of lines names
	}
	
	int go;

	rewind(fread); // makes the file pointer go back to the start of the file
	char names[numOfNames][50];// The 2D array for  sorting


	for(go = 0; go < numOfNames; go++)
		fscanf(fread,"%[^\n]%*c",names[go]); //mind the spaces

	// Sort the names
	for(int k = 0; k < numOfNames; k++){
		for(int j = k+1; j < numOfNames; j++){
			if(strcmp(names[k],names[j]) > 0){
				strcpy(temp,names[k]);
            	strcpy(names[k],names[j]);
            	strcpy(names[j],temp);
			}
		}
	}

	FILE *fout;
	fout = fopen("6th_out.txt","w");
	for(int j = 0; j < numOfNames; j++){
		fprintf(fout, "%s\n",names[j]);
	}

	fprintf(stdout,"Highest num of characters is : %d, Lowest number of characters is : %d\n",max,min);

	fclose(fread);
	return 0;
}