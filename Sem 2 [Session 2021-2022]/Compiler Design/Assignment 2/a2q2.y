%{ 
    #include <stdio.h> 
    #include <stdlib.h> 
    int yylex(void); 
    int yyerror(char *); 
%}

%start Expression 
%union {float num;} 
%token <num> NUMBER 
%type <num> Expression E 
%left '+' '-' 
%left '*' 
%left '&' '|' 
%left '(' ')' 

%% 
Expression: E {printf("Result = %f\n", $$); return 0;}; E: E '+' E {$$ = $1 + $3;} 
| E '-' E {$$ = $1 - $3;} 
| E '*' E {$$ = $1 * $3;} 
| E '&' E {$$ = (int)($1) & (int)($3);} 
| E '|' E {$$ = (int)($1) | (int)($3);} 
| '-' E {$$ = -$2;} 
| '(' E ')' {$$ = $2;} 
| NUMBER {$$ = $1;} 
; 
%% 

int main() { 
    yyparse(); 
    return 0; 
} 

int yyerror(char* s){ 
    printf("Invalid expression.\n"); 
    exit(0); 
}
