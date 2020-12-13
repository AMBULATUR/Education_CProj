#include "SportCompetition.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXTEAMNAME 30

//- Ф.И.О.игрока;
//-название команды;
//-вес.
//Вывести название и средний вес самой легкой команды.


struct Team* CreateTeam(struct Team* head, char* Name)
{
	struct Team* element;
	element = (struct Team*)malloc(sizeof(struct Team));
	element->Next = head;
	element->Name = Name;
	return element;
}

struct Player* CreatePlayer(struct Player* head, char* Name, char* LastName, char* Patronymic, int weight)
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
struct Team* addPlayers(struct Team* team, struct Player* player)
{
	team->Players = player;
	return team;
}
struct Team* MinWeight(struct Team* team)
{
	struct Team* min = team;
	int minWeight = -1;

	if (team != NULL)
	{
		while (team != NULL)
		{
			int teamWeight = 0;
			struct Player* firstPlayer = team->Players;
			while (team->Players != NULL)
			{
				teamWeight += team->Players->Weight;
				team->Players = team->Players->Next;
			}

			if (teamWeight < minWeight || minWeight == -1)
			{
				team->Players = firstPlayer;
				min = team;
				minWeight = teamWeight;
			}
			team = team->Next;
		}
	}
	return min;
}
