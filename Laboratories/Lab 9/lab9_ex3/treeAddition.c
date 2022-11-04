#include "treePrivate.h"


void countNode(node_t *root, int *array){


        if(root==NULL){
                return;
            }
            if(root->left==NULL && root->right==NULL){
                array[0]++;
                }
            else if( (root->left==NULL && root->right!=NULL)|| (root->left!=NULL && root->right==NULL) ){
                array[1]++;
                }
        else if( root->left!=NULL && root->right!=NULL){
                array[2]++;
                    }

                    countNode(root->left, array);
                    countNode(root->right, array);
        return;

}




int countHeight(node_t *root){
int u, v;
if(root==NULL){
    return -1;
}

    u=countHeight(root->left);
    v=countHeight(root->right);
    if(u>v)
    return (u+1);
    else
    return (v+1);
}

void countLevel (node_t * root, int *array, int l){

  if(root==NULL){
                return;
            }

                    array[l]++;
                    countLevel(root->left, array, l+1);
                    countLevel(root->right, array, l+1);
        return;

}

void countPath (node_t * root, int *np, int *lenght){

  if(root==NULL){
                return;
            }
                *lenght=*lenght+1;
                   if(root->left==NULL && root->right==NULL){
                       *np=*np+1;
                }

                    countPath(root->left, np, lenght);
                    countPath(root->right, np, lenght);
        return;

}


int visitver (node_t *root, int key1, int key2){
static int l=0;
if(root!=NULL){
        if(compare(root->val, key1)==0 || compare(root->val, key2)==0 )
    return 0;
}

if(root->val==key1){
        if (root->val==key2){
            return l;
        }
    l++;
    visit(root->left, key1, key2);
    visit(root->right, key1, key2);
    return 0;
}

visit(root->left, key1, key2);
visit(root->right, key1, key2);
return 0;
}

//__________________________________

int visit (node_t *root, int key1,  int key2)
{
  int t_right, t_left, t_here;

  t_here = 0;
  t_right = t_left = 0;

  if (root != NULL) {
    if (compare (root->val, key1)==0 || compare(root->val, key2)==0) {
      t_here = 1;
    }
    t_left = visit (root->left, key1, key2);
    t_right = visit (root->right, key1, key2);
    if (t_left && t_right) {
      // Splitting node; one child on the left and one on the right
      // As for the BST version distance = left + right height
      printf("Distance between %d and %d: ", key1, key2);
      printf("%d edges\n", t_left+t_right);
    } else if (t_left || t_right) {
      if (t_here) {
        // One child on the left or on the right the other on this node
        // I return t_left if it is on the left and t_rith if it is on the right,
        // i.e., I always return t_left+t_right
        printf("Distance between %d and %d: ", key1, key2);
        printf("%d edges\n", t_left+t_right);
      } else {
        // On eis on the left or on the right and the other I do not know
        // I return t_left+1 or t_right+1, i.e., t_left+t_tight+1 being one = 0
        return t_left + t_right + 1;
      }
    }
  }

  return t_here;
}


