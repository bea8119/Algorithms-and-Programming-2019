#include "treePrivate.h"

#define FIND 0

static node_t *myAlloc (void);
#if FIND
 // static data_t findDeleteMax1 (node_t **);
#endif
#if !FIND
//  static node_t *findDeleteMax2 (data_t *, node_t *);
#endif



node_t *createEmptyTree (void)
{
  return (NULL);
}

//_______________________________________________________
/*
node_t *treeMinI (node_t *rp)
{
  if (rp == NULL)
    return (rp);

  while (rp->left != NULL) {
    rp = rp->left;
  }

  return (rp);
}

//_______________________________________________________

node_t * treeMinR (node_t *rp)
{
  if (rp == NULL || rp->left==NULL)
    return (rp);

  return (treeMinR (rp->left));
}
//_______________________________________________________
node_t * treeMaxI ( node_t *rp)
{
  if (rp == NULL)
    return (rp);

  while (rp->right != NULL) {
    rp = rp->right;
  }

  return (rp);
}

//_______________________________________________________

node_t * treeMaxR (node_t *rp)
{
  if (rp == NULL || rp->right==NULL)
    return (rp);

  return (treeMaxR (rp->right));
}

//_______________________________________________________
*/
int searchI (node_t *rp, data_t surname, data_t name )
{
    int l=0;
  while (rp != NULL) {
    if (compare(rp->name, name) == 0 && compare(rp->surname, surname) == 0){
            writeData(stdout, rp);
            l=1;

    }

    if (compare(rp->name, name) > 0)
      rp = rp->left_1;
    else
      rp = rp->right_1;
  }

  return  l;
}
int searchId (node_t *rp, int id )
{
 if(rp==NULL){
    return 0;
 }
    if (rp->id==id){
            writeData(stdout, rp);
            return 1;
    }
       searchId(rp->left_1, id);
       searchId(rp->right_1, id);


  return 1;
}

//_______________________________________________________
/*
node_t * searchR ( node_t *rp, data_t data )
{
  if (rp==NULL || compare(rp->val, data)==0)
    return (rp);

  if (compare(data, rp->val) < 0)
    return (searchR (rp->left, data));
  else
    return (searchR (rp->right, data));
}
*/
//_______________________________________________________
//OK
node_t * insert (node_t *rp, node_t *tmp)
 {
  // Empty Tree: Found Position
node_t *p;
  if (rp == NULL) {
        p=myAlloc();
        p->name=strdup(tmp->name);
        p->surname=strdup(tmp->surname);
        p->course=strdup(tmp->course);
        p->date=strdup(tmp->date);
        p->year=tmp->year;
        p->id=tmp->id;
    p->left_1 = p->right_1 =p->left_2 = p->right_2=NULL;
    return (p);
  }

 // Duplicated Element
  if (compare(tmp->name, rp->name) == 0 && compare(tmp->surname, rp->surname) == 0) {
    return (rp);
  }

  if (compare(tmp->name, rp->name) < 0) {
    // Insert on the left
    rp->left_1 = insert (rp->left_1, tmp);
  } else {
    // Insert on the right
    rp->right_1 = insert (rp->right_1, tmp);
  }

  if (compare(tmp->surname, rp->surname) < 0) {
    // Insert on the left
    rp->left_2 = insert (rp->left_2, tmp);
  } else {
    // Insert on the right
    rp->right_2 = insert (rp->right_2, tmp);
  }

  return (rp);
}

//_______________________________________________________
//OK
node_t * readTree ( FILE *fp )
{

   node_t *rp;
    node_t *tmp;

    rp =createEmptyTree ();
    tmp=myAlloc();

  while (readData (fp, tmp) != EOF) {

        rp = insert (rp, tmp);
  }

  return (rp);
}

//_______________________________________________________
//OK
void freeTree ( node_t *rp )
{

  if (rp == NULL) {
    return;
  }

     free(rp->name);
    free(rp->surname);
    free(rp->course);
    free(rp->date);
  freeTree (rp->left_1);
  freeTree (rp->right_1);
  freeTree (rp->left_2);
  freeTree (rp->right_2);
  free (rp);

  return;
}

//_______________________________________________________



void writeTree ( FILE* fp, node_t *rp, int modo )
{
  if (rp == NULL) {
    return;
  }

  if (modo == PREORDER) {
    writeData (fp, rp);
  }

  writeTree ( fp, rp->left_2, modo);

  if (modo == INORDER) {
    writeData (fp, rp);
  }

  writeTree (fp, rp->right_2, modo);

  if (modo == POSTORDER) {
    writeData (fp, rp);
  }

  return;
}

//_______________________________________________________
/*
node_t * delete (  node_t *rp,  node_t *tmp  )
{
  node_t *p;

  //Empty Tree
  if (rp == NULL) {
    printf("Error: Unknown Data\n");
    return (rp);
  }

  if (compare (rp->name, tmp->name) < 0) {
    // Delete on the left sub-treee Recursively
    rp->left_1 = delete (rp->left_1, );
    return (rp);
  }

  if (compare(rp->name, tmp->name)> 0) {
    // Delete on the rigth sub-treee Recursively
    rp->right_1 = delete (rp->right_1, tmp);
    return (rp);
  }

 // Delete Current Note rp
  p = rp;
  if (rp->right == NULL) {
    // Empty Right Sub-Tree: Return Left Sub-Tree
    rp = rp->left_1;
    free (p);
    return (rp);
  }

  if (rp->left == NULL) {
   //  Empty Left Sub-Tree: Return Right Sub-Tree
    rp = rp->right_1;
    free (p);
    return rp;
  }

 // Find Predecessor and Substitute
#if FIND
  rp->val = findDeleteMax1 (&(rp->left));
#endif
#if !FIND
  {
    data_t val;

    rp->left = findDeleteMax2 (&val, rp->left);
    rp->val = val;
  }
#endif

  return (rp);
}*/

//_______________________________________________________

static node_t * myAlloc (  void  )
{
  node_t *p;

  p = (node_t *)malloc(sizeof(node_t));
  if (p == NULL) {
    printf ("Allocation Error.\n");
    exit (1);
  }

  return (p);
}

//_______________________________________________________

/*#if FIND
static data_t
findDeleteMax1 (
  node_t **rpp
  )
{
  node_t *p;
  data_t d;

 // Find The Rigth-Most Node (max value)
  while ((*rpp)->right != NULL)
    rpp = &((*rpp)->right);

  p = *rpp;
  d = p->val;
  *rpp = (*rpp)->left;
  free (p);

  return (d);
}
#endif

#if !FIND
static node_t * findDeleteMax2 (  data_t *d,  node_t *rp  )
{
  node_t *tmp;

  if (rp->right == NULL) {
    *d = rp->val;
    tmp = rp->left;
    free (rp);
    return (tmp);
  }

  rp->right = findDeleteMax2 (d, rp->right);
  return (rp);
}
#endif */
