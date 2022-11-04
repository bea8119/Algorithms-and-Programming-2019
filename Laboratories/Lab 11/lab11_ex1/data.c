#include "data.h"
#include "item.h"
#include "st.h"

typedef struct item Item;

int readData (  FILE *fp,  Item *dat  ){

  int id, cred1, cred2;
  char name[MAXC];
  int retValue;

  retValue = fscanf (fp, "%d %s %d %d\n", &id, name, &cred1, &cred2);

  dat->id=id;
  dat->name=strdup(name);
  dat->cred1=cred1;
  dat->cred2=cred2;


  return (retValue);
}


void writeData (  FILE *fp,  Item data)
{
  fprintf(fp, "%d %s %d %d\n", data.id, data.name, data.cred1, data.cred2);

  return;
}


int compare ( Item d1,  Item d2 )
{

  return (d1.id==d2.id);
}
