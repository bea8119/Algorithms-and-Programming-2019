#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define max_num 10
#define length (8+1)

typedef struct lett_s{
char c;
int val;
}lett_t;


int index_find(lett_t *letters, int lett_used, char tofind);
void setup(lett_t *letters, int *lett_used, char * w);
int test(lett_t *letters, int lett_used, int *index, char *w1, char *w2, char *w3);
int wordtonum(lett_t *letters, char *w, int lett_used);
int sol_check(lett_t *letters, int lett_used, char *w1, char *w2, char *w3);
int sol_find(lett_t *letters, int lett_used, int *index,  char *w1, char *w2, char *w3, int start );
void print_sol(lett_t *letters, int lett_used);
int main(int argv, char *argc[])
{

     lett_t  letters[max_num];
     int i;
     int index[max_num]={0};

     int lett_used=-1;

     if (argv!=4){
        printf( "ERROR ARGUMENTS\n");
        return 1;
     }
    char* w1;
    char* w2;
    char* w3;
    w1=strdup(argc[1]);
    w2=strdup(argc[2]);
    w3=strdup(argc[3]);

    for(i=0; i<max_num; i++){
        letters[i].c='\0';
        letters[i].val=-1;
    }
    int sel;
    setup(letters, &lett_used, w1);
    setup(letters, &lett_used, w2);
    setup(letters, &lett_used, w3);
 printf("%d", lett_used);
    for(i=0; i<=lett_used; i++){
        printf("%c\t", letters[i].c);
    }
            printf("\n\n\t1) to test an inserted solution\n\t2) to find a solution:\n");
            scanf("%d", &sel);

            switch (sel){
        case 1:
           test(letters, lett_used, index, w1, w2, w3);
          break;

        case 2:
           sel=sol_find(letters, lett_used, index, w1, w2, w3, 0 );
           if(sel!=1){
            printf("Solution not found??!!\n");
           }
            break;
            }

    return 0;
}


int index_find(lett_t *letters, int lett_used, char tofind){
int i;
for(i=0;  i<=lett_used; i++){

    if(letters[i].c==tofind){
        return i;
    }
}
return -1;
}


void setup(lett_t *letters, int *lett_used, char * w){
    int i;

for(i=0; i<strlen(w); i++){

    if(index_find(letters, *lett_used, w[i])==-1){
 *lett_used=*lett_used+1;

        letters[*lett_used].c=w[i];

    }
}
return;
}

int test(lett_t *letters, int lett_used, int *index, char *w1, char *w2, char *w3){
int i, tmp;
for(i=0; i<=lett_used; i++){
    printf("Insert value for %c: ", letters[i].c);
    scanf("%d",&tmp );

    if(tmp<max_num && tmp>=0 && index[tmp]==0){
        index[tmp]=1;
        letters[i].val=tmp;
    }else{
    printf("Try again...\n");
    i--;
    }
}

if(sol_check(letters, lett_used, w1, w2, w3)){
    printf("\nSolution valid!!!!\n");
}
else{
        printf("\nWrong...\n");
}
return 0;
}

int sol_check(lett_t *letters, int lett_used,  char *w1, char *w2, char *w3){

int n1, n2, n3;
n1=wordtonum(letters, w1, lett_used);
n2=wordtonum(letters, w2, lett_used);
n3=wordtonum(letters, w3, lett_used);

        if(n1==-1 || n2== -1 || n3== -1){
            return 0;
        }

return ((n1+n2)==n3);
}

int wordtonum(lett_t *letters, char *w, int lett_used){
int i, n=0;

if(letters[index_find(letters, lett_used, w[0])].val==0){
    return 0;
}

for(i=0; i<strlen(w); i++){
    n=n*10+(int) (letters[index_find(letters, lett_used, w[i])].val);

}

return n;
}

int sol_find(lett_t *letters, int lett_used, int *index,  char *w1, char *w2, char *w3 , int start){
int i;
if(start>lett_used){
    if(sol_check(letters, lett_used, w1, w2, w3)!=0){
    print_sol(letters, lett_used);
    return 1;
}
}


for(i=0; i<max_num; i++){
        if(index[i]==0){
            letters[start].val=i;
            index[i]=1;
            if(sol_find(letters,lett_used, index, w1,w2,w3, start+1))
                return 1;
            letters[start].val=-1;
            index[i]=0;
        }

}
return 0;

}

void print_sol(lett_t *letters, int lett_used){
int i;
printf("Solution found: \n");
for(i=0; i<=lett_used; i++){
    printf("%c = %d\n", letters[i].c, letters[i].val);
}

return;
}











