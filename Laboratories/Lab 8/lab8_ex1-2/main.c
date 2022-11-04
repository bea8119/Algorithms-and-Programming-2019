#include <stdio.h>
#include <stdlib.h>

int **mall2(int R);
int findsquare(int  n, int** m, int k, int sum, int *used);
int check(int  n, int** m, int sum);



int main(int argc, char *argv[])
{
    if (argc!=3)
    {
        printf("Command error!");
        exit(1);
    }

    int x=atoi(argv[1]);
    FILE *fout;
    fout=fopen(argv[2], "w");
    int **mat;
    int *used;
    int i, j;
    used=(int *)malloc((x*x+1)*sizeof(int));
    if(used==NULL)
    {
        printf("ERROR ALLOC");
        exit(1);
    }
    for(i=0; i<=x*x; i++)
        used[i]=0;
    mat=mall2(x);

    int sum;
    sum=x*((x*x)+1)/2;
    int r=findsquare(x, mat, 0, sum, used);
    printf("risultato : %d", r);
    if(r==1)
    {

        printf("Matrix found!\n");
        for(i=0; i<x; i++)
        {
            for(j=0; j<x; j++)
            {
                printf("%d  ", mat[i][j]);
            }
            printf(" \n ");
        }
    }
    else
    {
        printf("\nMatrix not found\n");
    }
puts("   ") ;
for(i=0; i<x; i++)
        {
            for(j=0; j<x; j++)
            {
                printf("%d  ", mat[i][j]);
            }
            printf(" \n ");
        }
    free(used);
    for(i=0; i<x; i++)
    {
        free(mat[i]);
    }
    free(mat);
    fclose(fout);
    return 0;
}
//____________________________________________________
int **mall2(int R)
{
    int **m;

    int i,j;
    m=(int**)malloc(R*sizeof(int*));
    if(m==NULL)
    {
        fprintf(stderr, "ERROR ALLOCATING 1!\n");
        exit(EXIT_FAILURE);
    }
    for( i=0; i<R; i++)
    {
        m[i]=(int*)malloc(R*sizeof(int));
        if(m[i]==NULL)
        {
            fprintf(stderr, "ERROR ALLOCATING 2!\n");
            exit(EXIT_FAILURE);
        }
        for(j=0 ; j<R; j++){
            m[i][j]=-1 ;
        }

    }
    return m;
}

//_____________________________________________________________________________________________

int findsquare(int  n, int** m, int k, int sum, int *used)
{

    int i, j, val;

    if( k==n*n)
    {

       if( check( n, m,  sum ))
       {
           printf("PROVA \n");
        return 0;
        }

    }

    i=k/n;
    j=k%n;
    for(val=0; val<=n*n; val++){
        if(used[val]==0){
            m[i][j]=val+1;
            used[val]=1;

            if(findsquare(n, m, k+1, sum, used)==1){
                printf("EEEh \n");
            return 0;
            }

                used[val]=0;
        }
    }
    return 1;
}



//__________________________________________________________________________________________________________________

int check(int  n, int** m, int sum)
{
    int s, i, j;
printf(" summ : %d\n", sum);
    for(i=0; i<n; i++)
    {
        s=0;
        for(j=0; j<n; j++)
        {
            s+=m[i][j];

        }
        if(s!=sum)
        {

            return 1;
        }
    }

    for(j=0; j<n; j++)
    {
        s=0;
        for(i=0; i<n; i++)
        {
            s+=m[i][j];

        }
        if(s!=sum)
        {
            puts("rgdgdf ") ;
            return 1;
        }
    }
    s=0;
    for(i=0; i<n; i++)
    {
        s+=m[i][i];
    }
    if(s!=sum)
    {
        return 1;
    }

    s=0;
    for(i=0; i<n; i++)
    {
        s+=m[i][n-1-i];
    }

    if(s!=sum)
    {
        return 1;
    }

    return 0;
}

