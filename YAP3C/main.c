#include <stdio.h>
#include "SportCompetition.h"
#include "guard.h"
#include <time.h>
#include <stdlib.h>


#define DisplayPlayers()\
while (minWeightTeam->Players != NULL)\
{\
	count++;\
	weight += minWeightTeam->Players->Weight;\
	printf("Name: %s\nLastName = %s\nPatronymic = %s\nWeight = %d\n\n", minWeightTeam->Players->Name, minWeightTeam->Players->LastName, minWeightTeam->Players->Patronymic, minWeightTeam->Players->Weight);\
	minWeightTeam->Players = minWeightTeam->Players->Next;\
}

int main()
{
	/*int teamCount = 3;
	int PlayersPerTeam = 5;
	struct Team* teams = NULL;
	srand(time(NULL));
	for (int i = 0; i < teamCount; i++)
	{
		char str[50];
		printf("Enter teamName: ");
		fgets(str, sizeof(str), stdin);
		teams = CreateTeam(teams, str);
		struct Players* players = NULL;
		for (int j = 0; j < PlayersPerTeam; j++)
		{
			char name[50];
			printf("Enter playerName: ");
			fgets(name, sizeof(name), stdin);
			char sur[50];
			printf("Enter playerSurname: ");
			fgets(sur, sizeof(sur), stdin);
			char patron[50];
			printf("Enter Enter playerPatron: ");
			fgets(patron, sizeof(patron), stdin);
			players = CreatePlayer(players,name,sur,patron,rand(100));
		}
		teams = addPlayers(teams, players);
	}
	teams = NULL;*/
	//work();

	struct Team* teams = NULL;

	teams = CreateTeam(teams, "Team1");
	struct Player* players = NULL;
	players = CreatePlayer(players, "name1", "lastName1", "Patron1", 10);
	players = CreatePlayer(players, "name2", "lastName2", "Patron2", 20);
	players = CreatePlayer(players, "name3", "lastName3", "Patron3", 30);
	teams = addPlayers(teams, players);

	teams = CreateTeam(teams, "Team2");
	struct Player* players2 = NULL;
	players2 = CreatePlayer(players2, "name4", "lastName4", "Patron4", 30);
	players2 = CreatePlayer(players2, "name5", "lastName5", "Patron5", 30);
	players2 = CreatePlayer(players2, "name6", "lastName6", "Patron6", 30);
	teams = addPlayers(teams, players2);

	teams = CreateTeam(teams, "Team3");
	struct Player* players3 = NULL;
	players3 = CreatePlayer(players3, "name41", "lastName42", "Patron44", 10);
	players3 = CreatePlayer(players3, "name52", "lastName52", "Patron54", 10);
	players3 = CreatePlayer(players3, "name63", "lastName62", "Patron65", 10);
	teams = addPlayers(teams, players3);

	teams = CreateTeam(teams, "Team4");
	struct Player* players4 = NULL;
	players4 = CreatePlayer(players4, "name14", "lastName41", "Patron41", 70);
	players4 = CreatePlayer(players4, "name51", "lastName51", "Patron54", 60);
	players4 = CreatePlayer(players4, "name61", "lastName61", "Patron64", 70);
	teams = addPlayers(teams, players4);

	struct Team* minWeightTeam = MinWeight(teams);
	int weight = 0;
	int count = 0;
	DisplayPlayers();

	printf("%s=>%d\n", "Team weight", weight);
	printf("Sredniy ves=>%d", weight / count);
	return 0;
}

