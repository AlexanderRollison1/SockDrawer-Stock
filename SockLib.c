//Alexander Rollison
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SockLib.h"
#include "DresserLib.h"
#include "DrawerLib.h"
#include "SortLib.h"

void SortMySocks(SockDrawer Dresser[])
{
	int (*functions[])(const void *, const void *) = {DrawerIDCompare, NumberOfSocksCompare, MaxCapacityCompare, SockColorCompare};
	int choice;
	
	printf("\nDo you want to sort by?\n");
	printf("0.   Changed my mind - don't want to sort\n");
	printf("1.   Drawer ID?\n");
	printf("2.   Number of socks in drawer?\n");
	printf("3.   Max capacity of the drawers?\n");
	printf("4.   Sock color?\n");
	
	do
	{
		scanf("%d",&choice);
		getchar();
		
		if(choice < 0 || choice > 4)
		{
			printf("\nchoice must be 1 - 4.\n");
		}
		else if(choice == 0)
		{
			printf("\nYour sock drawer is a mess!\n");
		}
		else
		{
			qsort(Dresser, NumDrawers, sizeof(SockDrawer),(*functions[choice-1]));
		}
	}
	while(choice < 0 || choice > 4);
	
}
void PutAwayMySocks(SockDrawer Dresser[])
{
	int HowMany;
	int ID = GetDrawer(Dresser);
	
	printf("\nHow many socks are put into the drawer?\n");
	scanf("%d",&HowMany);
	getchar();
	if((Dresser[ID].NumberOfSocks + HowMany) > Dresser[ID].MaxDrawerCapacity)
	{
		printf("\n%d socks fit in the drawer and %d socks fell onto the floor\n", Dresser[ID].MaxDrawerCapacity,(Dresser[ID].NumberOfSocks + HowMany) - Dresser[ID].MaxDrawerCapacity);
		Dresser[ID].NumberOfSocks = Dresser[ID].MaxDrawerCapacity;
	}
	else
	{
		Dresser[ID].NumberOfSocks = Dresser[ID].NumberOfSocks + HowMany;
	}
}
void PutOnMySocks(SockDrawer Dresser[])
{
	int HowMany;
	int ID = GetDrawer(Dresser);
	
	printf("\nHow many socks are you getting out?\n");
	scanf("%d", &HowMany);
	getchar();
	if(Dresser[ID].NumberOfSocks < HowMany)
	{
		printf("\nYou don't have that many socks. You only get %d out of the drawer\n", Dresser[ID].NumberOfSocks);
		Dresser[ID].NumberOfSocks = 0;
	}
	else
	{
		Dresser[ID].NumberOfSocks = Dresser[ID].NumberOfSocks - HowMany;
	}
}
