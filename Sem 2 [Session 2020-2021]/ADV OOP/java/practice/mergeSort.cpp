#include<iostream>

using namespace std;

int merge(int arr[], int temp[], int left, int mid, int right){
    int i=left, j=mid, k=left, count=0;
    while(i<=mid-1 && j<=right){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
            count += mid-i;
        }
    }

    while(i <= mid-1)
        temp[k++] = arr[i++];
    while(j <= right)
        temp[k++] = arr[j++];
    
    for(int i=0; i<=right; i++)
        arr[i] = temp[i];

    return count;
}

int mergeS(int arr[], int temp[], int left, int right){
    int count = 0, mid = 0;
    
    if(right>left){
        mid = (left+right)/2;
        
        count += mergeS(arr, temp, left, mid);
        count += mergeS(arr, temp, mid+1, right);
        count += merge(arr, temp, left, mid+1, right);
    }
    return count;
}

int mergeSort(int arr[], int n){
    int temp[n];
    return mergeS(arr, temp, 0, n-1);
}

int main(){
    
    int n;
    cout<<"Enter size: ";
    cin>>n;
    int arr[n];

    cout<<"Enter elements:\n";
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int invCount = mergeSort(arr, n);

    cout<<"Number of Inversions: "<< invCount <<"\n";

    return 0;
    
}