%{ 
#include <stdio.h> 
%}

%% 
\n {return 0;} 
[A]+[B]+ {return 1;} 
. {;} 
%% 

int yywrap() {}
 
int main() { 
    int ok = yylex(); 
    if (ok) { 
    printf("Valid.\n"); 
    } else { 
    printf("Invalid.\n"); 
    } 
    return 0; 
} 
