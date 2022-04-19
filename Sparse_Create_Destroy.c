#include <stdio.h>
#include <stdlib.h>
#include "Graph_Project_Interface.h"

//////////////////////////  SPARSE ARRAY (GRAPH) CREATE/DESTROY FUNCTIONS  ///////////////////////////////

struct array *create_sparsearray()
 {
 	int i,V,E;
 	printf("\n\n This is graph creation please give the number of vertices and edges: ");
    scanf("%d",&V);
    scanf("%d",&E);
 	struct array *sparsearray;
 	sparsearray =(struct array*)malloc(sizeof(struct array));
    sparsearray->rowsHead =(struct node**)malloc(V*sizeof(struct node*));
    sparsearray->colHead  =(struct node**)malloc(V*sizeof(struct node*));
    for (i=0;i<V;i++)
    {
      sparsearray->rowsHead[i]= (tp)malloc(sizeof(struct node)); 
      sparsearray->colHead[i] = (tp)malloc(sizeof(struct node));
      sparsearray->rowsHead[i]->next = NULL;
      sparsearray->colHead[i] ->down = NULL;
      sparsearray->rowsHead[i]->i=i+1;
      sparsearray->rowsHead[i]->j=0;
      sparsearray->colHead[i]->i=0;
      sparsearray->colHead[i]->j=i+1;
      sparsearray->rowsHead[i]->weight=0;
      sparsearray->colHead[i]->weight=0;
    }
    sparsearray->V=V;
    sparsearray->E=E;
    return sparsearray;
 }
 
 void graph_destroy(struct array *sparsearray,tp A[])
 {
 	int i;
 	tp aux;
 	for(i=0;i<sparsearray->E;i++)
 	{
 		A[i]=NULL;
 		free(A[i]);
	 }
	for(i=0;i<sparsearray->V;i++)
	{
		aux=sparsearray->rowsHead[i];
		while(aux->next!=NULL)
		{
			delete2(sparsearray,aux->next);
		}
		free(sparsearray->rowsHead[i]);
		free(sparsearray->colHead[i]);
	}
	free(sparsearray);
 }
