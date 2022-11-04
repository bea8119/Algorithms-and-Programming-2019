#include "ausiliary.h"


cell_t **setup(FILE* f_in, int *n ){
int i, j;
int dim;
char tmp, trash;
cell_t **mat;

fscanf(f_in, "%d \n", n );
dim=*n;
mat=(cell_t**)malloc(dim*sizeof(cell_t*));
if(mat==NULL){
    printf("ERROR ALLOCATION\n");
    return EXIT_FAILURE;
}
for(i=0; i<dim; i++){
    mat[i]=(cell_t *)malloc((dim)*sizeof(cell_t));
    if(mat[i]==NULL){
    printf("ERROR ALLOCATION\n");
    return EXIT_FAILURE;
}

for(j=0; j<dim; j++){
    mat[i][j].v=0;
    mat[i][j].flagc=0;
    mat[i][j].flagr=0;
    mat[i][j].r_down='-';
    mat[i][j].r_left='|';

    //print_sol(mat, *n);
}
}
     for(i=0; i<dim; i++){

        if (i>0){
                for(j=0; j<(dim); j++){

                     fscanf(f_in, "%c%c", &tmp, &trash);
                     if(tmp!='-' && tmp!='v' && tmp!='^'){
                        mat[i-1][j].r_down='-';
                     }else{
                     mat[i-1][j].r_down=tmp;
                     }  } }
                for(j=0; j<dim; j++){

           fscanf(f_in, "%d%c", &mat[i][j].v, &tmp );

            if(tmp!='|' && tmp!='<' && tmp!='>'){
                        mat[i][j].r_left='|';
                     }else{
                     mat[i][j].r_left=tmp;
                     }
        }
     }
return mat;
}


int check_zeroes(cell_t** mat, int n){
    int i,j;
    for(i=0; i<n; i++)
    for(j=0; j<n; j++)
        if(mat[i][j].v==0)
            return 0;
     return 1;
}

int check_sol(cell_t** mat, int n){
    int i, j;

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
                if(mat[i][j].r_down=='^'){
                    if(mat[i][j].v>mat[i+1][j].v){
                        return 0;
                    }
                }else   if(mat[i][j].r_down=='v'){
                    if(mat[i][j].v<mat[i+1][j].v){
                        return 0;
                    }
                }

                  if(mat[i][j].r_left=='<'){
                    if(mat[i][j].v>mat[i][j+1].v){
                        return 0;
                    }
                }else   if(mat[i][j].r_left=='>'){
                    if(mat[i][j].v<mat[i][j+1].v){
                        return 0;
                    }
                }}}

return 1;
}

void print_sol(cell_t** mat, int n){
int i, j;
char tmp;
for(i=0; i<n; i++){
        if(i>0){
                tmp='-';
            for(j=0; j<n; j++){
                if(j==n-1)
                tmp='\n';
                printf("%c%c", mat[i-1][j].r_down, tmp);
            }}
    for(j=0; j<n-1; j++){
        printf("%d%c", mat[i][j].v, mat[i][j].r_left);
    }
    printf("%d\n", mat[i][j].v);
}

return;
}


int solve(cell_t ** mat, int n, int r){

}


int free_pls(cell_t **mat, int n){

}
