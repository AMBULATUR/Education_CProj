#include "guard.h"



#ifndef Competition_Header
#define Competition_Header
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

struct Team* CreateTeamList(struct Team* head);
struct Team* CreateTeam(struct Team* head, char* Name);
struct Player* CreatePlayerList();
struct Player* CreatePlayer(struct Player* head, char* Name, char* LastName, char* Patronymic, int weight);
struct Team* addPlayers(struct Team* team, struct Player* player);
struct Team* MinWeight(struct Team* team);
#endif 