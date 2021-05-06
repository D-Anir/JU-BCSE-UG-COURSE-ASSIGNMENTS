//implementing list of students without a structure 

#include<stdio.h>
#include<string.h>


void readData(char name[][31],int age[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("\nEnter Name of person %d: ",i+1);
        scanf("%s",name[i]);
        printf("Enter Age of person %d: ",i+1);
        scanf("%d",&age[i]);
    }
}

void sortAge(char name[][31],int age[], int n){
    char ar[31];
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(age[j]>age[j+1]){
                temp=age[j];
                age[j]=age[j+1];
                age[j+1]=temp;
                strcpy(ar,name[j]);
                strcpy(name[j],name[j+1]);
                strcpy(name[j+1],ar);
            }
        }
    }
}

void printData(char name[][31],int age[], int n){
    printf("\nThe data in ascending order of age is as follows:\n");
    int i;
    printf("NAME\tAGE\n");
    for(i=0;i<n;i++){
        printf("%s\t%d\n",name[i],age[i]);
    }
}

int main(){
    char name[100][31];
    int age[100];
    int n;
    printf("Enter number of persons: ");
    scanf("%d",&n);
    readData(name,age,n);
    sortAge(name, age, n);
    printData(name, age, n);
    return 0;
}