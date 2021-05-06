//implementing 2-D array using array of pointers

#include<stdio.h>
#include<stdlib.h>

int main(){
    int r,c,i,j;
    
    printf("Enter number of rows: ");
    scanf("%d",&r);
    
    printf("Enter number of columns: ");
    scanf("%d",&c);
     
    int* a[r];  //array of pointers
    printf("\nEnter the elements of 2D array:\n");
    for(i=0;i<r;i++){
        a[i]=(int *)malloc(c*sizeof(int)); 
        for(j=0;j<c;j++)
            scanf("%d",*(a+i) + j);
    }
    
    printf("\nThe 2D array looks like this:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++)
            printf("%d ",*(*(a+i) + j));
        printf("\n");    
    }
    
    for(i=0;i<r;i++){  //freeing allocated memory
        free(a[i]);
    }
    
    return 0;
}