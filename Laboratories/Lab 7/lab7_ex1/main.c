#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct producer{
char *name;
char *code;

struct producer *next;
}PRODUCER;

typedef struct product{
char *code;
char *n_car;
int price;
struct product *next;
}PRODUCT;

PRODUCER *readfile1(FILE*);
PRODUCT *readfile2(FILE*);

void printall(PRODUCER *, PRODUCT *, char *);
void cleanup(PRODUCER *, PRODUCT*);
int main(int argc, char *argv[])
{

    if (argc!=3)
        return 1;
    FILE* f_1;
    FILE* f_2;
    PRODUCER *head1;
    PRODUCT *head2;
    f_1=fopen(argv[1], "r");
    f_2=fopen(argv[2], "r");

    head1= readfile1(f_1);
    head2= readfile2(f_2);
    char instruction[21];
    printf("Insert name car company- insert stop to end the program: \n");
            scanf("%s", instruction);
    while(strcmpi(instruction, "stop")!=0){
        printall(head1, head2,  instruction);
        printf("Insert name car company- insert stop to end the program: \n");
            scanf("%s", instruction);
    }

    return 0;
}

PRODUCER *readfile1(FILE* f_input){
PRODUCER *head=NULL;
PRODUCER *tmp;
char name[21];
char code[21];
while(fscanf(f_input, "%s %s", name, code)!=EOF){
    tmp=(PRODUCER*)malloc(sizeof(PRODUCER));
    tmp->name=strdup(name);
    tmp->code=strdup(code);
    tmp->next=head;
    head=tmp;
}

return head;
}

PRODUCT *readfile2(FILE* f_input){
 PRODUCT *head=NULL;
PRODUCT *tmp;
char name[21];
char code[21];
int price;
while(fscanf(f_input, "%s %s %d",  code, name, &price)!=EOF){
    tmp=(PRODUCT*)malloc(sizeof(PRODUCT));

    tmp->code=strdup(code);
    tmp->n_car=strdup(name);
    tmp->price;
    tmp->next=head;
    head=tmp;
}

return head;

}

void printall(PRODUCER *head1, PRODUCT *head2, char *company){

PRODUCER *tmp1;
PRODUCT *tmp2;
tmp1=head1;
tmp2=head2;
while(tmp1!=NULL && strcmpi(tmp1->name, company)!=0){
        tmp1=tmp1->next;
        if(tmp1==NULL){
                printf("No Match found...\n");
             return;
        }

}
printf("\nLIST:\n");
while(tmp2!=NULL){
        if(strcmp(tmp1->code, tmp2->code)==0){
            printf("- %s: %d Euro\n", tmp2->n_car, tmp2->price);
        }
    tmp2=tmp2->next;
      if(tmp2==NULL){
                printf("\n____________\n\n");
             return;
        }
}

}

void cleanup(PRODUCER *head1, PRODUCT *head2 ){
PRODUCER *tmp1;
PRODUCT *tmp2;


while(head1!=NULL){
   tmp1=head1;
    head1=head1->next;
    free(tmp1->name);
    free(tmp1->code);
    free(tmp1);
 }
 while(head2!=NULL){
   tmp2=head2;
    head2=head2->next;
    free(tmp2->n_car);
    free(tmp2->code);
    free(tmp2);
 }

}

