#include "treePublic.h"

#define OK 1
#define KO 0

int main ( void )
{
  node_t *root, *tmp;

  FILE *fp = NULL;
 char row[MAXC*3];
 char instr[MAXC], instr2[MAXC], instr3[MAXC];
  root = NULL;
  root = createEmptyTree();
  int end=0;

  while (!end) {

    fprintf (stdout, "User selection\n");
    fprintf (stdout, "\t To read file: load *filename*  \n\t To search name: searchS *surname* *name*\n\t To search for ID: searchInt *ID*\n");
    fprintf (stdout, "\tTo save list in a file: save *filename*\n\t  To end: stop\n");
    gets( row);
sscanf(row, "%s ", instr);

 if(compare(instr, "load")==0){
        sscanf(row, "%s %s ", instr, instr2);
    fp=fopen(instr2, "r");

    if (fp == NULL) {
	  fprintf (stderr, "Error Opening File %s\n", instr2);
	} else {
	  freeTree (root);

	  root = readTree (fp);
	}
fclose(fp);
 }
 else if(compare(instr, "searchS")==0){
        sscanf(row, "%s %s %s", instr, instr2, instr3);
        tmp=root;
    if(searchI(tmp,instr2, instr3 )==0){
        printf("No match found...\n");
    }

 }
 else if(compare(instr, "searchInt")==0){

  sscanf(row, "%s %s ", instr, instr2);
        tmp=root;
   if( searchId(tmp, atoi(instr2) )==0){
    printf("No match found...\n");
   }
 }
else if(compare(instr, "save")==0){
tmp=root;
 sscanf(row, "%s %s ", instr, instr2);
 FILE* f_out;
 f_out=fopen(instr2, "w" );
writeTree(f_out, tmp, -1);
fclose(f_out);
}
else if(compare(instr, "stop")==0){
    end = 1;
}
   else
    fprintf(stdout, "\n SELECTION NOT VALID\n \tTry again: \n\n");

  }


 freeTree(root);

  return (OK);
}
