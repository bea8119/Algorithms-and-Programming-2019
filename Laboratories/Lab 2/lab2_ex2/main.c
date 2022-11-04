#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    char m[100];
    int v[100];
    for(int i=0; i<100; i++){
        v[i]=0;
    }
    char filename[30];
    printf("insert name file\n");
    scanf("%s", filename);
    FILE* f_input;
    f_input=fopen(filename, "r");
    int i=0, j;
    int counth=0, fcounth=0, fcountv=0;
    while(!feof(f_input)){

           while(fgets(m, 100, f_input)!=NULL) {
                printf("%s \n", m);
                counth=0;

            for(j=0; j<strlen(m); j++){
              if(m[j]=='h'){
                counth++;


              }

              else if( m[j]!='h'){

                counth=0;
              }
if (counth==5){
    fcounth++;
    printf("%d %d \n",j, fcounth);
    counth=0;
}
              if(m[j]=='v'){
                v[j]++;
              }
            }


           }
    }
    for(j=0; j<100; j++){
        if(v[j]>=5){
            fcountv=fcountv+v[j]/5;
        }
    }
printf("\n horizontal: %d\n vertical: %d", fcounth, fcountv);

    return 0;
}
