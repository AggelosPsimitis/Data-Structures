#include <stdio.h>
#include <stdlib.h>
#include "Graph_Project_Interface.h"

///////////////////////////  HEAPSORT FUNCTIONS  ////////////////////////////////////

int right(int i)
{
	return 2*i+2;
}

int left(int i)
{
	return 2*i+1;
}
void Heapify(tp A[],int i,int E)
{
	int heap_size=E;
	tp temp;
	int largest;
	int l=left(i);
	int r=right(i);
	if (l<=heap_size && A[l]->weight>=A[i]->weight)	largest=l;
	else largest=i;
	if(r<=heap_size && A[r]->weight>=A[largest]->weight) largest=r;
	if(largest != i)
	{
	  temp=A[i];
	  A[i]=A[largest];
	  A[largest]=temp;
	  Heapify(A,largest,heap_size);
	}
}

void Build_Heap(tp A[],int E)
{
	int i;
	int heap_size=E;
	for(i=heap_size/2;i>=0;i--)
	{
		Heapify(A,i,heap_size);
	}
}

void Heapsort(tp A[],int E)
{	
	tp temp;
	int i;
	int heap_size=E-1;
	Build_Heap(A,heap_size);
	for(i=heap_size;i>=1;i--)
	{   
		temp=A[0];
		A[0]=A[i];
		A[i]=temp;
		heap_size=heap_size-1;
		Heapify(A,0,heap_size);
	}
	heap_size=E-1;
	for(i=0;i<=heap_size;i++) 
	{
	  printf("\n A[%d]=(%d,%d) with weight : %d\n",i,A[i]->i,A[i]->j,A[i]->weight);
    }
}
