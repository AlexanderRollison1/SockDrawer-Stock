//Alexander Rollison 1001681800
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SockLib.h"
#include "DresserLib.h"
#include "DrawerLib.h"
#include "SortLib.h"

int GetDrawer(SockDrawer Dresser[])
{
	int ID;
	do
	{
		printf("\nWhich Drawer do you choose? (%d Drawer(s))\n", NumDrawers);
		scanf("%d", &ID);
		getchar();
		if(ID > NumDrawers && ID < 0)
		{
			printf("\nThat's not one of your drawers!!\nPick again!\n");
		}
	}
	while(ID > NumDrawers || ID < 0);

	int j = 1;
	
	while(j <= NumDrawers)
	{
		if(Dresser[j-1].DrawerID == ID)
		{
			ID = (j-1);
			j = NumDrawers + 1; 
		}
		j++;
	}
	return ID;
}
void GetNumDrawers(void)
{
	do
	{
		printf("\nHow many drawers are in the dresser (1 - %d?) \n", MAX_DRAWERS);
		scanf("%d", &NumDrawers);
		getchar();
	}
	while(NumDrawers > MAX_DRAWERS || NumDrawers <= 0);
}
void CreateDrawer(SockDrawer *DresserPtr)
{
	int HowMany;
	scanf("%d", &DresserPtr->MaxDrawerCapacity);
	getchar();
	
	printf("\nHow many socks are you putting into Drawer %d?\n", DresserPtr->DrawerID);
	scanf("%d", &HowMany);
	getchar();
	if(HowMany > DresserPtr->MaxDrawerCapacity)
	{
		printf("\n%d socks fit in the drawer and %d socks fell onto the floor\n",DresserPtr->MaxDrawerCapacity,(HowMany - DresserPtr->MaxDrawerCapacity));
		DresserPtr->NumberOfSocks = DresserPtr->MaxDrawerCapacity;
	}
	else
	{
		DresserPtr->NumberOfSocks = HowMany;
	}
	
	printf("\nWhat color are the socks in Drawer %d?\n", DresserPtr->DrawerID);
	fgets(DresserPtr->SockColor, 39, stdin);
	DresserPtr->SockColor[strlen(DresserPtr->SockColor)-1] = '\0';
	
}
