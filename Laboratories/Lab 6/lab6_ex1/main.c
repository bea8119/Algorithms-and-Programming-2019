#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
typedef struct list_s{
char *word;
int times;
struct list_s *next;
}list_t;

list_t *readfile(FILE *);
list_t *wordfind(list_t *, char * );
void clean(list_t *);

int main(int argc, char * argv[])
{
    list_t *head=NULL, *tmp;

    if(argc!=2){
            fprintf(stderr, "ERROR COMMAND\n");
        exit(1);
    }


    FILE * f_input;
    f_input=fopen(argv[1], "r");
        head=readfile(f_input);
    fclose(f_input);


    tmp=head;
    while (tmp!=NULL){
        printf("%s  %d", tmp->word, tmp->times );
        tmp=tmp->next;
    }
  clean(head);

    return 0;
}
            // TAIL INSERTION
/*list_t *readfile(FILE *f_input){
    list_t *tmp, *head=NULL, *q=NULL ;

    char word[MAX];

    while(fscanf(f_input, "%s", word)!=EOF){

        tmp=wordfind(head, word);

        if(tmp!=NULL){
            tmp->times++;
        }else{
            if(head==NULL){
                tmp=(list_t *)malloc(sizeof(list_t));
        tmp->word=strdup(word);
        tmp->times=1;
        tmp->next=head;
        head=tmp;
        q=tmp;
            }else{
             tmp=(list_t *)malloc(sizeof(list_t));
        tmp->word=strdup(word);
        tmp->times=1;
        tmp->next=NULL;

         while(q->next !=NULL){
            q=q->next;
         }
         q->next=tmp;
            }
        }
    }

return head;
}*/

            // HEAD INSERTION
 list_t *readfile(FILE *f_input){
    list_t *tmp, *head=NULL;

    char word[MAX];

    while(fscanf(f_input, "%s", word)!=EOF){

        tmp=wordfind(head, word);

        if(tmp!=NULL){
            tmp->times++;
        }else{
        tmp=(list_t *)malloc(sizeof(list_t));
        tmp->word=strdup(word);
        tmp->times=1;
        tmp->next=head;
        head=tmp;
        }

    }

return head;
}


list_t *wordfind(list_t *head, char *word ){
    list_t *tmp;
    tmp=head;

while(tmp!=NULL){
    if(strcmpi(tmp->word, word)==0){
        return tmp;
    }

    tmp=tmp->next;
    }

    return NULL;
}

void clean(list_t *head){
list_t *tmp;
 while(head!=NULL){
    tmp=head;
    head=head->next;
    free(tmp->word);
    free(tmp);
 }

}
