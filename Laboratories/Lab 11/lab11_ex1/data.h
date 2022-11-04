#ifndef _DATA_INCLUDED
#define _DATA_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXC 60

typedef struct item Item;

int readData (FILE *, Item*);
void writeData (FILE *, Item);
int compare (Item, Item);

#endif
