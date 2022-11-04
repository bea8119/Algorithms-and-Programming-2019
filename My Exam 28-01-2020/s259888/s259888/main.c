#include <stdio.h>
#include <stdlib.h>

typedef struct val{
int value;
int negation;
}val_t;

val_t ** file_read( FILE* fp, int *n, int *m);
int find_sol(val_t** map, int *sol, int n, int m, int lev);
int check_row(val_t* row, int *sol, int m);
int check_all(val_t** map, int *sol, int n, int m);
void initiate_row(val_t * row, int m);


int main(int argc, char **argv)
{
    int n, m, *sol, i, j;
    FILE * fp;
    if(argc!=2){
        printf("Error with program arguments \n");
        exit(EXIT_FAILURE);
    }
    fp=fopen(argv[1], "r");
    if(fp==NULL){
          printf("Error with opening file \n");
        exit(EXIT_FAILURE);
    }

    val_t** mat;
    mat=file_read(fp, &n, &m);

    sol=(int*)malloc(m*sizeof(int));

    if(sol==NULL){
          printf("Error Allocation \n");
        exit(EXIT_FAILURE);
    }
    for(i=0; i<=m; i++){
        sol[i]=-1;
    }

    if(find_sol(mat, sol, n, m, 0)){
        printf("A solution for the formula received is:\n");
        for(i=0; i<m; i++){
            printf("X(%d)= %d\n", i+1, sol[i]);
        }

    }else
      printf("NO solution for the formula received is:\n");


    return 0;
}


val_t ** file_read( FILE* fp, int *n, int *m){
int i, j, n_row, temp;
val_t ** mat;
fscanf(fp, "%d %d", n, m);
mat=(val_t**)malloc((*m)*sizeof(val_t*));
if(mat==NULL){
    printf("Error Allocation \n");
        exit(EXIT_FAILURE);
}
for(i=0; i<(*n); i++){
    mat[i]=(val_t*)malloc((*m)*sizeof(val_t));
    if(mat[i]==NULL){
    printf("Error Allocation \n");
        exit(EXIT_FAILURE);
}
initiate_row(mat[i], *m);  // in paper forgot parameter m
}

for(i=0; i<(*n); i++){
    fscanf(fp,"%d", &n_row); //in paper I forgot to delete the [i]  from &n_row[i], after changing idea
    for(j=0; j<n_row; j++){
        fscanf(fp, "%d", &temp);
        if(temp<0){
            temp=abs(temp);
            mat[i][temp-1].negation=1;
        }
        mat[i][temp-1].value=1;
    }
} //forgot a parenthesis in paper

return mat;
}

int find_sol(val_t** map, int *sol, int n, int m, int lev){
static int count=0;
if(lev==m){
    if(check_all(map, sol, n, m)){

       return 1;
    }
    else
        return 0;

}

if(sol[lev]==-1)
    sol[lev]=1;

if(find_sol(map, sol, n, m, lev+1))
    return 1;


sol[lev]=0;


if(find_sol(map, sol, n, m, lev+1))
    return 1;

return count;
}

void initiate_row(val_t * row, int m){
int i;
for(i=0; i<m; i++){
    row[i].value=0;
    row[i].negation=0;
}
return;
}



int check_row(val_t* row, int *sol, int m){
int i;

for(i=0; i<m; i++){
    if(row[i].value==1){
        if(row[i].negation==1){
            if(sol[i]==0)
                return 1;
            }else{
            if(sol[i]==1)
                return 1;
            }
    }
}
return 0;
}


int check_all(val_t** map, int *sol, int n, int m){         //in paper forgot '*' before sol
    int i;

        for(i=0; i<n; i++){
            if(check_row(map[i], sol, m)==0){
                return 0;
            }
        }
return 1;

}
