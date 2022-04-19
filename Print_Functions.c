#include <stdio.h>
#include <stdlib.h>
#include "Graph_Project_Interface.h"

//////////////////////  PRINT SPARSE ARRAY LISTS // PRINT MST PATH // PRINT GRAPH CYCLES  //////////////////////////

void display(struct array *sparsearray)
{
  int i;
  for(i=0; i<sparsearray->V; i++){ 
    if(sparsearray->rowsHead[i]->next!=NULL){      
    printlist (sparsearray->rowsHead[i]);
    printf("\n");
    }
  }
}

void printlist(tp row)
{
  tp aux;
  aux = row;
  printf("(%d,%d)->\t",aux->i,aux->j);
  if (aux->next != NULL)
    printlist(aux->next);
}

void printPath(struct array *sparsearray,tp s, tp v)
{
  if(v==s){
    printf("%d->",s->i);
    return;
  }
  else if(v->parent==NULL) printf("\n no path from %d to %d exists\n",s->i,v->i);
  else printPath(sparsearray,s,v->parent);
  printf("%d->",v->i);
  
}

void printGraphCycles(struct array *sparsearray)
{
  int i;
  int V=sparsearray->V;
  tp aux,aux1,aux2,aux3;
  for (i=0;i<V;i++)
  {
      aux=sparsearray->rowsHead[i];
      while(aux->next!=NULL)
      {             
        aux=aux->next;
        if(aux->status==deactivated)
        { 
         printf("\ndeactivated edge (%d,%d) is detected, ",aux->i,aux->j);
         printf("the corresponding cycle is \n"); 
         aux1=sparsearray->rowsHead[(aux->i)-1];
         aux2=sparsearray->rowsHead[(aux->j)-1];
         if(aux1->d==aux2->d)
         {
          while(aux1->parent!=aux2->parent)
          {
            aux1=aux1->parent; 
            aux2=aux2->parent;          
          }
          printPath(sparsearray,aux1->parent,sparsearray->rowsHead[(aux->i)-1]);
          aux3=sparsearray->rowsHead[(aux->j)-1];
          printf("%d->",aux3->i);
          while(aux3->parent!=aux1->parent)  
          {
           printf("%d->",aux3->parent->i);
           aux3=aux3->parent;
           }
           printf("%d \n",aux3->parent->i);
          }
         if(aux1->d < aux2->d)
         {
          while(aux1->d != aux2->d) aux2=aux2->parent; 
          while(aux1->parent!=aux2->parent)
          {
            aux1=aux1->parent; 
            aux2=aux2->parent;          
          }
          printPath(sparsearray,aux1->parent,sparsearray->rowsHead[(aux->i)-1]);
          aux3=sparsearray->rowsHead[(aux->j)-1];
          printf("%d->",aux3->i);
          while(aux3->parent!=aux1->parent)  
          {
           printf("%d->",aux3->parent->i);
           aux3=aux3->parent;
           }
           printf("%d \n",aux3->parent->i);
         } 
        if(aux1->d > aux2->d)
         {
          while(aux1->d != aux2->d) aux1=aux1->parent; 
          while(aux1->parent!=aux2->parent)
          {
            aux1=aux1->parent; 
            aux2=aux2->parent;          
          }
          printPath(sparsearray,aux1->parent,sparsearray->rowsHead[(aux->i)-1]);
          aux3=sparsearray->rowsHead[(aux->j)-1];
          printf("%d->",aux3->i);
          while(aux3->parent!=aux1->parent)  
          {
           printf("%d->",aux3->parent->i);
           aux3=aux3->parent;
           }
           printf("%d \n",aux3->parent->i);
         }            
      }
    }
  }
}
