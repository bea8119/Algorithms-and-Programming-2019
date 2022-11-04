#include "treePublic.h"

#define OK 1
#define KO 0
#define N 100

 int main(int argc, char* argv[]){
      node_t *root=NULL;

      FILE *fp;
      FILE* fout;
      ST st;
  if(argc!=3){
    printf("ERROR ARGUMENTS\n");
    return 1;
  }
  fp = fopen (argv[1], "r");
  fout=fopen(argv[2], "w");
	if (fp == NULL || fout==NULL) {
	  fprintf (stderr, "Error Opening File\n");
	  exit(EXIT_FAILURE);
	}

	  root=NULL;
	  root=createEmptyTree();
	  root = readTree (fp);

    writeTree(stdout, root, INORDER);
//INSERT IN HASH TABLE

st=STinit(N);
bstTOhash(root, st);
STdisplay(st, fout);

link list_un, tmp_l_u;
printf("\n\n Printing list of chained elements...\n");
tmp_l_u=list_un=listUnique(st);

if(link_print(tmp_l_u)==0){
    printf("\t\tThe list is empty! \n");

}else{
printf(" \n\nPrevious list with levels in the BST:\n");
listAndBST(tmp_l_u, root );
}




freeTree(root);
fclose(fp);
fclose(fout);
return 0;
  }
