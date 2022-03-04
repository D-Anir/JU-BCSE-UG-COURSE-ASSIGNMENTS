%{
    #include<stdio.h>
    int total_numbers = 0, total_decimals = 0;
%}


%%
[0-9]+\.[0-9]+[ \t\n]       {total_numbers++;}
[0-9]+[ \t\n]+              {total_decimals++;}
.                           ;
%%


int yywrap(void){}

int main(int argc, char* argv[])
{
    yyin=fopen(argv[1],"r");
    yylex();
    printf("Number of Integers: %d\n", total_numbers);
    printf("Number of decimals: %d\n", total_decimals);
    return 0;
}