#include "ausiliary.h"



int main(int argv,  char* argc[])
{
int n;
FILE* f_in;
if(argv!=2)
    exit(EXIT_FAILURE);

    f_in=fopen(argc[1], "r");
    cell_t **mat;
    mat=setup(f_in, &n);
print_sol(mat, n);
    if(check_zeroes(mat,n)==1){
        if(check_sol(mat, n)==1){
            fprintf(stdout, "SOLUTION correct already\n");
        }
        else{
            fprintf(stdout, "SOLUTION  NOT correct \n");
        }
    }
    else{
        if(solve(mat, n, 0)){
              fprintf(stdout, "SOLUTION  FOUND\n");
              print_sol(mat, n);
        }
        else{
            fprintf(stdout, "SOLUTION  NOT FOUND \n");
        }

    }

free_pls(mat, n);
return 0;
}
