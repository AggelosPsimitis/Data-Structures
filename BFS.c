#include <stdio.h>
#include <stdlib.h>
#include "Graph_Project_Interface.h"

///////////////  BREADTH FIRST SEARCH  //////////////////

void BFS(struct array *sparsearray, tp s)
{
  int k,m=0;
  int V=sparsearray->V;
  tp u, aux;
  struct Queue *Q=createQueue(V);
  for(k=0;k<V;k++)
  {
    sparsearray->rowsHead[k]->color=white;
    sparsearray->rowsHead[k]->parent=NULL;
    sparsearray->rowsHead[k]->d=0;
    aux=sparsearray->rowsHead[k];
    while(aux->next!=NULL) 
	{
	  aux->status=activated;
	  aux=aux->next;
    }
  }
  s->color=gray;
  s->parent=NULL;
  ENQUEUE(Q,s);
  printf("\nspanning tree 'branches' are :\n");
  while(Q->size>0)
  {
    u=DEQUEUE(Q);
    aux=u;
    while(aux->next!=NULL)
    {
      aux=aux->next;
      if(sparsearray->rowsHead[(aux->j)-1]->color==white){
        sparsearray->rowsHead[(aux->j)-1]->color=gray;
        sparsearray->rowsHead[(aux->j)-1]->parent=u;
        sparsearray->rowsHead[(aux->j)-1]->d=u->d+1;
        aux->status=activated;
        ENQUEUE(Q,sparsearray->rowsHead[(aux->j)-1]);
        printPath(sparsearray,s,sparsearray->rowsHead[(aux->j)-1]);
        printf("\n");
      }
      else if(sparsearray->rowsHead[(aux->j)-1]->color!=white&&sparsearray->rowsHead[(aux->j)-1]!=u->parent)
      { 
        m++;   
        aux->status=deactivated; 
      }
    }
      u->color=black;    
  }
  printf("\n The total number of cycles is : %d \n",m/2);
  free(Q);
}
