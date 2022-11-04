#ifndef _DATO_INCLUDED
#define _DATO_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXST 10

typedef struct item* Item;
typedef char* Key;
//typedef struct node node_t;
//typedef struct data data_t;

Item ITEMscan();
void ITEMshow(Item data, FILE* fp);
int ITEMcheckvoid(Item data);
Item ITEMsetvoid();
Key KEYscan();
int KEYcompare(Key k1, Key k2);
Key KEYget(Item data);
char *getField2I (Item dat);
int getField3I (Item dat);
int getField4I (Item dat);

Item ITEMset(char*, char*, int, int); //added to do
#endif
