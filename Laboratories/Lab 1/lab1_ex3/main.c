#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define r 3
#define c 5
int main()
{
    int m1[r][c], m2[r][c];
    int i, j;

    printf("insert m1: \n");
    for(i=0;i<r; i++){
        for(j=0;j<c;j++){
            scanf("%d", &m1[i][j]);
        }
    }

     for(i=0;i<r; i++){
        for(j=0;j<c;j++){
            if(m1[i][j]==0){
                m2[i][j]=0;
            }

            else if(m1[i][j]<0){
                    m2[i][j]=1;
                    for(int k=-m1[i][j]; k>0; k--){
                        m2[i][j]=m2[i][j]*k;
                    }

            }else if(m1[i][j]>0){
                int x=m1[i][j];
                float count=1.0;

              while(x>10){
                    x=x/10;
              count++;
                    }
m2[i][j]=1;
                for(int k=0; k<count; k++){
                    m2[i][j]=m2[i][j]*10;
                }

            }

        }
    }
    printf("\n\n sequence m2: \n");
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            printf("%d ", m2[i][j]);
        }
        printf("\n");
    }


    return 0;
}
