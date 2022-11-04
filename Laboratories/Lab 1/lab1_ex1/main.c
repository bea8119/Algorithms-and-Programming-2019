#include <stdio.h>
#include <stdlib.h>

#define dim 15
int main()
{

    int x[dim], longest[dim], count, start, i;
    printf("Insert numbers\n");
    for(i=0; i<dim; i++)  {
        scanf("%d", &x[i]);

    }
       count=0;
   int  prev_c=0, end, prev_s, prev_end;
    for(i=0; i<dim; i++){
      if(count==0){
        start=i;
        count++;
      }
      else if(x[i]>x[i-1]) {
        count++;
        end=i;
      }
      else {
        if(count>prev_c){
            prev_c=count;
            prev_s=start;
            prev_end=end;
            count=0;
        }

      }

    }

    printf("\n\n Longest sequence: \n");

for(i=prev_s; i<=prev_end; i++){
    printf("    %d\n", x[i]);
}
    return 0;
}
