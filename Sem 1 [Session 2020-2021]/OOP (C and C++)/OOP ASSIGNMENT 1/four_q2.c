// implementing 1-D array using single pointer and functions

#include<stdio.h>
#include<stdlib.h>

void dimension(int *n){
    scanf("%d",n);
}

void allocate(int **p, int n){  //dynamic allocation
    *p=(int *)malloc(n*sizeof(int));
}

void acceptvalues(int *a, int n){
    int i;
    for(i=0;i<n;i++){
        scanf("%d",a+i);
    }
}

void printvalues(int *a, int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",*(a+i));
    }
    printf("\n");
}

void FREE(int *p){ //freeing allocated memory
    free(p);
}

int main(){
    int n;
    printf("Enter array size: ");
    dimension(&n);
    
    int *p;
    allocate(&p,n);

    printf("Enter the values in array:\n");
    acceptvalues(p,n);
    
    printf("The 1-D array looks like:\n");
    printvalues(p,n);

    FREE(p);
    return 0;
}