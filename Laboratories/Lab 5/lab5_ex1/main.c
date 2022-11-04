#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

//Version 1
typedef struct {
char *str;
int flag;
}words;

words *ordlist(words *, int);
words *readfile(int *);

int main()
{
    int i, num;




FILE* f_out;

f_out=fopen("out.txt", "w");
if( f_out==NULL){
    fprintf(stderr, "ERROR FILES\n");
    exit(EXIT_FAILURE);
}

    words *list1;
    list1= readfile(&num);

    for(i=0; i<num; i++){
      printf("%s  \n", list1[i].str);
    }
 //   printf("\n\n\n");
   // PER PROVA LETTURA
//printf("prova 1\n");
    words *ordered=ordlist(list1, num);
   // printf("prova\n");
for(i=0; i<num; i++){
      fprintf(f_out, "%s \n", ordered[i].str);
    }
    fclose(f_out);
    for(i=0; i<num; i++){
        free(list1[i].str);
    }
    free(list1);
    free(ordered);
    return 0;
}

words* readfile(int *num){
int i;
    words *list;
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
list=(words*)malloc((*num)* sizeof(words));
if(list==NULL){
    fprintf(stderr, "Error memory allocation \n");
    exit(EXIT_FAILURE);
}

for( i=0; i<*num; i++){

    fscanf(f_input, "%s", name);
   // printf("%s boh\n",name);
    list[i].str=strdup(name);
 printf("%s hhh\n",list[i].str);
    list[i].flag=0;
    if(list[i].str==NULL){
        fprintf(stderr, "ERROR memory alloc \n");
        exit(1);
    }

}
fclose(f_input);
return list;
}

words *ordlist(words *list, int num){
int i, j, index;
words *ord;
ord=(words *)malloc(num*sizeof(words));

for(j=0; j<num ; j++){

        index=-1;
        for(i=0; i<num && index==-1; i++){
            if(list[i].flag==0){
                index=i;

            }
        }
   for(i=0; i<num; i++){

           if(strcmp(list[index].str, list[i].str)>0 && list[i].flag==0){
            index=i;
           }
           }
 //printf("%d  --%s\n", index, list[index].str);
     ord[j].str=strdup(list[index].str);
           list[index].flag=1;

}

return ord;

}

