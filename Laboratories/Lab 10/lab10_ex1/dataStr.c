#include "dataStr.h"
#include "treePrivate.h"

int readData (FILE *fp,  node_t *rp )
{
    int val;
  char  row[MAXC];
       val= fscanf (fp, "%s ", row );

       if(val==EOF){
        return val;
       }
       rp->id=atoi(row);
        fscanf (fp, "%s ", row );
        rp->surname=strdup(row);
        fscanf (fp, "%s ", row );
        rp->name=strdup(row);
          fscanf (fp, "%s ", row );
        rp->date=strdup(row);
        fscanf (fp, "%s ", row );
        rp->course=strdup(row);
         fscanf (fp, "%s ", row );
        rp->year=atoi(row);

  return (val);
}


void writeData (FILE *fp, node_t *rp)
{
  fprintf(fp, "%d %s %s %s %s %d\n", rp->id,  rp->surname, rp->name ,rp->date, rp->course, rp->year);
  return;
}


int compare (data_t d1,data_t d2)
{
  return (strcmp(d1, d2));
}
