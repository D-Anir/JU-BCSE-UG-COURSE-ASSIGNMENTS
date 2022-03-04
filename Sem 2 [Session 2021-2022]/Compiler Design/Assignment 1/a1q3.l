%{
    #include<stdio.h>
    int wordcnt = 0;
%}

%%

[aeiouAEIOU][a-zA-Z0-9]+ {wordcnt++;}
[a-zA-Z0-9]*                    ;
.                               ;

%%

int yywrap(void)
{
    return 1;
}

int main(int argc, char*argv[])
{
    yyin=fopen(argv[1],"r");
    yylex();
    printf("Number of words starting with vowels: %d.", wordcnt);
    return 0;
}