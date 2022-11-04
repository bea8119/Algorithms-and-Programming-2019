#include "data.h"


char *getField1 (data_t data){
return (data->id);
}
char *getField2 (data_t data){
   return (data->name);
}
int getField3 (data_t data){
return (data->cred1);
}
int getField4 (data_t data){
return (data->cred2);
}

data_t dataset(char* id, char* name, int cred1, int cred2){
data_t tmp = (data_t) malloc(sizeof(struct data));
  if (tmp == NULL) {
    return  NULL;
  } else {
    tmp->id = strdup(id);
    tmp->name = strdup(name);
    tmp->cred1= cred1;
    tmp->cred2 = cred2;
  }
  return tmp;
}
int readData (  FILE *fp,  data_t *dat  )
{
  char  name[MAXC], id[MAXC];
  int  cred1, cred2, retValue;
    data_t data;
    data=(data_t)malloc(1*sizeof(struct data));
    if(data==NULL){
        fprintf (stderr, "Allocation Error.\n");
    exit (1);
    }
  retValue = fscanf (fp, "%s %s %d %d",id, name, &cred1, &cred2 );


  data->id=strdup(id);
  data->name=strdup(name);
  data->cred1=cred1;
  data->cred2=cred2;

  *dat=data;
  return (retValue);
}


void writeData (  FILE *fp,  data_t data  )
{
  fprintf(fp, "%s %s %d %d\n",data->id , data->name, data->cred1, data->cred2 );

  return;
}


int compare (  data_t d1,  data_t d2  )
{

  return (strcmp(d1->id, d2->id));
}
