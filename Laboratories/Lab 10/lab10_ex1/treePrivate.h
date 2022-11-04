#ifndef _TREE_PRIVATE_INCLUDED
#define _TREE_PRIVATE_INCLUDED

#include "treePublic.h"



typedef struct node {
  char *name;
  char *surname;
  char *date;
  char *course;
  int year;
  int id;
  struct node *left_1;
  struct node *right_1;
  struct node *left_2;
  struct node *right_2;
} node_t;



#endif
