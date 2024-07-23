typedef struct Player
{
	int jerseyNo,runs,wickets,matches;
	char name[20];
} Player;

void storeData(Player* );
void hardcodeValues(Player* );
Player* increaseMemory(Player* );
void display(Player* );
int searchByJerseyNo(Player* ,int );
int searchByName(Player* ,char* );
void display1(Player );
void deletePlayr(Player* ,int );
void updateInfo(Player* ,int );
void sortByRuns(Player*);
void sortByWickets(Player*);
void sortByMatches(Player*);

extern int ctr,size;

