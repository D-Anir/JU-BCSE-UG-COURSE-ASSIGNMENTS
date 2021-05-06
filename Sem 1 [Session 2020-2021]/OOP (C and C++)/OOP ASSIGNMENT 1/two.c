//implementing 1-D array using single pointer

#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,i;
    printf("Enter array size: ");
    scanf("%d",&n);

    int *a;
    a=(int *)malloc(n*sizeof(int)); //dynamically allocated 1d array
    
    printf("Enter the values in array:\n");
    for(i=0;i<n;i++){
        scanf("%d",a+i);
    }
    
    printf("The 1-D array looks like:\n");
    for(i=0;i<n;i++){
        printf("%d ",*(a+i));
    }
    printf("\n");
    
    free(a); //freeing allocated memory
    return 0;
}