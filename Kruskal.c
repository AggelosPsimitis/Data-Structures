#include <stdio.h>
#include <stdlib.h>
#include "Graph_Project_Interface.h"

///////////////////// KRUSKAL'S ALGORITHM FOR MST ////////////////////////

struct node *find_set(struct array *sparsearray,tp v)
{   
	if(v->parent!=v)
	{
	  v->parent=find_set(sparsearray,v->parent);
	}
	return v->parent;
}

void Union(struct array *sparsearray,tp x,tp y)
{
	tp xroot=find_set(sparsearray,x);
	tp yroot=find_set(sparsearray,y);
	if (xroot->d<yroot->d)
	{
		xroot->parent=yroot;
	}
	else if (xroot->d>yroot->d)
	{
		yroot->parent=xroot;
	}
	else if (xroot->d==yroot->d)
	{
		yroot->parent=xroot;
		xroot->d=xroot->d+1;
	}
}


void KruskalMST(struct array *sparsearray,tp A[])
{
  int v,e=0,k=0,n;	
  int V=sparsearray->V;
  int E=sparsearray->E;
  tp result_table[E];
  printf("\n These are the edges of graph sorted in non decreasing order by weight");
  Heapsort(A,E);
  for(v=0;v<V;v++)
  {
  	sparsearray->rowsHead[v]->parent=sparsearray->rowsHead[v];
  	sparsearray->rowsHead[v]->d=0;
  }
  while(e<E)
  {
  	tp x=find_set(sparsearray,sparsearray->rowsHead[(A[e]->i)-1]);
  	tp y=find_set(sparsearray,sparsearray->rowsHead[(A[e]->j)-1]);
  	if (x!=y)
  	{
  		Union(sparsearray,x,y);
  		result_table[k]=A[e];
  		k++;
	}
	e++;
  }
  printf("\n Kruskal Gives Following Minimum Spanning Tree\n");
  for(n=0;n<k;n++)
  {
  	if(result_table[n]!=NULL)
  	{
  	 printf("\n %d -> %d (%d) \n",result_table[n]->i,result_table[n]->j,result_table[n]->weight);
    }
    result_table[n]=NULL;
    free(result_table[n]);
  }
}
