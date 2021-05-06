#include<stdio.h>
#include<stdlib.h>


void swap(int* xp, int* yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
    for (i = 0; i < n - 1; i++) { 
  
        min_idx = i; 
        for (j = i + 1; j < n; j++) 
            if (arr[j] < arr[min_idx]) 
                min_idx = j; 

        swap(&arr[min_idx], &arr[i]); 
    } 
}


void slidingWindowMax(int *a, int n, int k){
    int max=0, i, j;
    printf("The maximums for each sliding window of length '%d' is: ", k);
    for(i=0;i<=n-k;i++){
        max=a[i];
        for(j=1;j<k;j++){
            if(a[i+j]>max)
                max=a[i+j];
        }
        printf("%d ", max);
    }
    printf("\n");
}

void slidingWindowMin(int *a, int n, int k){
    int min=0, i, j;
    printf("The minimums for each sliding window of length '%d' is: ", k);
    for(i=0;i<=n-k;i++){
        min=a[i];
        for(j=1;j<k;j++){
            if(a[i+j]<min)
                min=a[i+j];
        }
        printf("%d ", min);
    }
    printf("\n");
}


void slidingWindowAvg(int *a, int n, int k){
    int sum=0, i, j;
    printf("The averages for each sliding window of length '%d' is: ", k);
    for(i=0;i<=n-k;i++){
        sum=0;
        for(j=1;j<k;j++){
            sum = sum + a[i+j];
        }
        printf("%lf ", (float)sum/k);
    }
    printf("\n");
}

void slidingWindowMedian(int *a, int n, int k){
    int temp=0, i, j;
    printf("The medians for each sliding window of length '%d' is: ", k);
    for(i=0;i<=n-k;i++){
        temp=0;
        for(j=1;j<k;j++){
            if(j==k/2)
                temp=a[j];
        }
        printf("%d ", temp);
    }
    printf("\n");
}


int main(){
    int n,k,i;
    printf("Enter array length: ");
    scanf("%d", &n);

    int *a;
    a=(int *)malloc(n*sizeof(int));
    printf("Enter array elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",a+i);
    }

    printf("Ente Sliding Window length: ");
    scanf("%d",&k);
    printf("\n");

    slidingWindowMax(a, n, k);
    slidingWindowMin(a, n, k);
    slidingWindowAvg(a, n, k);

    selectionSort(a, n);
    slidingWindowMedian(a, n, k);
    
    return 0;
}