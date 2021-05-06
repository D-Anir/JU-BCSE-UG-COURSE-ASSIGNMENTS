//printing an integer using pointer and pointer to ponter

#include<stdio.h>

int main(){
    int x;
    printf("Enter an integer: ");
    scanf("%d",&x);
    int *pt1; 
    pt1=&x; //pointer to an integer
    int **pt2; 
    pt2=&pt1;  //pointer to pointer
    printf("Value of x from pointer: %d\n",*pt1);
    printf("Value of x from pointer to pointer: %d\n",*(*pt2));
    return 0;
}