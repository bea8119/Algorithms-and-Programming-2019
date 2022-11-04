#include <stdio.h>
#include <stdlib.h>


typedef struct pipe_z{
char col;
int val;
int flag;
}pipe_t;

pipe_t ** read_file_tiles(FILE* fp, int *dim);
pipe_t ***read_file_board(FILE* fp, int *R, int *C, pipe_t **tile);
int check_config(pipe_t ***board, int R, int C);
void complete_board(pipe_t ***board, pipe_t ***sol, pipe_t **tiles, int *ris, int R, int C, int ind );
pipe_t ***clear_board(pipe_t ***board, int R, int C);
int main(int argv, char **argc)
{
    int i,j;
    int dim, R, C;
    pipe_t **tiles;
    pipe_t ***board, ***sol;
        FILE *fp;
        FILE *fboard;
        FILE *out;
        if(argv!=4){
            printf("ERROR ARGUMENTS\n");
            return 1;
        }
        fp=fopen(argc[1], "r");
        fboard=fopen(argc[2], "r");
        out=fopen(argc[3], "w");

        tiles=read_file_tiles(fp, &dim);

    board=sol=read_file_board(fboard, &R, &C, tiles);

  /*  printf("\n\nBOARD PRINTING\n");
    for(i=0; i<R; i++){
        for(j=0; j<C; j++){
            printf("\t(%c %d, %c %d)\t ",board[i][j][0].col,board[i][j][0].val,board[i][j][1].col,board[i][j][1].val);
        }
            printf("\n");
    }*/
int ris=0;
    if((i=check_config(board,R, C))==-1){
        printf("Board not complete, completing now...\n");

        complete_board(board, sol, tiles, &ris, R, C, 0 );


        fprintf(out,"%d %d\n", R, C);
    for(i=0; i<R; i++){
        for(j=0; j<C; j++){
            fprintf(out, "\t(%c %d, %c %d)\t ",sol[i][j][0].col,sol[i][j][0].val,sol[i][j][1].col,sol[i][j][1].val);
        }
            fprintf(out, "\n");
}
}
    else{
         printf("The max sum is %d", i);
    }


for(i=0; i<dim; i++)
    free(tiles[i]);
free(tiles);

for(i=0; i<R; i++){
    for(j=0; j<C; j++){
        free(board[i][j]);
    }
    free(board[i]);
}
free(board);
fclose(fp);
fclose(fboard);
fclose(out);
    return 0;
}


pipe_t ** read_file_tiles(FILE* fp, int *dim){
            int i, val1, val2;
            char col1, col2;
            pipe_t **tiles;
            fscanf(fp,"%d ", dim);
            tiles=(pipe_t**)malloc((*dim)*sizeof(pipe_t*));
            if(tiles==NULL){
                printf("ERROR allocation \n");
                return NULL;
            }

            for(i=0; i<*dim; i++){
                    tiles[i]=(pipe_t*)malloc(2*sizeof(pipe_t));
            if(tiles[i]==NULL){
                printf("ERROR allocation \n");
                return NULL;
            }
                fscanf(fp, "%c %d %c %d ", &col1, &val1, &col2, &val2);
                tiles[i][0].col=col1;
                tiles[i][0].val=val1;
                 tiles[i][1].col=col2;
                tiles[i][1].val=val2;
                tiles[i][0].flag=tiles[i][1].flag=0;
            }
            return tiles;
            }

pipe_t ***read_file_board(FILE* fp, int *R, int *C, pipe_t **tile){
    pipe_t ***board;
    int i,j;
    int index, orient;
        fscanf(fp, "%d %d", R, C);
        board=(pipe_t***)malloc((*R)*sizeof(pipe_t**));
        if(board==NULL){
                printf("ERROR allocation \n");
                return NULL;
        }
    for(i=0; i<*R; i++){
        board[i]=(pipe_t**)malloc((*C)*sizeof(pipe_t*));

            if(board[i]==NULL){
                printf("ERROR allocation \n");
                return NULL;
            }
            for(j=0; j<*C; j++){
                    board[i][j]=(pipe_t*)malloc(2*sizeof(pipe_t));
                    if(board[i][j]==NULL){
                printf("ERROR allocation \n");
                return NULL;
            }

                fscanf(fp, "%d /%d ", &index, &orient);
                if(index!=-1){

                       if(orient==0){
                    board[i][j][0]=tile[index][0];
                    board[i][j][1]=tile[index][1];

                }
                else{
                    board[i][j][1]=tile[index][0];
                    board[i][j][0]=tile[index][1];
                }
                tile[index][0].flag=tile[index][1].flag=1;
                board[i][j][0].flag=board[i][j][1].flag=1;
                }
                else{
                    board[i][j][0].col=board[i][j][1].col='\0';
                    board[i][j][0].val=board[i][j][1].val=-1;
                    board[i][j][0].flag=board[i][j][1].flag=0;
                }

            }
    }
    return board;
    }

    int check_config(pipe_t ***board, int R, int C){
    int i, j;
    char c;
    int sum=0;
    int part_s=0;
        for(i=0; i<R; i++){
        for(j=0; j<C; j++){
          if(board[i][j][0].val==-1 && board[i][j][1].val==-1)
            return -1;
                c=board[i][0][0].col;
                 part_s=part_s+board[i][j][0].val;
                if(c!=board[i][j][0].col){
                    j=C;
                    part_s=0;
                }
        }
        sum=sum+part_s;
        part_s=0;
      ;
    }

          for(j=0; j<C; j++){
        for(i=0; i<R; i++){

                c=board[0][j][1].col;
                 part_s=part_s+board[i][j][1].val;

                if(c!=board[i][j][1].col){
                    i=R;
                    part_s=0;
                }
        }
        sum=sum+part_s;
        part_s=0;
    }

    return sum;
    }

void complete_board(pipe_t ***board, pipe_t ***sol, pipe_t **tiles, int *ris, int R, int C, int ind){
int k, i, j;
if(ind==R*C){
        int r=check_config(board, R, C);
        if(r>*ris){
            *ris=r;
            sol=board;
        }
        else
            board=clear_board(board, R, C);
        return;
        }

        i=ind/C;
        j=ind%C;
        if(board[i][j][0].flag==0 ){
            for(k=0; k<R*C; k++){

                if(tiles[k][0].flag==0){
                    tiles[k][0].flag=2;
                    board[i][j][0].col=tiles[k][0].col;
                    board[i][j][0].val=tiles[k][0].val;
                    board[i][j][1].col=tiles[k][1].col;
                    board[i][j][1].val=tiles[k][1].val;
                    board[i][j][0].flag=1;
                        complete_board(board, sol, tiles, ris, R, C, ind+1);
                        board[i][j][1].col=tiles[k][0].col;
                    board[i][j][1].val=tiles[k][0].val;
                    board[i][j][0].col=tiles[k][1].col;
                    board[i][j][0].val=tiles[k][1].val;
                        complete_board(board, sol, tiles, ris, R, C, ind+1);
                     tiles[k][0].flag=0;
                     board[i][j][0].flag=0;
                }
        }
        }
        else
            complete_board(board, sol, tiles, ris, R, C, ind+1);
        return;

}

pipe_t ***clear_board(pipe_t ***board, int R, int C){
    int i, j;

    for(i=0; i<R; i++){
        for(j=0; j<C; j++){
            if(board[i][j][0].flag!=1){
                board[i][j][0].col=board[i][j][1].col='\0';
                    board[i][j][0].val=board[i][j][1].val=-1;
                    board[i][j][0].flag=board[i][j][1].flag=0;
            }  } }

    return board;
}



