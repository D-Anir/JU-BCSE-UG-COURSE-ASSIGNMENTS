//implementing 2-D array using array of pointers and functions

#include<stdlib.h>
#include<stdio.h>

void dimension(int *r, int *c){
    scanf("%d %d",r,c);
}

void allocate(int **p, int c){  //dynamic allocation
    *p=(int *)malloc(c*sizeof(int));
}

void acceptvalues(int **p, int r, int c){
    int i,j;
    for(i=0;i<r;i++){
        allocate(&p[i],c);
        for(j=0;j<c;j++)
            scanf("%d",*(p+i) + j);
    }
}

void printvalues(int **p,int r,int c){
    int i,j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++)
            printf("%d ",*(*(p+i) + j));
        printf("\n");    
    }
}

void FREE(int **p, int r){  //free allocated memory
    int i;
    for(i=0;i<r;i++){
        free(p[i]);
    }
}

int main(){
    int r,c;
    printf("Enter row and column number respectivey:\n");
    dimension(&r,&c);

    int* p[r];

    printf("\nEnter the elements of 2D array:\n");
    acceptvalues(p,r,c);

    printf("\nThe 2D array looks like this:\n");
    printvalues(p,r,c);

    FREE(p,r);

    return 0;
}