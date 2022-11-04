#include <stdio.h>
#include <stdlib.h>

#define max_dim 50
int main()
{
    float m1[max_dim][max_dim], m2[max_dim][max_dim];
    int m1_c, m1_r, m2_c, m2_r, i, j, k ,l;
    printf("insert dimensions of m1:\n");
    scanf("%d %d", &m1_r, &m1_c);
    printf("\n insert dimensions of m2:\n");
    scanf("%d %d", &m2_r, &m2_c);
    float m3[m1_r][m2_c];
    if(m1_c>max_dim ||m1_r>max_dim || m2_c>max_dim ||m2_r>max_dim || m1_c!=m2_r){
        printf("error ");
        return 1;
    }

   printf("\n Insert m1:\n");
   for(i=0;i<m1_r; i++){
    for(j=0;j<m1_c; j++){
        scanf("%f", &m1[i][j]);
    }
   }
    printf("\n Insert m2:\n");
   for(i=0;i<m2_r; i++){
    for(j=0;j<m2_c; j++){
        scanf("%f", &m2[i][j]);
    }
   }


    printf("\n here we go: \n");
    for(i=0; i<m1_r; i++){
        for(j=0; j<m2_c;j++){
                m3[i][j]=0;
            for(k=0; k<m1_c; k++){

                    m3[i][j]=m3[i][j]+(m1[i][k]*m2[k][j]);


            }
            printf("%.f ", m3[i][j]);
        }
        printf("\n");
    }


    return 0;
}
