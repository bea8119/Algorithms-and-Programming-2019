#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct rectangle{
char name[5];
float x1;
float y1;
float x2;
float y2;
float perimeter;
float area;
int flagp;
int flaga;
};

int main()
{
    struct rectangle list[10];
    int i, index=0, flag;
    float x, y;
    char rect[5], m[25];
    FILE* f_input;
    FILE* f_area;
    FILE* f_perim;

    f_input=fopen("f1.txt", "r");
    f_area=fopen("farea.txt", "w");
    f_perim=fopen("fperim.txt", "w");
   while(fgets(m, 24, f_input)!=NULL){
  //fscanf(f_input, "%s  %f %f \n", rect, &x, &y);

        sscanf(m,"%s  %f %f", rect, &x, &y);
        printf("# %s %f %f \n\n", rect, x, y);
        flag=0;
        for(i=0; i<index; i++){
            if(strcmp(rect, list[i].name)==0){
                list[i].x2=x;
                list[i].y2=y;
                list[i].perimeter=(abs(list[i].x2-list[i].x1)+abs(list[i].y2-list[i].y1))*2;
                list[i].area=abs(list[i].x2-list[i].x1)*abs(list[i].y2-list[i].y1);
                flag=1;
            }
        }
        if(flag==0){
            strcpy(list[index].name, rect);
            list[index].x1=x;
            list[index].y1=y;
            list[index].flagp=0;
            list[index].flaga=0;
            index++;

        }

    }
    int ord_perim[10];
    int ord_area[10];
    int max_per, max_area, j;
    for(j=0; j<index; j++){
            flag=0;
            i=0;
                while(i<index && flag==0){
                if(list[i].flagp==0){
                    flag=1;
                    max_per=i;

            }
             i++;
             }

   for(i=0; i<index; i++){


    if(list[max_per].perimeter<=list[i].perimeter && list[i].flagp==0){
        max_per=i;
    }
   }
   ord_perim[j]=max_per;
   list[max_per].flagp=1;

    }

    for(j=0; j<index; j++){
            flag=0;
            i=0;
                while(i<index && flag==0){
                if(list[i].flaga==0){
                    flag=1;
                    max_area=i;

            }
             i++;
             }

   for(i=0; i<index; i++){


    if(list[max_area].area<=list[i].area && list[i].flaga==0){
        max_area=i;
    }
   }
   ord_area[j]=max_area;
   list[max_area].flaga=1;

    }

    for(i=0; i<index; i++){
        fprintf(f_perim, "%s\n", list[ord_perim[i]].name);
        fprintf(f_area, "%s\n", list[ord_area[i]].name);
    }
    fclose(f_input);
    fclose(f_perim);
    fclose(f_area);
    return 0;
}

