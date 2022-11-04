#include "treePublic.h"

#define OK 1
#define KO 0

int main ( void )
{
  node_t *root, *tmp;
  data_t d;
  int retValue, end = 0;
  int arr[3];
  int i, np, lenght;
  int *arr_level;
  int key1, key2;
  int height;
  char row[MAXC];
  FILE *fp = NULL;

  root = NULL;
  root = createEmptyTree();

  while (!end) {

    fprintf (stdout, "User selection\n");
    fprintf (stdout, "\t1) Insert one single node\n\t2) Cancel one single node\n\t3) Search a node\n");
    fprintf (stdout, "\t4) Print BST on stdout\n\t5) Write BST on file\n\t6) Read BST from file\n");
    fprintf (stdout, "\t7) Compute min and max\n\t8)vCount nodes with children, 1 child or 0 children \n ");
      fprintf (stdout, "\t9)vCount nodes in each level\n\t10) Count paths and lenght total \n");
            fprintf (stdout, "\t11)Count distance between two keys \n\t12)End\n\t>");
    scanf ("%2s", row);

    switch (atoi(row)) {

      case 1:
        fprintf (stdout, "data: ");
	retValue = readData (stdin, &d);
        if (retValue==0) {
          fprintf (stderr, "Input erro.\n");
          exit (0);
        }
	root = insert (root, d);
	break;

      case 2:
        fprintf (stdout, "data: ");
	retValue = readData (stdin, &d);
        if (retValue==0) {
          fprintf (stderr, "Input erro.\n");
          exit (0);
        }
	root = delete (root, d);
	break;

      case 3:
        fprintf (stdout, "data: ");
	retValue = readData (stdin, &d);
        if (retValue==0) {
          fprintf (stderr, "Input error.\n");
          exit (0);
        }

	tmp = searchI (root, d);
	if (tmp != NULL) {
	  fprintf (stdout, "Iterative Search: Found -> ");
          writeData (stdout, getData(tmp));
	} else {
	  fprintf (stdout, "Iterative Search: Not Found\n");
        }
	tmp = searchR (root, d);
	if (tmp  != NULL) {
	  fprintf (stdout, "Recursive Search: Found -> ");
          writeData (stdout, getData(tmp));
	} else {
	  fprintf (stdout, "Recursive Search: Not Found\n");
        }
	break;

      case 4:
	writeTree (stdout, root, INORDER);
	break;

      case 5:
	fprintf (stdout, "File Name: ");
	scanf ("%s", row);

        if (strcmp (row, "stdout") == 0) {
          fp = stdout;
        } else {
   	  fp = fopen (row, "w");
        }

        if (fp == NULL) {
         fprintf (stderr, "Error Opening File %s\n", row);
         break;
	}

	writeTree (fp, root, PREORDER);

        if (strcmp (row, "stdout") != 0) {
	  fclose(fp);
	}
	break;

      case 6:
	fprintf (stdout, "File Name: ");
	scanf ("%s", row);

	fp = fopen (row, "r");
	if (fp == NULL) {
	  fprintf (stderr, "Error Opening File %s\n", row);
	} else {
	  freeTree (root);
	  root = readTree (fp);
	}
	break;

      case 7:
        fprintf (stdout, "Tree minimum iterative: ");
        tmp = treeMinI (root);
        writeData (stdout, getData(tmp));
        fprintf (stdout, "Tree minimum recursive: ");
        tmp = treeMinR (root);
        writeData (stdout, getData(tmp));
        fprintf (stdout, "Tree maximum iterative: ");
        tmp = treeMaxI (root);
        writeData (stdout, getData(tmp));
        fprintf (stdout, "Tree maximum recursive: ");
        tmp = treeMaxR (root);
        writeData (stdout, getData(tmp));
	break;
      case 8:

          arr[0]=arr[1]= arr[2]=0;
        countNode(root, arr);
        fprintf(stdout, "\n\tNodes with no children: %d\n\t Nodes with 1 child: %d\n\tNodes with children: %d\n\n", arr[0], arr[1], arr[2]);
	break;
      case 9:
        height=countHeight(root);
        arr_level=(int*)malloc(height*sizeof(int));
        for(i=0; i<height; i++){
            arr_level[i]=0;
        }

        countLevel(root, arr_level, 0);
        for(i=0; i<height; i++)
            fprintf(stdout, "\n\tLevel %d:  %d nodes", i, arr_level[i]);
            fprintf(stdout, "\n\n");
        break;
      case 10:
        np=lenght=0;
        countPath(root,&np, &lenght);
        fprintf(stdout, "\n\t Number roots: %d\n\t Total lenght: %d \n\n", np, lenght);
        break;
      case 11:
          fprintf(stdout, "Insert the two keys:\n");
          scanf("%d %d", &key1, &key2);
          if(key1>key2)
           i= visit(root,key2, key1);
          else
         i= visit(root, key1, key2);

            fprintf(stdout, "\n\tThe distance between the two keys: %d\n", i);

          break;
          case 12:
	end = 1;
	break;

      default:
	fprintf (stderr, "Unknown Option.\n");
	break;
    }
  }

  freeTree(root);

  return (OK);
}


