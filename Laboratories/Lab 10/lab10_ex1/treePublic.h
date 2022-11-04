#ifndef _TREE_PUBLIC_INCLUDED
#define _TREE_PUBLIC_INCLUDED

#include "dataStr.h"

#define PREORDER  -1
#define INORDER    0
#define POSTORDER  1



node_t *createEmptyTree ();
node_t *readTree( FILE*);
int searchI(node_t *, data_t, data_t);
int searchId(node_t *, int);
node_t *searchR (node_t *, data_t);
node_t *treeMinI (node_t *);
node_t *treeMinR (node_t *);
node_t *treeMaxI (node_t *);
node_t *treeMaxR (node_t *);
node_t *insert(node_t *, node_t *);
node_t *delete(node_t *, data_t);
void writeTree( FILE *, node_t *, int);
void freeTree(node_t *);

#endif


