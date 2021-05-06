//implementing 2-D array using pointer to array and functions

#include<stdlib.h>
#include<stdio.h>

#define MAX_COL 10000

void dimension(int *r, int *c, int C){
    scanf("%d %d",r,c);
    if(*c > C){
        printf("COLUMN NUMBER IS RESTRICTED TO %d !!!\n",C);
        exit(1);
    }
}

int (*allocate(int r))[MAX_COL]{  //dynamic allocation
    int (*p)[MAX_COL];
    if((p= (int (*)[MAX_COL])malloc(r*sizeof(int[MAX_COL]))) == NULL ){
        exit(1);
    }
    return p;
}

void acceptvalues(int (*p)[MAX_COL], int r, int c){
    int i,j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++)
            scanf("%d",*(p+i) + j);
    }
}

void printvalues(const int (*p)[MAX_COL], int r, int c){
    int i,j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++)
            printf("%d ",*(*(p+i) + j));
        printf("\n");    
    }
}

int main(){
    int r,c;
    printf("Enter rows and columns respectively:\n");
    dimension(&r,&c,MAX_COL);

    int (*p)[MAX_COL];
    p = allocate(r);

    printf("Enter the array elements:\n");
    acceptvalues(p,r,c);

    printf("The 2-D array looks like:\n");
    printvalues(p,r,c);

    free(p); //freeing allocated memory
    return 0;
}