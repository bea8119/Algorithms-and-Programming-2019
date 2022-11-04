#include <stdio.h>
#include <stdlib.h>
#include<string.h>


char ***mall3(int R, int C);
char **mall2(int R);
char *** readfile(FILE *f_input, int R, int C );
char **sort(char ***mat, int R, int C);
void writefile(char **ord, int R, int C);

int main()
{
int R, C, i, j;
char ***mat;
char **ord;
FILE *f_input;
 f_input=fopen("f.txt", "r");
 fscanf(f_input,"%d %d\n", &R, &C);

 ord=mall2(R*C);
mat=readfile(f_input, R, C);
//for(i=0; i<R; i++){for(j=0; j<C; j++){ printf("%s  ", mat[i][j]);}}

ord=sort(mat, R, C);

writefile(ord, R, C);
fclose(f_input);
for(i=0; i<R; i++){
    for(j=0; j<C; j++){
        free(mat[i][j]);
    }
    free(mat[i]);
    free(ord[i]);
}
free(mat);
free(ord);

    return 0;

}

char ***mall3(int R, int C){
        int i;
 char ***m;

 m=(char ***)malloc(R *sizeof(char**));
 if(m==NULL){
    fprintf(stderr, "ERROR ALLOCATING 1!\n");
    exit(EXIT_FAILURE);
 }
 for(i=0; i<R; i++){
    m[i]=(char**)malloc(C *sizeof(char*));
   if(m[i]==NULL){
    fprintf(stderr, "ERROR ALLOCATING 2!\n");
    exit(EXIT_FAILURE);

 }
 }
 return m;
}

char **mall2(int R){
char **m;
m=(char**)malloc(R*sizeof(char*));
 if(m==NULL){
    fprintf(stderr, "ERROR ALLOCATING 1!\n");
    exit(EXIT_FAILURE);
 }
 return m;
}



char ***readfile(FILE * f_input, int R, int C ){
    int i,j;
    char word[21];
 char ***m;

m=mall3(R,C);
 for(i=0; i<R; i++){
 for(j=0; j<C; j++){
  fscanf(f_input, "%s ", word);
  m[i][j]=strdup(word);
 }}

return m;

}

char **sort(char ***mat, int R, int C){
char **ord;
int i, min, index=0;
ord=mall2(R*C);
int *flag;
flag=(int*)malloc(R*sizeof(int));
for(i=0; i<R; i++){
    flag[i]=0;
}

do{
        min=0;
    for(i=0; i<R; i++){
//printf("%s %s\n", mat[min][flag[min]], mat[i][flag[i]]);
if(flag[i]<C){
    if(strcmp(mat[min][(flag[min])], mat[i][(flag[i])])>0){
            min=i;
}
}

            }



        ord[index]=strdup(mat[min][flag[min]]);

        flag[min]++;
        index++;

    }while (index<R*C);

    return ord;
}

void writefile(char **ord, int R, int C){
FILE *out;
out=fopen("out.txt", "w");
for(int i=0; i<R*C; i++){

    fprintf(out,"%s \n", ord[i]);
}


fclose(out);


}





