#include <stdio.h>
#include <stdlib.h>
#include<string.h>


typedef struct employees{
char *name;
char *id;
char *db;
int income;

struct employees *next;
struct employees *prev;
}list;

list *readfile(FILE *);
list *findstart(list *,  char *);
void printa(FILE *,list*, char *);
void cleanup(list *);

int main(int argc, char *argv[])
{

    if(argc!=4){
        fprintf(stderr, "COMMAND LINE ERROR!\n");
        exit(1);
    }
FILE *f_input;
f_input=fopen(argv[1], "r");
list *head;
list *temp;
list *tail;
head=readfile(f_input);
temp=head;
    do{
        tail=temp;
        temp=temp->next;
       }while (temp!=NULL);
temp=findstart(head, argv[2]);

fclose(f_input);

FILE *f_out;
f_out=fopen("out.txt", "w");
printa(f_out, temp, argv[3]);
 temp=head;
    while (temp!=NULL){
        printf("%s  - \n", temp->name);
        temp=temp->next;
    }

cleanup(head);
    return 0;
}

list *readfile(FILE *f_input){
    list *tmp, *head=NULL;
    char name[51], id[17], date[11];
    int income;
    while(fscanf(f_input,"%s %s %s %d \n",name, id, date, &income)!=EOF){

            tmp=(list*)malloc(sizeof(list));
    tmp->name=strdup(name);
    tmp->id=strdup(id);
    tmp->db=strdup(date);
    tmp->income=income;

        tmp->next=head;
        head=tmp;
          }
        list *q=NULL;
        tmp->prev=q;
        q=tmp;
        tmp=tmp->next;

    while(tmp!=NULL){
          tmp->prev=q;
          q=tmp;
          tmp=tmp->next;
          }

   return head;
}


list *findstart(list *head, char *name){
list *tmp;
tmp=head;
while( tmp!=NULL ){

     if(strcmp(tmp->name, name)==0){
        return tmp;
     }
    tmp=tmp->next;
}
return NULL;
}

void printa(FILE *fout,list *start, char *str){
int i=0;

 fprintf(fout, "%s %s %s %d\n", start->name, start->id, start->db, start->income);
while(i<=strlen(str)){

  if(str[i]=='-'){
if(start->prev!=NULL){
        start=start->prev;
        }
    fprintf(fout, "%s %s %s %d\n", start->name, start->id, start->db, start->income);


  } else if(str[i]=='+'){
      if(start->next!=NULL){
        start=start->next;
        }
        fprintf(fout, "%s %s %s %d\n", start->name, start->id, start->db, start->income);

    }
    i++;
}

}

void cleanup(list *head){
list *tmp;
 while(head!=NULL){
   tmp=head;
    head=head->next;
    free(tmp->name);
    free(tmp->id);
    free(tmp->db);
    free(tmp);

 }

}
