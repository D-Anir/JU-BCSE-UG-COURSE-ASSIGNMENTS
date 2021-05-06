//implementing list of students using a structure

#include<stdio.h>

struct student {
    int age;
    char name[100];
};

void readData(struct student l[], int n){  //reads student details
    int i;
    for(i=0;i<n;i++){
        printf("\nEnter Name of Student %d: ",i+1);
        scanf("%s",l[i].name);
        printf("Enter Age of Student %d: ",i+1);
        scanf("%d",&l[i].age);
    }
}

void sortAge(struct student l[], int n){  //sorts students according to age
    struct student t;
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(l[j].age>l[j+1].age){
                t=l[j];
                l[j]=l[j+1];
                l[j+1]=t;
            }
        }
    }
}

void printData(struct student l[], int n){  //prints student details
    int i;
    printf("\nThe data in ascending order of age is as follows:\n");
    printf("NAME\tAGE\n");
    for(i=0;i<n;i++){
        printf("%s\t%d\n",l[i].name,l[i].age);
    }
}

int main(){
    int  n,i;
    printf("Enter number of students: ");
    scanf("%d",&n);
    struct student ar[n];
    readData(ar, n);
    sortAge(ar, n);
    printData(ar, n);
    return 0;
}