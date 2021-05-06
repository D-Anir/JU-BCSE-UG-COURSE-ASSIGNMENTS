#include<stdio.h>

typedef struct{
    int score;
    char name[31];
}student;


int main(){
    FILE *ptr;
    int n,i;
    printf("Enter number of students: ");
    scanf("%d",&n);
    ptr=fopen("hello.txt","w");
    student ar;
    for(i=0;i<n;i++){
        printf("Enter name of student %d: ",i+1);
        scanf("%s", ar.name);
        printf("Enter score of student %d: ",i+1);
        scanf("%d", &ar.score);
        fwrite(&ar, sizeof(ar), 1, ptr);
    }
    printf("\nMAXIMUM SCORE FROM THE LIST IS: ");
    fclose(ptr);
    int max=0;
    ptr=fopen("hello.txt","r");
    while(fread(&ar,sizeof(ar),1,ptr)){
        if(max<ar.score)
            max=ar.score;
    }
    printf("%d\n",max);
    fclose(ptr);
    return 0;
}