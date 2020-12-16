#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef enum State {
	state1, // wait quote
	state2, // write quote, wait quote or any symbol instead quote
	state3, // write quote, wait quote on EOS
	state4, // write quote, wait quote or any symbol instead quote
	state5, // write symbol, wait quote or any symbol instead quote
} State;

typedef enum Signals {
	symbol,
	quote,
	Unknown,
} Signal;

enum Signals table[5][3] = {
	[state1] [Unknown] = state1,
	[state1][quote] = state2,

	[state2][quote] = state3,
	[state2][symbol] = state5,

	//[state3][quote] = state3, //end

	[state3][quote] = state4,

	[state4][quote] = state3,
	[state4][symbol] = state5,

	[state5][symbol] = state5,
	[state5][quote] = state3,

};

Signal GetCharTypeState(char c) {
	Signal type = symbol;
	if (c == NULL)
		Unknown;
	else if (c == '\'') {
		type = quote;
	}
	return type;
}

void CheckString(const char* str)
{
	char* substr = (char*)malloc(strlen(str));

	for (int i = 0; i < strlen(str); ++i)
	{
		State state = state1;
		substr[0] = '\0';

		for (int j = i; j < strlen(str); ++j) {
			state = table[state][GetCharTypeState(str[j])];

			if (state == state1) {//Multi line
				if (substr[0] != '\0' /*&& substr[1] != '\''*/)
				{
					//printf("%s\n", substr);
					i = j - 1;
				}
				break;
			}

			if (state == state3) {
				strncpy(substr, str + i, j - i + 1);
				substr[j - i + 1] = '\0';

				if (j + 1 == strlen(str))
				{
					printf("%s\n", substr);
				}
			}

		}

	}
}

int main()
{

	//Строковый литерал языка Pascal(апостроф записывается, как два апострофа подряд).
		// Примеры корректных строк:	
		// 'Hello, world!'
		// 'I don''t know.'


	//Примеры из докумнта:
	CheckString("'Hello, world!'");			//TRUE
	CheckString("'I don''t know.'");			//TRUE
	//END

	//Вольные примеры, Quote экранирован.
	CheckString("'hello world'");			// Quote Слева, Quote справа	TRUE
	CheckString("\'hello \'\'world\'");		// Quote в начале, double quote в середине, Quote в конце	TRUE

	CheckString("quote");					// Без Quote					FALSE
	CheckString("\'quote");					// Quote первым символом		FALSE
	CheckString("quote\'");					// Quote в конце				FALSE
	CheckString("\'quote\'");				// Quote с двух сторон			TRUE

}

