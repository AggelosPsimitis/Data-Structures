#include <stdio.h>
#include <stdlib.h>
#include "Graph_Project_Interface.h"

///////////////////////  QUEUE FUNCTIONS  //////////////////////////

struct Queue *createQueue(int V) 
{ 
  int i;    
  struct Queue *Q;
  Q=(struct Queue*)malloc(sizeof(struct Queue));
  Q->elements=(struct node**)malloc(V*sizeof(struct node*));
  for(i=0;i<V;i++)
   {
   Q->elements[i]=(tp)malloc(sizeof(struct node));
    }
  Q->size=0;
  Q->capacity=V-1;
  Q->head=0;
  Q->tail=-1;
  return Q;
}


void ENQUEUE(struct Queue *Q,tp x)
{
  if (Q->size==Q->capacity){
        printf("\n overflow error: queue is full \n");
        return;
      }   
  Q->tail=Q->tail+1;    
  Q->elements[Q->tail]=x;
  Q->size++;
  if(Q->tail==Q->capacity){
      Q->tail=0;
    }
  return;
}

struct node *DEQUEUE(struct Queue *Q)
{
  tp x;
  if(Q->size==0){
    printf("\n underflow error: queue is empty \n");
    return NULL;
  }
  x=Q->elements[Q->head];
  if(Q->head==Q->capacity){
    Q->head=0;
    Q->size--;
  }
  else 
    {
      Q->size--;
      Q->head++;
    }
  return x;
}

















