#include<stdio.h>
#include<stdlib.h>

void allo(int ***p, int r, int c){
    int i;
    *p = (int **)malloc(r*sizeof(int*));
    for(i=0;i<r;i++)
        *(p[i]) = (int*)malloc(c*sizeof(int));
}

int main(){
    int *p1, (*p2)[5];
    int x[5] = {1,2,3,4,5};
    p1 = x;
    p2 = &x;
    printf("%ld %lu\n", sizeof(*p1), sizeof(*p2));
    return 0;
}