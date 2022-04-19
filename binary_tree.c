#include<stdio.h>
#include<stdlib.h>

struct node
{
	int key;
	struct node *left;
	struct node *right;
	struct node *parent;
};

struct Tree
{
	struct node *root;
};

void insert(struct Tree *T,int key);							
struct node *tree_search(struct node *x,int key);				//Recursive functions which finds if a node is already in the tree
void Delete(struct Tree *T,int key);
void transplant(struct Tree *T,struct node *u,struct node *v);	//Assistant function for delete, replaces u's and v's parent pointers
struct node *minimum(struct node *x);
void inorder_print1(struct Tree *T,struct node *x);				//We use inorder print function and call print paths inside to print all branches of the tree from root to all leaves
void inorder_print(struct node *x);								//Regural inorder print function that prints nodes regarding their keys from minimum to maximum
void print_path(struct node *u,struct node *v); 				//It prints the path from node u to node v following parent pointers 
	

int main()
{
	int data;
	struct Tree *T=malloc(sizeof(struct Tree));
	T->root=NULL;
	char choice;

	
	while(choice !='q')
	{
		printf("Main Menu:\tPress 'i' to insert a node in tree, press 'd' to delete a node from tree\n");
		printf("\t\tPress 'p' to print paths of tree, press 'o' for inorder print or press 'q' to quit\n");
		printf("\t\tGive new choice:");
		choice='a';
		fflush(stdin);
		choice=getchar();
		getchar();
		
		if(choice == 'i')
		{
			printf("\nGive the key you want to insert:\t");
			scanf("%d",&data);
			if (tree_search(T->root,data)==NULL)
			{
				insert(T,data);
			}
			else printf("\nThis node already exists\n");
		printf("\n\n");
		}
	    
	    if(choice == 'd')
	    {
	    	printf("\nGive the key you want to delete:\t");
	    	scanf("%d",&data);
	    	Delete(T,data);
	    	printf("\n\n");
		}
		
		if(choice == 'p')
		{
			if(T->root!=NULL)
			{
				printf("\nThe root of the tree is %d\n",T->root->key);
				printf("\nThe tree paths are:\n");
				inorder_print1(T,T->root);
			}
			else printf("\nThe tree is empty");
			printf("\n\n");
		}	
		
		if(choice == 'o')
		{
			if(T->root!=NULL)
			{
				printf("\nThe root of the tree is %d\n",T->root->key);
				printf("\nInorder print is:");
				inorder_print(T->root);
			}
			else printf("\nThe tree is empty");
			printf("\n\n");
		}
	}
	printf("\nQUIT\n");
	return 0;	
}



void inorder_print(struct node *x)
{
	if(x!=NULL)
	{
		inorder_print(x->left);
		printf("%d,",x->key);
		inorder_print(x->right);
	}
}


void inorder_print1(struct Tree *T,struct node *x)  
{
	if(x!=NULL)
	{
		inorder_print1(T,x->left);
		if((x->left==NULL)&&(x->right==NULL))
		{
			print_path(T->root,x);
			printf("\n\n");
		}
		inorder_print1(T,x->right);
	}
}

void print_path(struct node *u,struct node *v)
{
	if(v==u)
	{
		printf("%d->",u->key);
		return;
	}
	else if(v->parent==NULL)
	{
		printf("\nNo path from %d to %d exists\n",u->key,v->key);
	}
	else print_path(u,v->parent);
	printf("%d->",v->key);
}


struct node *tree_search(struct node *x,int data) 
{
	if (x == NULL || data == x->key ) return x;
	if(data<x->key) return tree_search(x->left,data);
	else if(data>x->key) return tree_search(x->right,data);
}


struct node *minimum(struct node *x) 
{
	while(x->left!=NULL)
	{
		x = x->left;
	}
	return x;
}


void insert(struct Tree *T,int key)
{
	struct node *aux,*aux1;
	struct node *temp=malloc(sizeof(struct node));
	temp->key=key;
	temp->right=NULL;
	temp->left=NULL;
	temp->parent=NULL;
	aux=T->root;
	aux1=NULL;
	while(aux!=NULL)
	{
		aux1=aux;
		if(temp->key<aux->key)
		{
			aux=aux->left;
		}
		else if(temp->key>aux->key) 
		{
			aux=aux->right;
		}
	}
	if(aux1==NULL)
	{
		T->root=temp;
		T->root->parent=NULL;
	}
	else if(aux1!=NULL)
	{
		if(temp->key>aux1->key)
		{
			aux1->right=temp;
		}
		else if(temp->key<aux1->key)
		{
			aux1->left=temp;
		}
		temp->parent=aux1;
	}
}


void Delete(struct Tree *T,int key)
{
	struct node *z,*y;
	z=tree_search(T->root,key);
	if(z!=NULL)
	{
		if((z==T->root)&&(z->right==NULL)&&(z->left==NULL))//if root is the only node in the tree
		{
			printf("tree is empty");
			T->root=NULL;
			free(z);
			return;
		}
		if((z->right==NULL)&&(z->left==NULL)) //delete a leaf
		{
			if(z==z->parent->left)
			{
				z->parent->left=NULL;
			}
			else if(z==z->parent->right) 
			{
				z->parent->right=NULL;
			}
		}
		else if (z->right==NULL) //delete node with left child
		{
			transplant(T,z,z->left);
		}
		else if(z->left==NULL)	//delete node with right child
		{
			transplant(T,z,z->right);
		}
		else if((z->right!=NULL)&&(z->left!=NULL))	//delete node with both childs
		{
			y=minimum(z->right);		//finds successor of z
			if(y->parent!=z)
			{
				transplant(T,y,y->right);
				y->right=z->right;
				y->right->parent=y;
			}
			transplant(T,z,y);
			y->left=z->left;
			y->left->parent=y;
			z->left=NULL;
			z->right=NULL;
			z->parent=NULL;
		}
		free(z);
	}
	else printf("\n This node isn't in the tree\n'");
}

void transplant(struct Tree *T,struct node *u,struct node *v)
{
	if(u==T->root)
	{
		T->root=v;
		T->root->parent=NULL;
		return;
	}
	else
	{
		if(u==u->parent->right)
		{
			u->parent->right=v;
		}
    	if(u==u->parent->left)
		{
			u->parent->left=v;
		} 
		if(v!=NULL) 
		{
			v->parent=u->parent;
		}
	}
}




