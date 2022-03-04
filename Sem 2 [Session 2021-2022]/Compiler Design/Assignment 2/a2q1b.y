%{ 
    #include <stdio.h> 
    #include <stdlib.h> 
    int yyerror(char *s); int yylex(); 
%} 

%start string 
%token A B 

%% 
string : A string B | A B ; 
%% 

int yyerror(char *s) {
    printf("Invalid.\n");
    exit(0);
} 

int main() { 
    yyparse(); 
    printf("Valid.\n"); return 0; 
} 
