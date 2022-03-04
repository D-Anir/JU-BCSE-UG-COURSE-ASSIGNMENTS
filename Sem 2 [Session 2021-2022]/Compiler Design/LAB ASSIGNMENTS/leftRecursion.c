#include<stdio.h>
#include<string.h>

#define size 100

int menu(){
    int choice;
    printf("Detect and Remove:\n1. Indirect Left Recursion.\n2. Direct Left Recursion.\nEnter Your Choice: ");
    scanf("%d", &choice);
    return choice;
}

void indirect() {

}

void direct() {
    char non_terminal;  
    char beta,alpha;  
    int num;  
    char production[size][size];  

    /*starting of the string following "->"*/  
    int index=3; 
    printf("Enter Number of Productions : ");  
    scanf("%d",&num);  
    printf("Enter the grammar as E->E-A (without any space):\n");  
    for(int i=0;i<num;i++){  
        scanf("%s",production[i]);  
    }  
    for(int i=0;i<num;i++){  
        printf("\nGRAMMAR : %s",production[i]);  
        non_terminal = production[i][0];  
        if(non_terminal == production[i][index]) {  
            alpha = production[i][index+1];  
            printf(" is left recursive.\n");  
            while(production[i][index]!=0 && production[i][index]!='|')  
                index++;  
            if(production[i][index]!=0) {  
                beta=production[i][index+1];  
                printf("Grammar after removing left recursion:\n");  
                printf("%c->%c%c\'",non_terminal,beta,non_terminal);  
                printf("\n%c\'->%c%c\'|$\n",non_terminal,alpha,non_terminal);  
            }  
            else  
                printf("Grammer in invalid, can't be reduced.\n");  
        }  
        else  
            printf(" is not left recursive.\n");  
        index=3;  
    }  
}

int main(){
    int wish;
    while(1){
        int choice = menu();
        if(choice == 1){
            indirect();
        } else {
            direct();
        }
        printf(" Wish to continue ? Press 1 : Press 0\n");
        scanf("%d", wish);
        if(wish != 1){
            exit(0);
        }
    }
    
    return 0;
}