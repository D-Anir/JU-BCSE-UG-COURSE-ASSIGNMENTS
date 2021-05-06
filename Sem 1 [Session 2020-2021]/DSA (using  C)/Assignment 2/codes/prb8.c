#include<stdio.h>
#include<stdlib.h>

int sorted_a(int *a, int n){
    if(n==0 || n==1)
        return 1;
    int i;
    for(i=1;i<n;i++){
        if(a[i-1]>a[i])
            return 0;
    }
    return 1;
}

int sorted_d(int *a, int n){
    if(n==0 || n==1)
        return 1;
    int i;
    for(i=1;i<n;i++){
        if(a[i-1]<a[i])
            return 0;
    }
    return 1;
}


int main(){
    
    int n,i;
    printf("Enter Array Length: ");
    scanf("%d",&n);
    
    if(n==0 ||n==1){
        printf("ALREADY SORTED! (NO DEFINITE ORDER)");
        exit(0);
    }

    int *a;
    a=(int *)malloc(n*sizeof(int));
    printf("Enter array elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",a+i);
    }

    if(sorted_a(a,n))
        printf("SORTED IN ASSCENDING ORDER.\n");
    else if(sorted_d(a,n))
        printf("SORTED IN DESCENDING ORDER.\n");
    else
        printf("The array is not sorted in any order!\n");

    return 0;
}