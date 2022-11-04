#ifndef _TREE_PRIVATE_INCLUDED
#define _TREE_PRIVATE_INCLUDED

#include "treePublic.h"
typedef struct item Item;
struct node {
  Item val;
  struct node *left;
  struct node *right;
};


#endif
