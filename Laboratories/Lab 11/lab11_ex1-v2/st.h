#ifndef ST_H_DEFINED
#define ST_H_DEFINED

typedef struct symboltable *ST;
typedef struct STnode* link;

ST  	STinit(int) ;
void 	STinsert(ST, Item) ;
Item	STsearch(ST, Key) ;
void	STdelete(ST, Key) ;
void	STdisplay(ST, FILE*) ;
Item   ITEMget(link);
link NextPLink(link);

#endif
