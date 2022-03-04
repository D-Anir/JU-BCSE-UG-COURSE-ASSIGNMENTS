%{ 
#include "a2q1b.tab.h" 
int yyerror(char *s); 
int yylex(); 
%} 

%% 
A {return A;} 
B {return B;} 
\n {return 0;} 
. {return yytext[0];} 
%% 

int yywrap() {return 1;} 
