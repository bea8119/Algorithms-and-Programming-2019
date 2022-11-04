#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

 /*  ------VERSION A-------
 struct index_t{
    char word[MAX_WORD_LENGTH+1];
    int occurrences;
  };*/
  // ------VERSION B------
struct index_t{
    char *word;
    int occurrences;
  };
int main()
{
    int i, n_words;
    char m[MAX_WORD_LENGTH];
    struct index_t *list;
    FILE* f_text;
    FILE* f_words;

    f_text=fopen("f1.txt", "r");
    f_words=fopen("f2.txt", "r");


    fscanf(f_words, "%d \n", &n_words);
    printf("%d ---------\n", n_words);
    list=(struct index_t *) malloc(n_words*sizeof(struct index_t));
    if(list==NULL){
        printf("n Error allocation 1 \n");
        exit(1);
    }
    i=0;
    while(!feof(f_words)){
    fscanf(f_words, "%s \n", m);
    list[i].word=strdup(m);
            printf("%s \n", list[i].word);
            i++;
        }

for(i=0; i<n_words; i++){
        list[i].occurrences=0;

}

    while(!feof(f_text)){
           fscanf(f_text, "%s", m);

        for(i=0; i<n_words; i++){

        if(strcmpi(list[i].word, m)==0){

            //fcount[i]++;
            list[i].occurrences++;
        }

        }


    }
    printf("Risultati: \n");
    for(i=0; i<n_words; i++){
        printf("%s occurres %d times \n", list[i].word, list[i].occurrences);
    }
    return 0;
}
