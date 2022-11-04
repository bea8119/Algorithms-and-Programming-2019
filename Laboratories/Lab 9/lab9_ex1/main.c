#include "h1.h"
int main()
{

    FILE *f_input;
    f_input=fopen("f.txt", "r");
    if(f_input==NULL){
        printf("ERRORE FILE \n");
        exit(1);
    }
    char **mat;
    int c, r, i;

   mat=readfile(&c, &r,  f_input );

   posit *list;
    list=(posit *)malloc((r-1)*(c-1)*sizeof(posit));
    if(list==NULL){
        printf("ERROR ALLOCATING LIST\n");
        exit(1);
    }
    list[0]=firstfind(mat, r, c);
   int count;
  count= findpath(mat, list, 0);
 if(count!=0){
    printf("Solution: \n");
    for(i=0; i<count+1; i++){
        printf(" ( %d, %d )\n", list[i].x, list[i].y);
    }
 }


free(list);
printf("OKk\n ");
    for (i=0; i<r; i++){
            printf("OK\n ");
        free(mat[i]);
        if(mat[i]==NULL){

        }
    }
    free(mat);
    printf("OK 2\n ");
    fclose(f_input);
    return 0;
}



