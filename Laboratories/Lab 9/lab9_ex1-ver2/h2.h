#ifndef H2_H_INCLUDED
#define H2_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define EMPTY ' '
#define START '@'
#define STOP '#'
#define PATH '$'
#define DONE '.'

char ** readfile( int *c, int *r, FILE *f_input);

char ** mall2( int r);
int one_path(char **m, int maxr, int maxc, int row, int col);
int all_path(char **m, int maxr, int maxc, int row, int col, int row0, int col0 );
int cleanm(char **m, int maxr, int maxc);
#endif // H2_H_INCLUDED
