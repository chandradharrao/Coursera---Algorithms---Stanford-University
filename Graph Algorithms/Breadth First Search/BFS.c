#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

typedef struct q
{
    int* Q;
    int size;
    int top;
    int rear;
}queue;

void print1DArr(int* a,int n){
    for(int i = 0;i<n;i++){
        printf("%d,",a[i]);
    }
}

int isEmpty(queue q){
    if((q.top) == -1){
        printf("\nQueue is Empty\n");
        return True;
    }
    printf("\nQueue isnt empty!\n");
    return False;
}

int dequeue(queue*q){
    printf("\nBefore Deletion :\n");
    printf("\nTop:%d Rear:%d Q[top]:%d\n",q->top,q->rear,(q->Q)[q->top]);
    //check for empty condition
    if((q->top == -1)){
        printf("\nQueue empty\n");
        return -1;
    }
    //check for one element case
    if(q->top == q->rear){
        printf("\nSingle Element in queue before deleting\n");
        int res = (q->Q)[(q->top)];
        q->top = q->rear = -1;
        printf("\nThe value to be deleted is %d\n",res);
        return res;
    }
    //if more than one element
    printf("\nThe value to be deleted is %d\n",(q->Q)[(q->top)]);
    return (q->Q)[(q->top)++];
}

void enqueue(queue* q,int x){
    printf("\nThe value to insert is %d\n",x);
    //check for full condition
    if(q->rear == ((q->size)-1)){
        printf("\nQueue is full\n");
        return;
    }
    printf("\nBefore Insertion :\n");
    printf("\nTop:%d and Rear:%d\n",q->top,q->rear);
    //first time insertion case
    if(q->rear == -1 && q->top == -1){
        printf("\nFirst Time Insertion\n");
        q->top = q->rear = 0;
    }
    else{
        (q->rear) = (q->rear) + 1;
    }
    (q->Q)[(q->rear)] = x;
    printf("\nAfter Insertion :\n");
    printf("\nTop:%d and Rear:%d and Q[rear]:%d\n",q->top,q->rear,(q->Q)[(q->rear)]);
    return;
}


void print2DMatrix(int** G,int n){
    for(int i =0;i<n;i++){
        printf("\n|");
        for(int j = 0;j<n;j++){
            if(j == n-1){
                printf("\t%d|",G[i][j]);
            }else{
                printf("\t%d",G[i][j]);
            }
        }
    }
}

int** create2DMatrix(int n){
    int** G = (int**)malloc(sizeof(int*)*n);
    for(int i = 0;i<n;i++){
        G[i] = (int*)malloc(sizeof(int*)*n);
    }
    //initialize with zeroes
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            G[i][j] = 0;
        }
    }
    return G;
}

void init2DMatrix(int** G,int n){
    for(int i =0;i<n;i++){
        for(int j = 0;j<n;j++){
            printf("\nIs there an Edge between G[%d][%d]?\n",i,j);
            scanf("%d",&G[i][j]);
        }
    }
    print2DMatrix(G,n);
}

void BFS(int** G,int s,int n){
	printf("\nBFS is called....\n");
    //create a boolean for each node if it has been explored or not
    int* visited = (int*)malloc(sizeof(int)*n);
    for(int i = 0;i<n;i++){
        visited[i] = False;
    }
    //mark the strating vertex as explored
    visited[s] = True;
    printf("\nCreating the Queue...\n");
    //Queue to store all nodes of a particular layer whose neighbours are yet to be explored
    queue* q = (queue*)malloc(sizeof(queue));
    printf("\nCreating the array.....");
    (q->Q) = (int*)malloc(sizeof(int)*n);
    printf("\nAssigning the top and rear variables\n");
    q->size = n;
    q->top = -1;
    q->rear = -1;
    printf("\nInserting first element to the queue\n");
    //add the first node to the queue
    enqueue(q,s);
    printf("\n********************\n");
    printf("\nexplored:%d\n",s);
    printf("\n*********************\n");
    //while there are elements with unexplored neighbours
    while(!isEmpty(*q)){
        int v = dequeue(q);
        printf("\nThe popped value is %d\n",v);
        if(v != -1){
        	printf("\nPop successfull...\n");
            //go through all neighbours
            for(int i = 0;i<n;i++){
                //if there exist an edge  it is unexplored
                printf("\nG[%d][%d] = %d and visited[%d] = %d\n",v,i,G[v][i],i,visited[i]);
                if(G[v][i] == 1 && visited[i] == False){
                	printf("\n********************\n");
                	printf("\nexplored:%d\n",i);
                	printf("\n*********************\n");
                    enqueue(q,i);
                    visited[i] = True;
                }
            }
        }else{
            return;
        }
    }
}

int main(){
    printf("\nEnter the number of vertices in the graph\n");
    int n;
    scanf("%d",&n);

    int** adjMatrix = create2DMatrix(n);
    init2DMatrix(adjMatrix,n);
    printf("\nEnter the Starting Node\n");
    int s;
    scanf("%d",&s);
    printf("\nThe starting node is %d\n",s);
    BFS(adjMatrix,s,n);
}