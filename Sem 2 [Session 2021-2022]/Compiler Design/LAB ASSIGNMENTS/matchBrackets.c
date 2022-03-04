#define _GNU_SOURCE

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define FILE_CHARS_SIZE 10000
#define WORD_CHARS_SIZE 100
#define bool int

// to store each element of a stack as a pair
struct pair {
    char ch;
    int lineNo;
};

// structure of a stack node
struct sNode {
    struct pair data;
    struct sNode* next;
};

// Function to push an item to stack
void push(struct sNode** top_ref, struct pair newPair);
  
// Function to pop an item from stack
struct pair pop(struct sNode** top_ref);

// Returns 1 if character1 and character2 are matching left
// and right Brackets
bool isMatchingPair(char character1, char character2)
{
    if (character1 == '(' && character2 == ')')
        return 1;
    else if (character1 == '{' && character2 == '}')
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    else
        return 0;
}

// Function to push an item to stack
void push(struct sNode** top_ref, struct pair newPair)
{
    // allocate node
    struct sNode* new_node
        = (struct sNode*)malloc(sizeof(struct sNode));
  
    if (new_node == NULL) {
        printf("Stack overflow n");
        getchar();
        exit(0);
    }
  
    // put in the data
    new_node->data = newPair;
  
    // link the old list off the new node
    new_node->next = (*top_ref);
  
    // move the head to point to the new node
    (*top_ref) = new_node;
}

// Function to pop an item from stack
struct pair pop(struct sNode** top_ref)
{
    struct pair res;
    struct sNode* top;
  
    // If stack is empty then error
    if (*top_ref == NULL) {
        printf("Stack overflow n");
        getchar();
        exit(0);
    }
    else {
        top = *top_ref;
        res = top->data;
        *top_ref = top->next;
        free(top);
        return res;
    }
}

int is_balanced(FILE *file){
    // printf("hello\n");
    // char * line = NULL;
    // size_t len = 0;
    // size_t read;

    char * buffer = 0;
    long length;

    if (file)
    {
        fseek (file, 0, SEEK_END);
        length = ftell (file);
        fseek (file, 0, SEEK_SET);
        buffer = malloc (length);
        if (buffer)
        {
            fread (buffer, 1, length, file);
        }
    }

    int lineNo = 1;
    
    if(buffer){
        // printf("%s", buffer);
        struct sNode* stack = NULL;

        int i = 0;
        // printf("hello\n");
        while (buffer[i]) {
            // printf("hello\n");
            // printf("%s", line);
            if(buffer[i] == '\n'){
                lineNo++;
            }
            
            struct pair newPair;
            newPair.ch = buffer[i];
            newPair.lineNo = lineNo;

            if (buffer[i] == '{' || buffer[i] == '(' || buffer[i] == '['){
                push(&stack, newPair);
            }
                
            if (buffer[i] == '}' || buffer[i] == ')' || buffer[i] == ']') {
                if (stack == NULL){
                    // printf("line 121\n");
                    printf("Line No.: %d\n", newPair.lineNo);
                    return 0;
                }
                else if (!isMatchingPair(pop(&stack).ch, newPair.ch)){
                    //  printf("line 126\n");
                    printf("Line No.: %d\n", newPair.lineNo);
                    return 0;
                }
            }
            i++;
        }

        if(stack == NULL){
            return 1;
        } else {
            //  printf("line 137\n");
            printf("Line No.: %d\n", stack->data.lineNo);
            return 0;
        }
    }
}

int main(){
    // printf("hello\n");
    FILE *file = fopen("file.txt", "r");
    if(file == NULL){
        printf("Error!! File Does Not Exists..");
        exit(-1);
    }
    // printf("hello\n");
    // printf("hello\n");

    if(is_balanced(file)){
        printf("The Code Fragment is balanced.\n");
    } else {
        printf("The Code Fragment is not balanced.\n");
    }
    fclose(file);

    return 0;
}