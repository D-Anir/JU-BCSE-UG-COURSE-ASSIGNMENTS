//working with files in c

#include<stdlib.h>
#include<stdio.h>

int i;

struct student {  //structure to store student details
    int roll;
    char name[31];
    int score[5];
}stu;

int isavailable(int r){ //to check if roll is available
    FILE *ptr3;
    ptr3 = fopen("students.txt","r");
    while(!feof(ptr3)){
        fread(&stu, sizeof(stu), 1, ptr3);
        if(r==stu.roll){
            fclose(ptr3);
            return 1;
        }
    }
    fclose(ptr3);
    return 0;
}


void insert(){  //to accept student details and write to the file
    FILE *ptr1;
    ptr1 = fopen("students.txt","a");
    printf("Enter Roll no: ");
    scanf("%d", &stu.roll);
    if(isavailable(stu.roll)){
        printf("Roll already exists! If want to modify press 4.\n");
        return;
    }
    printf("Enter the Name: ");
    scanf("%s", stu.name);
    printf("Enter score in 5 subjects:\n");
    for(i=0;i<5;i++)
        scanf("%d",&stu.score[i]);

    fwrite(&stu, sizeof(stu), 1, ptr1);
    fclose(ptr1);
}

void display(){  //to display student details
    FILE *ptr2;
    ptr2 = fopen("students.txt","r");
    printf("\nROLL NO.\tNAME\tSCORE IN 5 SUBS\n\n");
    while(fread(&stu,sizeof(stu),1,ptr2)){
        printf("  %d\t\t%s\t",stu.roll,stu.name);
        for (i=0; i<5; i++)
            printf("%d ",stu.score[i]);
        printf("\n");    
    }
    printf("\n\n");
    fclose(ptr2);    
}


void search(){  //to search and diaplay user-entered student
    FILE *ptr4;
    int r;
    printf("\nENTER ROLL NO. TO BE SEARCHED:\n");
    scanf("%d",&r);
    int avl=isavailable(r);
    if(avl==0){
        printf("ROLL NO. %d IS NOT AVAILABLE IN THE FILE\n\n",r);
    }
    else{
        ptr4=fopen("students.txt","r");
        while(fread(&stu,sizeof(stu),1,ptr4)){
            if(stu.roll == r){
                printf("\nRoll No.: %d\nName: %s\n",stu.roll,stu.name);
                printf("Marks in 5 subs: ");
                for (i=0; i<5; i++)
                    printf("%d ",stu.score[i]);
            }
        }
        printf("\n\n");
        fclose(ptr4);
    }
}

void modify(){ //to modify student details 
    int r;
    FILE *fpo; //for original file
    FILE *fpt; //for temporary file
    printf("\nENTER ROLL NO. TO BE SEARCHED:\n");
    scanf("%d",&r);
    if(isavailable(r)==0){
        printf("ROLL NO. %d IS NOT AVAILABLE IN THE FILE\n",r);
    }
    else{
        fpo = fopen("students.txt","r");
        fpt = fopen("temp.txt","w");
        while(fread(&stu,sizeof(stu),1,fpo)){
            if(stu.roll!=r)
                fwrite(&stu,sizeof(stu),1,fpt);
            else{
                int ch;
                printf("\n1. Update Name of Roll Number %d", r);
                printf("\n2. Update Marks of Roll Number %d", r);
                printf("\n3. Update both Name and Marks of Roll Number %d", r);
                printf("\nEnter your choice:");
                scanf("%d", &ch);
                switch (ch){
                    case 1:
                        printf("ENTER NEW NAME: ");
                        scanf("%s",stu.name);
                        break;
                    case 2:
                        printf("ENTER NEW MARKS OF 5 SUBS: ");
                        for (i=0; i<5; i++)
                            scanf("%d ",&stu.score[i]);
                        break;
                    case 3:
                        printf("ENTER NEW NAME: ");
                        scanf("%s",stu.name);
                        printf("ENTER NEW MARKS OF 5 SUBS: ");
                        for (i=0; i<5; i++)
                            scanf("%d ",&stu.score[i]);
                        break;
                    default:
                        printf("INVALID CHOICE!!!\n");             
                }
                fwrite(&stu,sizeof(stu),1,fpt);
            }
        }
        fclose(fpo);
        fclose(fpt);
        fpo = fopen("students.txt","w");
        fpt = fopen("temp.txt","r");
        while(fread(&stu,sizeof(stu),1,fpt))
            fwrite(&stu,sizeof(stu),1,fpo);
        fclose(fpo);
        fclose(fpt);
        printf("STUDENT MODIFIED!\n");    
    } 
}


void deldata(){ //to delete student details
    int r;
    FILE *fpo; //for original file
    FILE *fpt; //for temporary file
    printf("\nENTER ROLL NO. TO BE SEARCHED:\n");
    scanf("%d",&r);
    if(isavailable(r)==0){
        printf("ROLL NO. %d IS NOT AVAILABLE IN THE FILE\n",r);
    }
    else{
        fpo = fopen("students.txt","r");
        fpt = fopen("temp.txt","w");
        while(fread(&stu,sizeof(stu),1,fpo)){
            if(stu.roll!=r)
                fwrite(&stu,sizeof(stu),1,fpt);
        }
        fclose(fpo);
        fclose(fpt);
        fpo = fopen("students.txt","w");
        fpt = fopen("temp.txt","r");
        while(fread(&stu,sizeof(stu),1,fpt))
            fwrite(&stu,sizeof(stu),1,fpo);
        fclose(fpo);
        fclose(fpt);
        printf("STUDENT DELETED!\n\n");
    }
}

int main(){  //to display menu for the user
    int ch;
    do{
        printf("***STUDENT DATABASE****\n\n");
        printf("1.ADD DATA\n");
        printf("2.DISPLAY DATA\n");
        printf("3.SEARCH DATA\n");
        printf("4.MODIFY DATA\n");
        printf("5.DELETE DATA\n");
        printf("6.EXIT\n");
        printf("\nENTER YOUR CHOICE (1/2/3/4/5/6): ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                    insert();
                    break;
            case 2:
                    display();
                    break;
            case 3:
                    search();
                    break;
            case 4:
                    modify();
                    break;   
            case 5:
                    deldata();
                    break;
            case 6:
                    exit(1);
                    break;
            default:
                    printf("INVALID CHOICE!!!\n");          
        }
    }while(ch!=6);    
    return 0;
}