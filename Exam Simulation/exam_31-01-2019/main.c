#include <stdio.h>
#include <stdlib.h>



typedef struct vertex_z{
char *id;
int col;
struct edge_z *edge;
struct vertex_z *next;
}vertex_t;

typedef struct edge_z{
struct vertex_z *vertex;
struct edge_z *next;
}edge_t;

typedef struct graph_z{
struct vertex_z *head;
}graph_t;


graph_t * read_file(FILE* fp);
graph_t *graph_init();
vertex_t *vertex_find(graph_t *graph, char *n);
vertex_t *vertex_add(graph_t *graph, char *n);
int main()
{
   graph_t *graph=NULL;
   vertex_t *vertex;
   char filename[31];
   FILE *fp;
   printf("Insert file name: \n");
   scanf("%s", filename);
   fp=fopen(filename, "r");
   graph=read_file(fp);

    return 0;
}



graph_t * read_file(FILE* fp){
char n1[101], n2[101];
graph_t *graph;
graph=graph_init();
vertex_t *v1, *v2;

while(fp!=EOF){
    fscanf(fp, "%s %s", n1, n2);

    v1=vertex_find(graph, n1);
    if(v1==NULL){
     graph=vertex_add(graph, n1);

        v1=graph->head;
    }
        v2=vertex_find(graph, n2);
    if(v2==NULL){
     graph=vertex_add(graph, n2);
        v2=graph->head;
    }
    edge_add(graph, v1, v2);

}

return graph;

}

int vertex_coloring(graph_t *graph, vertex_t *vertex, int n ){

        if(graph_colored(graph)==1){
            return n;
        }





return n;
}

