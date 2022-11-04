#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100


//int countwords(char m[max], char word[max]);
int main()
{
    int i, n_words, fcount[max];
    char m[max], word[max][20];
    FILE* f_text;
    FILE* f_words;

    f_text=fopen("f1.txt", "r");
    f_words=fopen("f2.txt", "r");


    fscanf(f_words, "%d \n", &n_words);
    printf("%d ---------\n", n_words);
    i=0;
    while(!feof(f_words)){
    fscanf(f_words, "%s \n", word[i]);
            printf("%s \n", word[i]);
            i++;
        }

for(i=0; i<n_words; i++){
    fcount[i]=0;
}

    while(!feof(f_text)){
           fscanf(f_text, "%s", m);

        for(i=0; i<n_words; i++){

        if(strcmpi(word[i], m)==0){

            fcount[i]++;
        }

        }


    }
    printf("Risultati: \n");
    for(i=0; i<n_words; i++){
        printf("%s occurres %d times \n", word[i], fcount[i]);
    }
    return 0;
}

/*int countwords(char m[max], char word[max]){
int i=0, j=0, c=0, flag=0;

while(i<strlen(m)){

        flag=0;
j=0;
    while(j<strlen(word) && flag!=1){
       if(m[i]==word[j]){
        j++;
       }
       else{
flag=1;
        j=0;

       }
       i++;
    }
    if(flag==0){
        c++;
        printf("\n funzione %s\n", word);
    }
}

return c;
}*/
