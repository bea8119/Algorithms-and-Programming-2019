#include <stdio.h>
#include <stdlib.h>

#define max_dim 50

void readDim(int *r, int *c);
int checkDim(int r1, int c1, int r2, int c2);
void readMatrix(float m[][max_dim], int r, int c);
void computeProduct(float m1[][max_dim], int m1_r, int m1_c, float m2[][max_dim], int m2_r, int m2_c, float m3[][max_dim], int *r3, int *c3);
void writeMatrix(float m1[][max_dim], int m1_r, int m1_c, float m2[][max_dim], int m2_r, int m2_c, float m3[][max_dim], int r3, int c3);

int main()
{
    float m1[max_dim][max_dim], m2[max_dim][max_dim], m3[max_dim][max_dim];
    int m1_c, m1_r, m2_c, m2_r, r3, c3;
    printf("insert dimensions of m1:\n");
    readDim(&m1_r, &m1_c);
    printf("\n insert dimensions of m2:\n");
    readDim(&m2_r, &m2_c);

    if (checkDim(m1_r, m1_c, m2_r, m2_c)==1){
        printf("error ");
        return 1;
    }


    printf("\n Insert m1:\n");
   readMatrix(m1, m1_r, m1_c);
    printf("\n Insert m2:\n");
   readMatrix(m2, m2_r, m2_c);


    computeProduct(m1, m1_r, m1_c, m2, m2_r, m2_c, m3, &r3, &c3);

    writeMatrix(m1, m1_r, m1_c, m2, m2_r, m2_c, m3, r3, c3);

    return 0;
}

void readDim(int *r, int *c){

scanf("%d %d", r, c);

}

int checkDim(int r1, int c1, int r2, int c2){

 if(r1>max_dim ||c1>max_dim || r2>max_dim ||c2>max_dim || c1!=r2){

        return 1;
    }
    else {
            return 0;
    }
}

void readMatrix(float m[][max_dim], int r, int c){
    int i,j;
    for(i=0;i<r; i++){
    for(j=0;j<c; j++){
        scanf("%f", &m[i][j]);
    }
   }
}

void computeProduct(float m1[][max_dim], int m1_r, int m1_c, float m2[][max_dim], int m2_r, int m2_c, float m3[][max_dim], int *r3, int *c3){
int i,j, k;
*r3=m1_r;
*c3=m2_c;
for(i=0; i<*r3; i++){
        for(j=0; j<*c3;j++){
                m3[i][j]=0;
            for(k=0; k<m1_c; k++){

                    m3[i][j]=m3[i][j]+(m1[i][k]*m2[k][j]);


            }}}

}

void writeMatrix(float m1[][max_dim], int m1_r, int m1_c, float m2[][max_dim], int m2_r, int m2_c, float m3[][max_dim], int r3, int c3){
    int i,j;
printf("\n printing m1:\n");
   for(i=0;i<m1_r; i++){
    for(j=0;j<m1_c; j++){
        printf("%f ", m1[i][j]);
    }
    printf("\n");
   }
   printf("\n printing m2:\n");
   for(i=0;i<m2_r; i++){
    for(j=0;j<m2_c; j++){
        printf("%f ", m2[i][j]);
    }
    printf("\n");
   }
   printf("\n printing m3:\n");
   for(i=0;i<r3; i++){
    for(j=0;j<c3; j++){
        printf("%f ", m3[i][j]);
    }
    printf("\n");
   }

}




