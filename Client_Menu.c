#include <stdio.h>
#include <stdlib.h>
#include "Graph_Project_Interface.h"



int main (int argc, char *argv[])
{
  int  i,n,edge_count;
  char choice;
  choice ='a';
 
  while(choice !='q')
  {
    printf("\n Welcome : As we start we need you to give us some information in order to create the undirected weighted graph you want to analyze");
    printf("\n Press '1' to proceed or 'q' to quit the program\t");
    fflush(stdin);
    choice=getchar();
    getchar();
    if(choice !='q')
    {
      struct array *sparsearray=create_sparsearray();
      int E=sparsearray->E;
      tp A[E];
      edge_count=0; 
	 
      while(choice != 'r')
       { 
        printf("\n Main Menu :Press : \n \t\t 'i' to insert an edge, \t 'd' to delete an edge, \t 'p' for graph display,");
        printf("\n \t\t 'b' to run BFS on graph, \t 'c' to deploy cycles,");
        printf("\n \t\t 'k' to perform Kruskal's Algorithm (MST),"); 
	    printf("\n \t\t 'r' to return to the beginning and create a new graph\n");
        printf("\n \t\t Give new choice :");
        choice ='a';
        fflush(stdin);
        choice=getchar();
        getchar();
        if (choice =='i')
         {
           printf("\n INSERT \n");
           insert(sparsearray,&edge_count,A);
         }
        if(choice=='d')
         { 
           printf("\n DELETE \n");
           delete1(sparsearray);
         }
        if (choice =='p')
         {
           printf("\n GRAPH DISPLAY \n ");
           display(sparsearray);
         }
        if (choice == 'b')
         {
           printf("\n Which node should be the source node?\n");
           scanf("%d",&i);
           BFS(sparsearray,sparsearray->rowsHead[i-1]);
        }
        if (choice=='c')
         {
          printGraphCycles(sparsearray);
         }
        if (choice=='k')
         { 
          KruskalMST(sparsearray,A);
	     }
      }
      graph_destroy(sparsearray,A);
   }
  else printf("\n QUIT");
 } 
     
 return 0;
 }
