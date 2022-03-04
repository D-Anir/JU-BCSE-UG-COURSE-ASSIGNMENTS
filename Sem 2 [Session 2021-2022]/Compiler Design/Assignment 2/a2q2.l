%{ 
    #include <stdio.h> 
    #include "a2q2.tab.h" 
%} 

%% 
[0-9]+(\.[0-9]?[0-9])? {yylval.num = atof(yytext); return NUMBER;}
[ \t] {;} 
[\n] {return 0;} 
. {return yytext[0];} 
%% 

int yywrap() {
    return 1;
} 