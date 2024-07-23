#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void storeData(Player* playr)
{
	Player p;
	printf("\nEnter the jersey no: ");
	scanf("%d",&p.jerseyNo);
	
	for(int i=0;i<ctr;i++)
	{
		if(playr[i].jerseyNo==p.jerseyNo)
		{
			printf("\nPlayer already exists with same jersey number\n");
			return;
		}
	}
	
	fflush(stdin);
	printf("\nEnter the name: ");
	gets(p.name);
	
	printf("\nEnter the no of runs: ");
	scanf("%d",&p.runs);
	
	printf("\nEnter the no of wickets: ");
	scanf("%d",&p.wickets);
	
	printf("\nEnter the no of matches played: ");
	scanf("%d",&p.matches);
	
	playr[ctr++] = p ;
	printf("\nPlayer added successfully\n");
}

void hardcodeValues(Player* playr)
{
	Player p;
	p.jerseyNo=10;
	strcpy(p.name,"Sachin Tendulkar");
	p.runs=800;
	p.wickets=20;
	p.matches=500;
	playr[ctr++] = p ;	
	
	p.jerseyNo=8;
	strcpy(p.name,"Ravindra Jadeja");
	p.runs=400;
	p.wickets=15;
	p.matches=180;
	playr[ctr++] = p ;
	
	p.jerseyNo=77;
	strcpy(p.name,"Shubhman Gill");
	p.runs=500;
	p.wickets=10;
	p.matches=150;
	playr[ctr++] = p ;
}

Player* increaseMemory(Player* playr)
{
	int n = 5;
	size = size + n;
	playr = (Player*)realloc(playr,size * sizeof(Player));
	return playr;
}

void display(Player* playr)
{
	printf("\n|------------------------------------------------------------------------------------|");
	printf("\n|   Jersey No   |         Name         |   Runs   |   Wickets   |   Matches played   |");
	printf("\n|------------------------------------------------------------------------------------|");
	for(int i=0;i<ctr;i++)
	{
		printf("\n|   %9d   |   %16s   |   %4d   |   %7d   |   %14d   |",playr[i].jerseyNo,playr[i].name,playr[i].runs,playr[i].wickets,playr[i].matches);
	}
	printf("\n|------------------------------------------------------------------------------------|\n");
}

int searchByJerseyNo(Player* playr,int jn)
{
	for(int i=0;i<ctr;i++)
	{
		if(playr[i].jerseyNo==jn)
		{
			return i;
		}
	}
	return -1;
}

int searchByName(Player* playr,char* name)
{
	for(int i=0;i<ctr;i++)
	{
		if(strncasecmp(playr[i].name,name,strlen(name))==0)
		{
			return i;
		}
	}
	return -1;
}

void display1(Player p)
{
	printf("\n|------------------------------------------------------------------------------------|");
	printf("\n|   Jersey No   |         Name         |   Runs   |   Wickets   |   Matches played   |");
	printf("\n|------------------------------------------------------------------------------------|");
	printf("\n|   %9d   |   %16s   |   %4d   |   %7d   |   %14d   |",p.jerseyNo,p.name,p.runs,p.wickets,p.matches);
	printf("\n|------------------------------------------------------------------------------------|\n");
}

void deletePlayr(Player* playr,int index)
{
	for(int i=index;i<ctr-1;i++)
	{
		playr[i] = playr[i+1];
	}
	ctr--;
}

void updateInfo(Player* playr,int index)
{
	int r,w,m;
	printf("\nEnter current no of runs you want to add to previous: ");
	scanf("%d",&r);
	playr[index].runs = playr[index].runs + r;
	
	printf("\nEnter current no of wickets you want to add to previous: ");
	scanf("%d",&w);
	playr[index].wickets = playr[index].wickets + w;
	
	printf("\nEnter current no of matches you want to add to previous: ");
	scanf("%d",&m);
	playr[index].matches = playr[index].matches + m;
}

void sortByRuns(Player* playr)
{
	int ch;
	printf("\n1. Ascending Order \n2. Descending order\n\nEnter your choice: ");
	scanf("%d",&ch);
	if(ch==1)
	{
		for(int i=0;i<ctr;i++)
		{
			for(int j=i+1;j<ctr;j++)
			if(playr[i].runs > playr[j].runs)
			{
				Player temp = playr[i];
				playr[i] = playr[j];
				playr[j] = temp;
			}
		}
		display(playr);
	}
	else if(ch==2)
	{
		for(int i=0;i<ctr;i++)
		{
			for(int j=i+1;j<ctr;j++)
			if(playr[i].runs < playr[j].runs)
			{
				Player temp = playr[i];
				playr[i] = playr[j];
				playr[j] = temp;
			}
		}
		display(playr);
	}
	else 
	{
		printf("\nInvalid choice!!\n");
	}	
}

void sortByWickets(Player* playr)
{
	int ch;
	printf("\n1. Ascending Order \n2. Descending order\n\nEnter your choice: ");
	scanf("%d",&ch);
	if(ch==1)
	{
		for(int i=0;i<ctr;i++)
		{
			for(int j=i+1;j<ctr;j++)
			if(playr[i].wickets > playr[j].wickets)
			{
				Player temp = playr[i];
				playr[i] = playr[j];
				playr[j] = temp;
			}
		}
		display(playr);
	}
	else if(ch==2)
	{
		for(int i=0;i<ctr;i++)
		{
			for(int j=i+1;j<ctr;j++)
			if(playr[i].wickets < playr[j].wickets)
			{
				Player temp = playr[i];
				playr[i] = playr[j];
				playr[j] = temp;
			}
		}
		display(playr);
	}
	else 
	{
		printf("\nInvalid choice!!\n");
	}	
}

void sortByMatches(Player* playr)
{
	int ch;
	printf("\n1. Ascending Order \n2. Descending order\n\nEnter your choice: ");
	scanf("%d",&ch);
	if(ch==1)
	{
		for(int i=0;i<ctr;i++)
		{
			for(int j=i+1;j<ctr;j++)
			if(playr[i].matches > playr[j].matches)
			{
				Player temp = playr[i];
				playr[i] = playr[j];
				playr[j] = temp;
			}
		}
		display(playr);
	}
	else if(ch==2)
	{
		for(int i=0;i<ctr;i++)
		{
			for(int j=i+1;j<ctr;j++)
			if(playr[i].matches < playr[j].matches)
			{
				Player temp = playr[i];
				playr[i] = playr[j];
				playr[j] = temp;
			}
		}
		display(playr);
	}
	else 
	{
		printf("\nInvalid choice!!\n");
	}	
}