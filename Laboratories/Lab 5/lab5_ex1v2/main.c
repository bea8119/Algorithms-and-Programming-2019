#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

/*Version 1
typedef struct {
char *str;
int flag;
}words;*/


void readfile(char ***, int *);
void ordlist(char **, char***, int, int *);
int main()
{
    int i, num;




FILE* f_out;

f_out=fopen("out.txt", "w");
if( f_out==NULL){
    fprintf(stderr, "ERROR FILES\n");
    exit(EXIT_FAILURE);
}

    char **list1;
    int *flag;
    readfile(&list1, &num);
flag=(int *)malloc(num*sizeof(int));
    for(i=0; i<num; i++){
      printf("%s  \n", list1[i]);
      flag[i]=0;
    }

char **ord;
   ordlist(list1, &ord, num, flag);

for(i=0; i<num; i++){
      fprintf(f_out, "%s \n", ord[i]);
    }
    fclose(f_out);
    for(i=0; i<num; i++){
        free(list1[i]);
    }
    free(list1);
    //free(ordered);
    return 0;
}

void readfile(char ***m, int *num){
int i;
    char **list;
    char name[MAX+1];
    printf("Insert input file name: \n");
 scanf("%s", name);
 FILE* f_input;
 f_input=fopen(name, "r");
fscanf(f_input, "%d\n", num);
if(f_input==NULL){
    fprintf(stderr, "ERROR FILES\n");
    exit(EXIT_FAILURE);
}
list=(char**)malloc((*num)* sizeof(char*));
if(list==NULL){
    fprintf(stderr, "Error memory allocation \n");
    exit(EXIT_FAILURE);
}

for( i=0; i<*num; i++){

    fscanf(f_input, "%s", name);
   // printf("%s boh\n",name);
    list[i]=strdup(name);
 printf("%s hhh\n",list[i]);

    if(list[i]==NULL){
        fprintf(stderr, "ERROR memory alloc \n");
        exit(1);
    }

}
fclose(f_input);
*m=list;
return;
}

void ordlist(char **list, char ***ordine ,int num, int *flag){
int i, j, index;
char **ord;
ord=(char **)malloc(num*sizeof(char *));

for(j=0; j<num ; j++){

        index=-1;
        for(i=0; i<num && index==-1; i++){
            if(flag[i]==0){
                index=i;

            }
        }
   for(i=0; i<num; i++){

           if(strcmp(list[index], list[i])>0 && flag[i]==0){
            index=i;
           }
           }

     ord[j]=strdup(list[index]);
     printf("%d  --%s\n", index, ord[j]);
           flag[index]=1;

}

*ordine=ord;
return;

}
