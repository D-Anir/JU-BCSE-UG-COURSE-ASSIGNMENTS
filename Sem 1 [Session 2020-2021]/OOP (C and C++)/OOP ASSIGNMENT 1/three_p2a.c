//implementing 2-D array using pointer to array

#include<stdio.h>
#include<stdlib.h>

int main(){
    int r,c,i,j;
    printf("Enter number of rows: ");
    scanf("%d",&r);
    printf("Enter number of columns: ");
    scanf("%d",&c);
    
    
    int (*p)[c]; //pointer to array
    p=(int (*)[])malloc(r*sizeof(int [c]));

    printf("\nEnter the elements of 2D array:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++)
            scanf("%d",*(p+i) + j);
    }
    
    printf("\nThe 2D array looks like this:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++)
            printf("%d ",*(*(p+i) + j));
        printf("\n");    
    }
    free(p);   //freeing allocated memory
    return 0;
}