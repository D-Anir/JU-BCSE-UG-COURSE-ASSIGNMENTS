#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int roll;
    char name[31];
    int marks;
} student;

struct node{
    student s;
    struct node *adr;
};

struct node *root;
struct node* createnode(struct node **);
void addstudent(struct node *, int);
void display();

struct node *createnode(struct node **temp){
    *temp=(struct node*)malloc(sizeof(struct node));
    return *temp;
}

void addstudent(struct node *temp, int i){
    printf("Enter the roll of student %d:\n",i); 
    scanf("%d",&temp->s.roll); 
    printf("Enter the name of student %d:\n",i); 
    scanf("%s",temp->s.name); 
    printf("Enter the marks obtained by student %d:\n",i); 
    scanf("%d",&temp->s.marks);
}

void del() {    
    struct node *ptr=NULL;
    struct node *prev=NULL;
    struct node *current=NULL;
    int roll_no;
    printf("Enter Roll Number to Delete:\n");
    scanf("%d",&roll_no);
    if(root->s.roll == roll_no){
        struct node *tmp;
        if(root == NULL) printf("LIST EMPTY ALREADY!!\n");
        tmp = root;
        root = (root)->adr;
        free(tmp);
    }
    else{
        prev=root;
        current=root;
        while(current->s.roll!=roll_no){
            prev=current;
            current=current->adr;
        }
        prev->adr = current->adr;
        current->adr=NULL;
        free(current);
    }
    printf("Recored Deleted\n\n");
}


void display() 
{ 
    struct node *temp; 
    temp=root;
    printf("ROLL   NAME   MARKS\n"); 
    while(temp) 
    { 
        printf("-> %d  %s  %d " , temp->s.roll, temp->s.name, temp->s.marks); 
        temp=temp->adr; 
    }
    printf("\n"); 
}

int main(){
    int n,i;
    struct node *p;
    printf("ENTER NUMBER OF STUDENTS: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        struct node *temp;
        temp = createnode(&temp);
        addstudent(temp,i+1);
        if(root==NULL){
            root=temp;
            p=temp;
        }
        else{
            p->adr=temp;
            p=temp;
        }
    }
    p->adr=NULL;
    printf("\nTHE LINKED LIST LOOKS LIKE THIS:\n");
    display();
    printf("\nWANT TO DELETE A RECORD? PRESS 1.\n");
    int ch;
    scanf("%d",&ch);
    while(ch==1){
        if(root==NULL){
            printf("LIST EMPTY ALREADY!!\n");
            break;
        }
        del();
        display();
        printf("\nWANT TO DELETE MORE? PRESS 1 TO CONTINUE AND 0 TO STOP!\n");
        scanf("%d",&ch);
    }
    printf("\nFINAL LIST LOOKS LIKE THIS:\n");
    display();
    return 0;
}