#ifndef AUSILIARY_H_INCLUDED
#define AUSILIARY_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct cell{
int v;
int flagc;
int flagr;
char r_left;
char r_down;
}cell_t;

cell_t **setup(FILE* f_in, int *n);
int check_zeroes(cell_t** mat, int n);
int check_sol(cell_t** mat, int n);
void print_sol(cell_t** mat, int n);
int solve(cell_t ** mat, int n, int r);
int free_pls(cell_t **mat, int n);

#endif // AUSILIARY_H_INCLUDED
