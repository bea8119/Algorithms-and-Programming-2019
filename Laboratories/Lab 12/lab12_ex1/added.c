#include "graph.h"
#include "queuePublic.h"

/*A. graph_bfs_count
   this is a copy of the BFS function which evaluates and returns
   the number of visited vertices in the graph.*/

 int  graph_bfs_count(graph_t *g, vertex_t *n){
queue_t *qp;
  vertex_t *d;
  edge_t *e;
    int count=0;
  qp = queue_init (g->nv);
  n->color = GREY;
  n->dist = 0;
  n->pred = NULL;
  queue_put (qp, (void *)n);

  while (!queue_empty_m (qp)) {

    queue_get (qp, (void **)&n);
    e = n->head;
    while (e != NULL) {
      d = e->dst;
      if (d->color == WHITE) {

	d->color = GREY;
	d->dist = n->dist + 1;
	d->pred = n;
	queue_put (qp, (void *)d);
      }

      e = e->next;
    }
     count++;
    n->color = BLACK;

  }
  queue_dispose (qp, NULL);

  return count;
 }


 /*B. graph_dfs_distance
   this is a copy of the BFS function which evaluates the highest
   distance of a node from the source vertex.
   In other words, this function evaluates the number of steps
   to reach, from the source node, the farthest vertex.*/

 int  graph_dfs_distance(graph_t *g, vertex_t *n){
 int currTime=0;
 int max=0;
 int fantoccio;
  vertex_t *tmp, *tmp2;


  currTime = graph_dfs_r2 (g, n, currTime, &fantoccio, &fantoccio, &fantoccio, &fantoccio);
  for (tmp=g->g; tmp!=NULL; tmp=tmp->next) {
    if (tmp->color == WHITE) {
      currTime = graph_dfs_r2 (g, tmp, currTime, &fantoccio, &fantoccio, &fantoccio, &fantoccio);
    }
  }


  for (tmp=g->g; tmp!=NULL; tmp=tmp->next) {
    tmp2 = tmp->pred;

    if(max<tmp->disc_time)
        max=tmp->disc_time;
  }

return max;
 }


 /*C. graph_dfs_type
   a copy of the DFS function, which performs the same operations of
   the DFS function, but in addition it evaluates and it returns the
   number of Tree edges, Forward edges, Backward edges and
   Cross edges encountered during the visit.*/

 void graph_dfs_type(graph_t *g, vertex_t *n, int * T, int * F, int * B, int * C){

int currTime=0;


  vertex_t *tmp, *tmp2;


  currTime = graph_dfs_r2 (g, n, currTime, T,F,B,C);
  for (tmp=g->g; tmp!=NULL; tmp=tmp->next) {
    if (tmp->color == WHITE) {
      currTime = graph_dfs_r2 (g, tmp, currTime, T,F,B,C);
    }
  }


  for (tmp=g->g; tmp!=NULL; tmp=tmp->next) {
    tmp2 = tmp->pred;

  }

return;

  }

int graph_dfs_r2(graph_t *g, vertex_t *n, int currTime, int * T, int * F, int * B, int * C ) {
  edge_t *e;
  vertex_t *tmp;

  n->color = GREY;
  n->disc_time = ++currTime;
  e = n->head;
  while (e != NULL) {
    tmp = e->dst;
    switch (tmp->color) {
      case WHITE: (*T)=(*T)+1;break;
      case GREY : (*B)=(*B)+1; break;
      case BLACK: if (n->disc_time < tmp->disc_time) {
                    (*F)=(*F)+1;
                  } else {
                    (*C)=(*C)+1;
                  }
    }
    if (tmp->color == WHITE) {
      tmp->pred = n;
      currTime = graph_dfs_r2 (g, tmp, currTime,  T,F,B,C );
    }
    e = e->next;
  }
  n->color = BLACK;
  n->endp_time = ++currTime;

  return currTime;
}

/*D. graph_dfs_depth
   a copy of the DFS function, which performs the same operations of
   the DFS function, but in addition it evaluates and it returns the
   depth of the DFS visit tree.*/

 int  graph_dfs_depth(graph_t *g, vertex_t *n, int level){
  edge_t *e;
  vertex_t *tmp;
        int maxLev=level;
        int newLev;
  n->color = GREY;

  e = n->head;
  while (e != NULL) {
    tmp = e->dst;

    if (tmp->color == WHITE) {
      tmp->pred = n;
       newLev= graph_dfs_depth(g, tmp, level+1) ;
       if(newLev>maxLev)
        maxLev=newLev;
    }
    e = e->next;
  }
  n->color = BLACK;


  return maxLev;
 }


/*E and F.
   graph_dfs_r_max_path
   a copy of the DFS function, which considers the graph as directed
   and weighted and it computes the length of the longest path
   starting at the source node and visiting each node of the graph
   at most once.
   The length of a path is defined as the sum of its edges.
   Write two versions of this function:
   - the first one works on generic graphs (with cycles).
   - the second one (simplified) works only on acyclic (and
     weighted) graphs.*/


int graph_dfs_r_max_path(graph_t *g, vertex_t *n){
int currTime=0;
int fantoccio;

  vertex_t *tmp, *tmp2;


  currTime = graph_dfs_r2 (g, n, currTime, &fantoccio, &fantoccio, &fantoccio, &fantoccio);
  for (tmp=g->g; tmp!=NULL; tmp=tmp->next) {
    if (tmp->color == WHITE) {
      currTime = graph_dfs_r2 (g, tmp, currTime, &fantoccio, &fantoccio, &fantoccio, &fantoccio);
    }
  }


  for (tmp=g->g; tmp!=NULL; tmp=tmp->next) {
    tmp2 = tmp->pred;

  }

return;


}







