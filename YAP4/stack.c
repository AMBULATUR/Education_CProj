#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Stack
{
	char* Word;
	struct Stack* Next;
};
char* strcpy(char* destination, const char* source)
{
	if (destination == NULL)
		return NULL;
	char* ptr = destination;
	while (*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return ptr;
}
char* reverse(char* s)
{
	char r[1000];
	int end = 0;
	int count = 0;
	int begin = 0;

	while (s[count] != '\0')
		count++;
	end = count - 1;

	for (begin = 0; begin < count; begin++) {
		r[begin] = s[end];
		end--;
	}

	r[begin] = '\0';
	return r;
}
struct Stack* EnterWord(struct Stack* head, char* Word)
{
	struct Stack* element;
	element = malloc(sizeof(struct Stack));
	element->Word = malloc(strlen(Word) + 1);
	Word = reverse(Word);
	strcpy(element->Word, Word);
	element->Next = head;
	return element;
}

int stack()
{
	struct Stack* stack = NULL;
	FILE* file;
	file = fopen("D:\\1.txt", "r");
	char str[20];

	while (fscanf(file, "%s", str) != EOF)
		stack = EnterWord(stack, str);

	FILE* outFile;
	outFile = fopen("D:\\2.txt","w");
	while (stack != NULL)
	{
		fprintf(outFile, "%s\n", stack->Word);
		stack = stack->Next;
	}
}