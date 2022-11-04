#ifndef _DATA_INCLUDED
#define _DATA_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXC 60
typedef struct node node_t;
typedef char *data_t;

int readData ( FILE  *, node_t *);
void writeData ( FILE *, node_t *);

int compare (data_t, data_t);

#endif
