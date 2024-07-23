#include <stdio.h>
#include "player.h"
#include <stdlib.h>

int ctr=0,size;

void main()
{
	printf("\n****************Player Management System****************\n");
	
	int choice;
	printf("\nHow many players you want to store : ");
	scanf("%d",&size);
	
	Player* playr = (Player*)malloc(size * sizeof(Player));
	
	//printf("%d",size *sizeof(Player)); 
	hardcodeValues(playr);
	do
	{
		printf("\n1. Add player\n2. Display players\n3. Search Player\n4. Delete player info\n5. Update player info\n6. Sort player\n0. Exit\n\nEnter your choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				{
					if(ctr!=size)
					{
						storeData(playr);
					}
					else
					{
						char ch;
						printf("\nInsufficient memory!!\nWould you like to increase your storage?(y or n)");
						fflush(stdin);
						scanf("%c",&ch);
						if(ch=='y' || ch=='Y')
						{
							playr = increaseMemory(playr);
							storeData(playr);
						}
						else
						{
							printf("\nInsufficient memory!!");
						}
					}	
				}
				break;
			case 2:
				{
					display(playr);
				}
				break;
			case 3:
				{
					if(ctr==0)
					{
						printf("\nNo player found\n");
					}
					else
					{
						int ch;
						printf("\n1. Search by jersey no\n2. Search by name\n\nEnter your choice: ");
						scanf("%d",&ch);
						if(ch==1)
						{
							int jn;
							printf("\nEnter the jersey no you want to search: ");
							scanf("%d",&jn);
							int index = searchByJerseyNo(playr,jn);
							if(index==-1)
							{
								printf("\nPlayer not found\n");
							}
							else
							{
								display1(playr[index]);
							}
						}
						else if(ch==2)
						{
							char name[20];
							printf("\nEnter the name you want to search: ");
							fflush(stdin);
							gets(name);
							int index = searchByName(playr,name);
							if(index==-1)
							{
								printf("\nPlayer not found\n");
							}
							else
							{
								display1(playr[index]);
							}
						}
					}
				}
				break;
			case 4:
				{
					int jn;
					printf("\nEnter the jersey no you want to delete: ");
					scanf("%d",&jn);
					int index = searchByJerseyNo(playr,jn);
					if(index==-1)
					{
						printf("\nPlayer not found\n");
					}
					else
					{
						deletePlayr(playr,index);
						printf("\nPlayer info deleted successfully\n");
					}
				}
				break;
			case 5:
				{
					int jn;
					printf("\nEnter the jersey no: ");
					scanf("%d",&jn);
					int index = searchByJerseyNo(playr,jn);
					if(index==-1)
					{
						printf("\nPlayer not found\n");
					}
					else
					{
						updateInfo(playr,index);
						printf("\nPlayer info updated successfully\n");
					}
				}
				break;
			case 6:
				{
					printf("\n1. Sort player by runs\n2. Sort player by wickets\n3. Sort player by matches\n\nEnter your choice: ");
					int ch;
					scanf("%d",&ch);
					if(ch==1)
					{
						sortByRuns(playr);
					}
					else if(ch==2)
					{
						sortByWickets(playr);
					}
					else if(ch==3)
					{
						sortByMatches(playr);
					}
				}
				break;
			case 0:
				{
					printf("\nThank You!!\n");
				}
				break;
			default:
				printf("\nInvalid Input!!\n");
		}	
	}while(choice!=0);		
}