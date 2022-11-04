#include <stdio.h>
#include <stdlib.h>

#define dim 100
int main()
{
    int n1, n2, v1[dim],  i, count, j;
    float v2[dim], sum;
    printf("insert n1 and n2:\n");
    scanf("%d %d", &n1, &n2);

    if(n1>dim || n2>dim){
            printf("Error \n");
        return 1;
    }

    printf("\n Insert v1 of %d numnbers", n1);

    for(i=0; i<n1; i++){
        scanf("%d", &v1[i]);
    }
    int c;

   for(i=0; i<n1; i++){
    count=1;
    sum=v1[i];

    if(i<(n1-n2) && i>(n2)){
       for(j=1;j<=n2; j++){
            printf("controllo somma numer %d... %.2f counter %d \n",i, sum, count);
        sum=sum+v1[i-j]+v1[i+j];
        count=count+2;

    }
    }
else if(i<=n2){
     for(j=1;j<=n2; j++){
        sum=sum+v1[i+j];
        count++;
    }
    for(j=i;j>0; j--){
      sum=sum+v1[i-j];
        count++;
    }
}
else if(i>=(n1-n2)){
     for(j=1;j<=n2; j++){
        sum=sum+v1[i-j];
        count++;
    }
    for(j=1;j<n1-i; j++){
      sum=sum+v1[i+j];
        count++;
    }
}
   v2[i]=sum/count;

   }

    printf(" \n\n\n\ jdsjsdvsdvc");
    for(i=0; i<n1; i++){
        printf(" %.2f \n", v2[i]);
    }


    return 0;
}
