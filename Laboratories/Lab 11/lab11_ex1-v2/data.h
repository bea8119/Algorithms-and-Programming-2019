#ifndef _DATA_INCLUDED
#define _DATA_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXC 60

struct data{
char *id;
char *name;
int cred1;
int cred2;
};

typedef struct data *data_t;

char *getField1 (data_t);
char *getField2 (data_t);
int getField3 (data_t);
int getField4 (data_t);

int readData (FILE *, data_t *);
void writeData (FILE *, data_t);
int compare (data_t, data_t);
data_t dataset(char*, char*, int, int);
#endif
