int sorted_a(int *a, int n){
    if(n==0 || n==1)
        return 1;
    int i;
    for(i=1;i<n;i++)
        if(a[i-1]>a[i])
            return 0;
    return 1;
}

int sorted_d(int *a, int n){
    if(n==0 || n==1)
        return 1;
    int i;
    for(i=1;i<n;i++)
        if(a[i-1]<a[i])
            return 0;
    return 1;
}