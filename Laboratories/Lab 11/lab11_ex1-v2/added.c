#include "item.h"
#include "treePrivate.h"


void writeHashfromBST(FILE *fp, node_t *rp, int modo){

 if (rp == NULL) {
    return;
  }

  if (modo == PREORDER) {
    writeDataHash (fp, rp->val);
  }

  writeHashfromBST (fp, rp->left, modo);

  if (modo == INORDER) {
    writeDataHash(fp, rp->val);
  }

  writeHashfromBST (fp, rp->right, modo);

  if (modo == POSTORDER) {
    writeDataHash(fp, rp->val);
  }

  return;


}
