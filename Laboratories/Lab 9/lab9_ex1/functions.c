#include "h1.h"

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


//_____________________________________________________

posit firstfind(char **m, int r, int c){
int i, j;
posit p;
for(i=0; i<r; i++){
    for(j=0; j<c; j++){
        if(m[i][j]=='@'){
            p.x=j;
            p.y=i;
        }
    }
}
return p;
}

//________________________________________________________


//_____________________________________________________

//put the checks and maybe remove blank

int blank(char **m, posit *p, int i){


if(m[p[i].y][p[i].x-1]!='*'){
    if(m[p[i].y][p[i].x-1]==' '){
        m[p[i].y][p[i].x-1]='*';
    }

        p[i+1].y=p[i].y;
        p[i+1].x=p[i].x-1;
return 1;
}

if(m[p[i].y][p[i].x+1]!='*'){
    if(m[p[i].y][p[i].x+1]==' '){
        m[p[i].y][p[i].x+1]='*';
    }

        p[i+1].y=p[i].y;
        p[i+1].x=p[i].x+1;
        return 1;
}

if(m[p[i].y-1][p[i].x]!='*'){

    if(m[p[i].y-1][p[i].x]==' '){
        m[p[i].y-1][p[i].x]='*';
    }

        p[i+1].y=p[i].y-1;
        p[i+1].x=p[i].x;

        return 1;
}

if(m[p[i].y+1][p[i].x]!='*'){
    if(m[p[i].y+1][p[i].x]==' '){
        m[p[i].y+1][p[i].x]='*';
    }

        p[i+1].y=p[i].y+1;
        p[i+1].x=p[i].x;
        return 1;
}
return 0;
}


int findpath(char **m,posit *p, int coun){
int var;
if(m[p[coun].y][p[coun].x]=='#'){
    return coun;
    }
var=blank(m, p, coun);
    if(var==1){
coun++;

         findpath(m, p, coun);
    }
else if(var==0){
        if(coun==0){
            return 0;
        }
    coun--;
 findpath(m, p, coun);
}


 return coun;
}




