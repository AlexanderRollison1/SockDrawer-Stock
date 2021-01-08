//Alexander Rollison 1001681800
#ifndef SockLib_H
#define SockLib_H

#define MAX_DRAWERS 10

typedef struct
{
int DrawerID;
int NumberOfSocks;
char SockColor[40];
int MaxDrawerCapacity;
}
SockDrawer;


void SortMySocks(SockDrawer Dresser[]);
void PutAwayMySocks(SockDrawer Dresser[]);
void PutOnMySocks(SockDrawer Dresser[]);

#endif


