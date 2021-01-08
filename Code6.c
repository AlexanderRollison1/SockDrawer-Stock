//Alexander Rollison

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SockLib.h"
#include "DresserLib.h"
#include "DrawerLib.h"
#include "SortLib.h"

int main(void)
{
	int choice;
	enum SockAction
	{
		RemoveSocks = 1, AddSocks, DisplayDresser, SortSocks
	};
	
	SockDrawer Dresser[MAX_DRAWERS];
	GetNumDrawers();
	
	int i = 0;
	while(i < NumDrawers)
	{
		Dresser[i].DrawerID = i+1;
		printf("\nHow many socks will fit in the drawer %d?\n", Dresser[i].DrawerID);
		CreateDrawer(&Dresser[i]);
		i++;
	}
	
	do
	{
		printf("\nWhat do you need to do?\n");
		printf("0.   Don't have socks!!\n");
		printf("1.   Take socks out of a drawer?\n");
		printf("2.   Put more socks in a drawer?\n");
		printf("3.   Display dresser\n");
		printf("4.   Sort Socks\n");
		scanf("%d", &choice);
		getchar();
		
		switch (choice)
		{
			case 0:
				printf("\nTime to do laundry\n");
				break;
			case RemoveSocks:
				PutOnMySocks(Dresser);
				DisplayMyDresser(Dresser);
				break;
			
			case AddSocks:
				PutAwayMySocks(Dresser);
				DisplayMyDresser(Dresser);
				break;
			
			case DisplayDresser:
				DisplayMyDresser(Dresser);
				break;
			
			case SortSocks:
				SortMySocks(Dresser);
				DisplayMyDresser(Dresser);
				break;
				
			default:
				printf("\nPlease enter another value\n");
		}
	}
	while(choice != 0);
	
	return 0;
}


