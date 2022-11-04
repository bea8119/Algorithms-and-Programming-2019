#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100

int searchstring(char m[], char str[], int from);
int main(int argc, char* argv[])
{
    char string1[21], string2[21], file1[max], file2[max], m[max], out[max];
    int i,j,count, start, from=0, to, index, endflag;
    printf("%d %s %s %s %s", argc, argv[1], argv[2], argv[3], argv[4]);
    if(argc!=5){
        return 1;
    }
    strcpy(string1, argv[1]);
    strcpy(file1, argv[2]);
    strcpy(string2, argv[3]);
    strcpy(file2, argv[4]);

    FILE* f_input;
    FILE* f_output;

    f_input=fopen(file1, "r");
    f_output=fopen(file2, "w");

    while(!feof(f_input)){
        while(fgets(m, 100, f_input)!=NULL){
                from=index=endflag=0;
                do{


        to=searchstring(m, string1, from);
        if(to<0){
            to=strlen(m);
            endflag=1;
        }
        for(i=from; i<to; i++){
            out[index]=m[i];
            index++;
        }
        for(i=0; i<strlen(string2); i++){
        out[index]=string2[i];
        index++;
        }
        from=to+strlen(string2);


        }while(endflag!=1);
        out[index]='\0';
        fprintf(f_output, "%s\n", out);
        printf("%s\n", out);
        }


    }

    fclose(f_input);
    fclose(f_output);
    return 0;
}


int searchstring(char m[], char str[], int from){
int i, j, flag;
i=from;
while(i< strlen(m)-strlen(str)){
    flag=j=0;
    while(j<strlen(str) && flag==0){

        if(m[i+j]!=str[j]){
            flag=1;
        }
        j++;
    }
    if(flag==0){
        return i;
    }
    i++;
}

    return -1;
}


