//Alexander Rollison 1001681800
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SockLib.h"
#include "DresserLib.h"
#include "DrawerLib.h"
#include "SortLib.h"

void DisplayMyDresser(SockDrawer Dresser[])
{
	int i= 0;
	
	printf("\n\nMyDresser\n");
	while(i < NumDrawers)
	{
		printf("\nDrawer %d", Dresser[i].DrawerID);
		printf("\n     Contents : %d %s socks",Dresser[i].NumberOfSocks,Dresser[i].SockColor);
		printf("\n     Capacity : %d socks",Dresser[i].MaxDrawerCapacity);
		++i;
	}
	printf("\n");
}
