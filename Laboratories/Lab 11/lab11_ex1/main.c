#include "item.h"
#include "st.h"
#include "treePublic.h"


/*Receive two file names on the command line.
* Store the content of the first file in a BST with string keys
  (the register number), using the BST library functions.
* Visit the tree in in-order and save all data in a hash table,
  using the BST and the hash-table library functions.
* Traverse the hash table, from the first to the last element of the
  table and for each element of the table store all elements within
  the connected list in the output file, using (modified) hash-table
  library functions.*/

  int main(int argc, char* argv[]){
      node_t *root, *tmp;
      FILE *fp;
      int maxN;
      Item item;
       printf("Input size of hash table to guarantee load factor < 1/2:");
  scanf("%d", &maxN);

  ST st = STinit(maxN);

  if(argc!=3){
    printf("ERROR ARGUMENTS\n");
    return 1;
  }
  fp = fopen (argv[1], "r");
	if (fp == NULL) {
	  fprintf (stderr, "Error Opening File\n");
	} else {
	  freeTree (root);
	  root = readTree (fp);
	}
    writeTree(stdout, root, INORDER);
//INSERT IN HASH TABLE
writeTree (stdout, root, INORDER);

printf("Enter item: \n");
/*STinsertFromBST( )
                            item = ITEMscan();
                            if (ITEMcheckvoid(STsearch(st, KEYget(item))))
                              STinsert(st, item);

*/


  return 0;
  }
