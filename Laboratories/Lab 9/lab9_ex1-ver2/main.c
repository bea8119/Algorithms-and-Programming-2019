#include "h2.h"

int main()
{

      FILE *f_input;
    f_input=fopen("f.txt", "r");
    if(f_input==NULL){
        printf("ERRORE FILE \n");
        exit(1);
    }
    char **m;
    char **best;
    int c, r, i, j, row, col;
   m=best=readfile(&c, &r,  f_input );

    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            if(m[i][j]==START){
                row=i;
                 col=j;
                 m[i][j]=EMPTY;
            }
        }
    }
             for(i=0; i<r; i++){
        printf("%s", m[i]);
   }

    int ris;
    ris=one_path(m,r, c, row, col);

    if(ris==1){
            printf("\n\nSOLUTION : \n");
           for(i=0; i<r; i++){
        printf("%s", m[i]);
   }
   printf("________________________\n");
    }
    else{
        printf("NO PATH\n");
             for(i=0; i<=r; i++){
        printf("%s", m[i]);
   }
    }

cleanm(m, r, c);
ris=all_path(m, r, c, row, col, row, col);

free(m);
    printf("OK 2\n ");
    fclose(f_input);
    return 0;
}
