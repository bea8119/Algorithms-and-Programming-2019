        #ifndef _H1
        #define _H1

        #include <stdio.h>
        #include <stdlib.h>
        #include <string.h>




        typedef struct pos{
        int x;
        int y;
        }posit;

        char ** mall2(int r);
        char ** readfile(int *c, int *r, FILE *f_input);
        posit firstfind(char **m, int r, int c);
       int findpath(char **m,  posit *p, int coun);
       int blank(char **m, posit *p, int i);
        #endif  //_H1
