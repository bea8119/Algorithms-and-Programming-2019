#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "item.h"



struct item {
    char *id;
    char *name;
     int cred1;
     int cred2;
      };


char *getField2I (Item data){
   return (data->name);
}
int getField3I (Item data){
return (data->cred1);
}
int getField4I (Item data){
return (data->cred2);
}

Item ITEMscan() {
  char name[MAXST], id[MAXST];
  int  cred1, cred2;
 printf("id = ");
  scanf("%s", id);
  printf("name = ");
  scanf("%s", name);
 printf("id = ");
  scanf("%d", &cred1);
  printf("id = ");
  scanf("%d", &cred2);

  Item tmp;
  tmp=(Item)malloc(sizeof(struct item));
if (tmp == NULL)
    return ITEMsetvoid();
    else{
           tmp->id = id;
    tmp->name = strdup(name);
  tmp->cred1=cred1;
  tmp->cred2=cred2;
    }
  return tmp;
}

void ITEMshow(Item data, FILE* fp) {
  fprintf(fp, "%s %s %d %d-- ", data->id, data->name, data->cred1, data->cred2);
}

int ITEMcheckvoid(Item data) {
  Key k1, k2="";
  k1 = KEYget(data);
  if (KEYcompare(k1,k2)==0)
    return 1;
  else
    return 0;
}

Item ITEMsetvoid() {
  char name[MAXST]="";
  Item tmp;
  tmp=(Item)malloc(sizeof(struct item));
if (tmp != NULL){
     tmp->id=strdup(name);
    tmp->name = NULL;
    tmp->cred1=-1;
    tmp->cred2=-1;
}
  return tmp;
}

Item ITEMset(char* id, char* name, int cred1, int cred2){

Item tmp = (Item) malloc(sizeof(struct item));
  if (tmp == NULL) {
    return ITEMsetvoid();
  } else {
    tmp->id = strdup(id);
    tmp->name = strdup(name);
    tmp->cred1= cred1;
    tmp->cred2 = cred2;
  }
  return tmp;

}

Key KEYscan() {
  char name[MAXST];
  Key *k;
  scanf("%s", name);
  k=strdup(name);
  return k;
}

int  KEYcompare(Key k1, Key k2) {
  return strcmp(k1,k2);
}

Key KEYget(Item data) {
  return data->id;
}


