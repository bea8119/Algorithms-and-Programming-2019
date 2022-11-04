#include <stdio.h>
#include <stdlib.h>

int **mall2(int R ,int C);
void genbinary(int **m, int k, int bit);
void reflect(int **m, int n,  int k, int bit);

            int main()
            {
                int **mat;
                int bit;
                int i, j;
                printf("Insert numbers of bits: \n");
                scanf("%d", &bit);
                mat=mall2(bit, pow(2,bit));

                genbinary(mat, 1, bit);
                    for(i=0; i<pow(2, bit); i++){
                        for(j=0;  j<bit; j++){
                            printf("%d ", mat[i][j]);
                        }
                        printf("\n");

                    }

for(i=0; i<pow(2, bit); i++)
    free(mat[i]);

    free(mat);
                return 0;
            }


//________________________________________________

            int **mall2(int R, int C)
            {
                int **m;

                int i,j;
                m=(int**)malloc(C*sizeof(int*));
                if(m==NULL)
                {
                    fprintf(stderr, "ERROR ALLOCATING 1!\n");
                    exit(EXIT_FAILURE);
                }
                for( i=0; i<C; i++)
                {
                    m[i]=(int*)malloc(R*sizeof(int));
                    if(m[i]==NULL)
                    {
                        fprintf(stderr, "ERROR ALLOCATING 2!\n");
                        exit(EXIT_FAILURE);
                    }
                }
                return m;
            }

//__________________________________________________________________
            void genbinary(int **m, int k, int bit){
            int n, i;


             n= pow(2, k);

             for(i=0; i<n/2; i++){
               m[i][bit-k]= 0;

             }
             for(i=n/2; i<n; i++){
               m[i][bit-k]= 1;

             }

  if( k==bit){

                return;
            }
             reflect(m, n, k, bit);

             genbinary(m, k+1, bit);



            return;
            }

//____________________________________________________________-
            void reflect(int **m, int n, int k, int bit){
            int i, j, l;
            for(l=bit; l>=bit-k; l--){
            for(i=n , j=n-1; i<n*2; i++, j--){
                m[i][l]=m[j][l];

                }
            }
            return;
            }
