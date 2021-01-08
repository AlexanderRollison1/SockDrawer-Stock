//Alexander Rollison 1001681800
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SockLib.h"
#include "DresserLib.h"
#include "DrawerLib.h"
#include "SortLib.h"

int DrawerIDCompare(const void * a, const void * b)
{
	return((((SockDrawer*)a)->DrawerID) > (((SockDrawer*)b)->DrawerID));
}
int NumberOfSocksCompare(const void * a, const void * b)
{
	return((((SockDrawer*)a)->NumberOfSocks) > (((SockDrawer*)b)->NumberOfSocks));
}
int MaxCapacityCompare(const void * a, const void * b)
{
	return((((SockDrawer*)a)->MaxDrawerCapacity) > (((SockDrawer*)a)->MaxDrawerCapacity));
}
int SockColorCompare(const void * a, const void * b)
{
	return(strcmp((((SockDrawer*)a)->SockColor),  (((SockDrawer*)b)->SockColor)));
}
