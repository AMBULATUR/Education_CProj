#define _CRT_SECURE_NO_WARNINGS
#include "SportCompetition.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXTEAMNAME 30
struct Player
{
	char* Name;
	char* LastName;
	char* Patronymic;
	int Weight;
	struct Player* Next;
};

struct Team
{
	char* Name;
	struct Player* Players;
	struct Team* Next;
};
//- Ф.И.О.игрока;
//-название команды;
//-вес.
//Вывести название и средний вес самой легкой команды.

struct Team* CreateTeamList()
{
	struct Team* tHead;
	tHead = malloc(sizeof(struct Team));
	return tHead;
}
struct Team* AddTeam(struct Team* head, char* Name)
{
	struct Team* element = malloc(sizeof(struct Team));
	element->Next = head;
	element->Name = Name;
	return element;
}
struct Player* CreatePlayerList()
{
	struct Player* pHead;
	pHead = malloc(sizeof(struct Player));
	return pHead;
}
struct Player* AddPlayer(struct Player* head, char* Name, char* LastName, char* Patronymic, int weight)
{
	struct Player* element;
	element = malloc(sizeof(struct Player));
	element->Next = head;
	element->Name = Name;
	element->LastName = LastName;
	element->Patronymic = Patronymic;
	element->Weight = weight;
	return element;
}

//void list(struct stack* p) {
//	// пока не конец стека
//	while (p != NULL) {
//		printf("%d-->", p->data);
//		// продвижение по списку
//		p = p->next;
//	}
//	printf("\n");
//}