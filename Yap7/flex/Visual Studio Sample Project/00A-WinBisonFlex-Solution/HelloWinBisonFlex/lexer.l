% option noyywrap

% {
    char* delimeters = ".,?!;:()";
% }

delim[., !? : ; ()]
ws[\t]

% %

{ ws } + fputc(' ', yyout);
({ ws }*) {
    delim
}({ ws }*) {

        for (int i = 0; i < yyleng; ++i)
        {
            char* delimeter = strchr(delimeters, yytext[i]);

            if (delimeter != NULL)
            {
                if (*delimeter == '(')
                {
                    fputc(' ', yyout);
                }

                fputc(*delimeter, yyout);

                if (*delimeter != '(')
                {
                    fputc(' ', yyout);
                }

                break;
            }
        }

    }

    %%