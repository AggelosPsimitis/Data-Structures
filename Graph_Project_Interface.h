enum color{white,gray,black};
enum status{activated,deactivated};
typedef struct node *tp;
struct node 
   {   
     int i,j;
     int color;
     int status;
     int d; 		 
     int weight;
     tp next, prev;
     tp up, down;
     tp parent;
    };

struct array
  { 
    int V;
    int E;
    struct node **rowsHead;
    struct node **colHead;
  };
 
struct Queue
{
  int size,capacity;
  int head;
  int tail;
  struct node **elements;
};  


int right(int i);
int left(int i);
int parent(int i);
void Heapify(tp A[],int i,int E);
void Build_Heap(tp A[],int E);
void Heapsort(tp A[],int E);
struct node *find_set(struct array *sparsearray,tp v);
void Union(struct array *sparsearray,tp x,tp y);
void KruskalMST(struct array *sparsearray,tp A[]);
struct array *create_sparsearray();
void graph_destroy(struct array *sparsearray,tp A[]);
struct Queue *createQueue(int V);    
void BFS(struct array *sparsearray, tp s);
void ENQUEUE(struct Queue *Q, tp x);
struct node *DEQUEUE(struct Queue *Q);       
void insert (struct array *sparsearray,int *edge_count,tp A[]);
void insertRow(tp r, struct array *sparsearray);
void insertCol(tp c, struct array *sparsearray);
void delete1(struct array *sparsearray);
void delete2(struct array*sparsearray,tp aux);
void deleteRow(tp r, struct array *sparsearray);
void deleteCol(tp c, struct array *sparsearray);
struct node *findedge(int i,int j, struct array *sparsearray);
void display(struct array *sparsearray);
void printlist(tp row);
void printPath(struct array *sparsearray,tp s, tp v);
void printGraphCycles(struct array *sparsearray);
