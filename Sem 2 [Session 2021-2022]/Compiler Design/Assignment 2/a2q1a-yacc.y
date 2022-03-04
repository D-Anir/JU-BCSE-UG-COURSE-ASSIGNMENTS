%{ 
    #include <stdio.h> 
    #include <stdlib.h> 
    int yyerror(char *s); 
    int yylex(); 
%} 

%start string 
%token A B 

%% 
string : as bs ; 
as : A 
| as A ; 
bs : B 
| bs B; 
%% 

int yyerror(char *s) { 
    printf("Invalid.\n"); 
    exit(0); 
} 

int main() { 
    yyparse(); 
    printf("Valid.\n");
    return 0; 
} 
