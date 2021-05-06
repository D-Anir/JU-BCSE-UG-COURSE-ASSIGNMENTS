#include<stdio.h>
#include<stdlib.h>
#include "isSorted.h"


void mergeTwoArrays(int *a1, int *a2, int *a3, int n1, int n2){
    int i=0, j=0, k=0;
    while(i<n1 && j<n2){
        if(a1[i]<a2[j])
            a3[k++]=a1[i++];
        else
            a3[k++]=a2[j++];
    }
    while(i<n1){
        a3[k++]=a1[i++];
    }
    while(j<n2){
        a3[k++]=a2[j++];
    }
}

int main(){
    int n1,n2,i,j;
    
    printf("Enter length of array 1: ");
    scanf("%d",&n1);
    
    int *a1;
    a1=(int*)malloc(n1*sizeof(int));
    printf("Enter elements of array 1:\n");
    for(i=0;i<n1;i++){
        scanf("%d",a1+i);
    }

    printf("\nEnter length of array 2: ");
    scanf("%d",&n2);
    
    int *a2;
    a2=(int*)malloc(n2*sizeof(int));
    printf("Enter elements of array 2:\n");
    for(i=0;i<n2;i++){
        scanf("%d",a2+i);
    }

    if(sorted_a(a1, n1)==0 || sorted_a(a2, n1)==0){
        printf("\nENTER SORTED ARRAYS!!\n");
        exit(0);
    }

    int *a3;
    a3=(int *)malloc((n1+n2)*sizeof(int));
    mergeTwoArrays(a1,a2,a3,n1,n2);
    printf("\nThe merged array looks like: ");
    for(i=0;i<n1+n2;i++){
        printf("%d ",*(a3+i));
    }
    
    printf("\n");
    return 0;
}