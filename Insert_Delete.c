#include <stdio.h>
#include <stdlib.h>
#include "Graph_Project_Interface.h"

///////////////  FIND/INSERT/DELETE FUNCTIONS  ///////////////////////////

struct node *findedge(int i, int j, struct array *sparsearray)
  {
    tp aux = sparsearray->rowsHead[i-1];

    if(aux->next!=NULL)
      {
        while((aux->next!=NULL)&&(aux->next->j <=j))
        { 
          if(aux->next->j==j) return aux->next;    
          aux=aux->next;
        }
      }
    return NULL;
  }   
  
 
 void insert(struct array *sparsearray,int *edge_count, tp A[])
 {  
   tp temp, temp_sym; 
   temp=(tp)malloc(sizeof(struct node));
   temp_sym=(tp)malloc(sizeof(struct node));
   do{
   printf("\n which vertices do you want to link?\n");
   scanf("%d",&temp->i);
   //getchar();
   scanf("%d",&temp->j);
   //getchar();
     }while(temp->i > sparsearray->V||temp->i==0||temp->j > sparsearray->V||temp->j==0);
   printf("\n give the weight of edge (%d,%d) ",temp->i,temp->j);
   scanf("%d",&temp->weight);
   temp_sym->i=temp->j;
   temp_sym->j=temp->i;
   temp->next=NULL;
   temp->prev=NULL;
   temp->up=NULL;
   temp->down=NULL;
   temp_sym->next=NULL;
   temp_sym->prev=NULL;
   temp_sym->up=NULL;
   temp_sym->down=NULL;

   if((findedge(temp->i,temp->j,sparsearray)==NULL)&&(*edge_count<sparsearray->E))
   {
     insertRow(temp,sparsearray);
     insertCol(temp,sparsearray);
     A[*edge_count]=temp;
     //printf("\n A[%d]=(%d,%d)",*edge_count,A[*edge_count]->i,A[*edge_count]->j);
     *edge_count=*edge_count+1;

     
    
    if(temp->i != temp->j)    
      {
        insertRow(temp_sym,sparsearray);
        insertCol(temp_sym,sparsearray);
      }
    }
   else if(*edge_count>=sparsearray->E) printf("\n error: maximum number of edges reached\n");
   else  printf("\n this edge already exists \n");
  }

void insertRow(tp r, struct array *sparsearray) 
 {  
     tp aux;
                
   if (sparsearray->rowsHead[(r->i)-1]->next != NULL)
      {
         aux = sparsearray->rowsHead[(r->i)-1];
        
        while((r->j>aux->next->j)&&(aux->next!=NULL))
          {
            aux = aux->next;
          
          if(aux->next == NULL){
              aux->next = r;
              r->prev = aux;
            }
          }
          
          if(r->j < aux->next->j){
              r->prev = aux;
              r->next = aux->next;
              aux->next->prev = r;
              aux->next = r;
            }
      }
    
    else{  
          sparsearray->rowsHead[(r->i)-1]->next= r;
          r->prev = sparsearray->rowsHead[(r->i)-1];
        }
  }

void insertCol(tp c, struct array *sparsearray)  
 {  
     tp aux;
                
  if (sparsearray->colHead[(c->j)-1]->down != NULL){
          aux = sparsearray->colHead[(c->j)-1];
        
        while((c->i>aux->down->i)&&(aux->down!=NULL))
          {
            aux = aux->down;
          
          if(aux->down == NULL){
                aux->down = c;
                c->up = aux;
            }
          }
          
          if(c->i < aux->down->i){
            c->up = aux;
            c->down = aux->down;
            aux->down->up = c;
            aux->down = c;
          }
      }
  
  else{  
        sparsearray->colHead[(c->j)-1]->down= c;
        c->up = sparsearray->colHead[(c->j)-1];
      }
  }
   
void delete1(struct array *sparsearray)
{
  tp aux;
  int i,j;
  printf("\n which edge do you want to delete?\n");
  scanf("%d",&i);
  scanf("%d",&j);
  

  if(findedge(i,j,sparsearray)!= NULL)
    {
      aux=findedge(i,j,sparsearray);                   
      if(aux->next==NULL)
      {
       aux->prev->next=NULL;
       aux->prev=NULL;
      }
      else
      {
       aux->next->prev=aux->prev;
       aux->prev->next=aux->next;
       aux->next=NULL;
       aux->prev=NULL;
      }
      if(aux->down==NULL)
      {
       aux->up->down=NULL;                  
       aux->up=NULL;
      }
      else
      {
       aux->down->up=aux->up;
       aux->up->down=aux->down;
       aux->down=NULL;
       aux->up=NULL;
       }
      free(aux);
      
    if(i!=j)
      {
      aux=findedge(j,i,sparsearray);                  
      if(aux->next==NULL)
      {
       aux->prev->next=NULL;
       aux->prev=NULL;
      }
      else
      {
       aux->next->prev=aux->prev;
       aux->prev->next=aux->next;
       aux->next=NULL;
       aux->prev=NULL;
      }
      if(aux->down==NULL)
      {
       aux->up->down=NULL;                  
       aux->up=NULL;
      }
      else
      {
       aux->down->up=aux->up;
       aux->up->down=aux->down;
       aux->down=NULL;
       aux->up=NULL;
       }
      free(aux);
      }
    
    }
  else printf("\n edge does not exist \n");
}
void delete2(struct array *sparsearray, tp aux)
{
                     
      if(aux->next==NULL)
      {
       aux->prev->next=NULL;
       aux->prev=NULL;
      }
      else
      {
       aux->next->prev=aux->prev;
       aux->prev->next=aux->next;
       aux->next=NULL;
       aux->prev=NULL;
      }
      if(aux->down==NULL)
      {
       aux->up->down=NULL;                  
       aux->up=NULL;
      }
      else
      {
       aux->down->up=aux->up;
       aux->up->down=aux->down;
       aux->down=NULL;
       aux->up=NULL;
       }
      free(aux);
}
