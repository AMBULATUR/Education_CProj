%option noyywrap yylineno
%{
int lines = 0;
int admin = 0;

%}
%%
\n {
lines++;
}
.*admin {
admin++;
}
%%
 #include <stdio.h>
 #include <stdlib.h>

int main(int argc, char **argv)
{
 yyin = fopen(argv[1], "r");
 yylex();
 int sum = admin/lines*100;
 printf("\nAdmin: %8d | Lines: %8d\n sum:%.6f Percent",admin,lines,(float)admin/lines*100);
 fclose(yyin);
 return 0;
}
