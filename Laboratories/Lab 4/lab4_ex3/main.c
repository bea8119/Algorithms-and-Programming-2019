#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct cyclist{
char name[31];
int id;
int n_laps;
float *times;
float average;

};
int main()
{
    int i=0, j=0, n_a, best=0;
    char command[10+1], reference[15+1];
    FILE * f_input;
    f_input=fopen("cyclist.txt", "r");
    if(f_input==NULL){
        fprintf(stderr, "Error opening the file\n");
        exit(EXIT_FAILURE);
    }

    struct cyclist *list;
    fscanf(f_input, "%d\n", &n_a);

    list=(struct cyclist *)malloc(n_a*sizeof(struct cyclist));
     if(list==NULL){
        fprintf(stderr, "Error Allocating memory\n");
        exit(EXIT_FAILURE);
    }
 printf(" ________\n");
    while(!feof(f_input)){

        fscanf(f_input, "%s %d %d \n",list[i].name, &list[i].id, &list[i].n_laps);
list[i].average=0;
        list[i].times=(float *)malloc(list[i].n_laps*sizeof(float));
printf("%s %d %d \n",list[i].name, list[i].id, list[i].n_laps );
        for(j=0; j<list[i].n_laps; j++){
            fscanf(f_input, "%f ", &list[i].times[j]);
            list[i].average=list[i].average+list[i].times[j];
        }
        list[i].average=list[i].average/list[i].n_laps;
        if(list[i].average<list[best].average){
            best=i;
        }
       // printf("%s %d %d",list[i].name, list[i].id, list[i].n_laps );
        for(j=0; j<list[i].n_laps; j++){
            printf("%.2f \n", list[i].times[j]);
        }
        i++;
        printf("\n");
    }

    do{
        printf("\n insert command:  ");
        scanf("%s", command);
        if(strcmpi(command, "list")==0){
            printf("\n There are %d athletes: \n", n_a);
            for(i=0; i<n_a; i++){
                printf("Name: %s Id: %d nuber laps: %d average: %.2f \n", list[i].name, list[i].id, list[i].n_laps, list[i].average);
            }

        }
        else if(strcmpi(command, "detail")==0){
            printf("\n insert name athlete: ");
            scanf("%s", reference);

            for(i=0; i<n_a; i++){
                if(strcmpi(list[i].name, reference)==0){
                    printf("Id: %d N laps: %d Average: %.2f\n", list[i].id, list[i].n_laps, list[i].average);
                }

            }
        }
        else if (strcmpi(command, "best")==0){
            printf("The best athlete is %s with an average of %.2f", list[best].name, list[best].average);
        }

    }while(strcmpi(command, "stop")!=0);
for(i=0; i<n_a; i++){
    free(list[i].times);
}
free(list);

    return 0;
}
