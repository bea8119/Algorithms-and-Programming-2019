#include "h2.h"

 const int xmod[4]={0, 1, 0, -1 };
 const int ymod[4]={1, 0, -1, 0 };

char ** readfile( int *c, int *r, FILE *f_input){
int i;
char **m;
char *temp;

fscanf(f_input, "%d %d\n", r, c);
temp=(char*)malloc(*c*sizeof(char));
m=mall2(*r);

for(i=0; i<=(*r); i++){

    fgets(temp, *c+2, f_input);
m[i]=strdup(temp);
}

return m;
}

//_____________________________________________________
char ** mall2( int r){
char **m;
int i;
m=(char **)malloc(r*sizeof(char *));

if(m==NULL){
    printf("ERROR ALLOCATION 1\n");
    exit(1);
}
return m;
}

//________________________________________________________

int one_path(char **m, int maxr, int maxc, int row, int col){
    int k, r, c;
    if(m[row][col]==STOP)
        return 1;

    if(m[row][col]!=EMPTY)
        return 0;

        m[row][col]=PATH;
    for(k=0; k<4; k++){
        r=row+ymod[k];
        c=col+xmod[k];
            if(r>=0 && r<maxr && c>=0 && c<maxc ){
                if(one_path(m, maxr, maxc, r, c)==1){
                    return 1;
                }
            }
    }
    m[row][col]=DONE;

    return 0;
}

//__________________________________________________
int cleanm(char **m, int maxr, int maxc){

int i, j;
for(i=0; i<maxr; i++){
    for(j=0; j<maxc; j++){
        if(m[i][j]!=EMPTY && m[i][j]!=STOP  && m[i][j]!='*'){
            m[i][j]=' ';
        }
    }
}
return 0;
}


//_____________________________________
int all_path(char **m, int maxr, int maxc, int row, int col, int row0, int col0 ){

int k, r, c, i;
static int sol=0;
    if(m[row][col]==STOP){
        sol++;
        printf("\n\nSOLUTION NUM %d: \n\n", sol);
        m[row0][col0]=PATH;
         for(i=0; i<maxr; i++){
        printf("%s", m[i]);
   }
   printf("\n");
   m[row0][col0]=EMPTY;
        return 1;
    }
    if(m[row][col]!=EMPTY)
        return 0;

        m[row][col]=PATH;
    for(k=0; k<4; k++){
        r=row+ymod[k];
        c=col+xmod[k];
            if(r>=0 && r<maxr && c>=0 && c<maxc ){
                all_path(m, maxr, maxc, r, c, row0, col0);
            }
    }
    m[row][col]=DONE;

    return 0;
}
