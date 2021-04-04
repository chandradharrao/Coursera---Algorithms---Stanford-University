#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0
#define INFIN 999

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
    return False;
}

int dequeue(queue*q){
    //check for empty condition
    if((q->top == -1)){
        printf("\nQueue empty\n");
        return -1;
    }
    //check for one element case
    if(q->top == q->rear){

        int res = (q->Q)[(q->top)];
        q->top = q->rear = -1;
        return res;
    }
    //if more than one element
    return (q->Q)[(q->top)++];
}

void enqueue(queue* q,int x){
    //check for full condition
    if(q->rear == ((q->size)-1)){
        printf("\nQueue is full\n");
        return;
    }
    //first time insertion case
    if(q->rear == -1 && q->top == -1){
        q->top = q->rear = 0;
    }
    else{
        (q->rear) = (q->rear) + 1;
    }
    (q->Q)[(q->rear)] = x;
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

int* shortestDistance(int** G,int s,int n){
    //create an array to store the distance of each node rom thwe starting vertex
    int* dist = (int*)malloc(sizeof(int)*n);
    for(int i = 0;i<n;i++){
        //initially all are at INFINITE dist
        dist[i] = INFIN;
    }
    //create a boolean for each node if it has been explored or not
    int* visited = (int*)malloc(sizeof(int)*n);
    for(int i = 0;i<n;i++){
        visited[i] = False;
    }
    //mark the strating vertex as explored
    visited[s] = True;
    //the distance to the starting vertex is 0 from itself
    dist[s] = 0;
    //Queue to store all nodes of a particular layer whose neighbours are yet to be explored
    queue* q = (queue*)malloc(sizeof(queue));
    (q->Q) = (int*)malloc(sizeof(int)*n);
    q->size = n;
    q->top = -1;
    q->rear = -1;
    //add the first node to the queue
    enqueue(q,s);
    printf("\n********************\n");
    printf("\nexplored:%d\n",s);
    printf("\n*********************\n");
    //while there are elements with unexplored neighbours
    while(!isEmpty(*q)){
        int v = dequeue(q);
        if(v != -1){
            //go through all neighbours
            for(int i = 0;i<n;i++){
                //if there exist an edge  it is unexplored
                if(G[v][i] == 1 && visited[i] == False){
                    enqueue(q,i);
                    //mark it as visited
                    visited[i] = True;
                    //update th distance of the node from the node that led to this node
                    dist[i] = 1 + dist[v];
                }
            }
        }
    }
    return dist;
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
    int* dist = shortestDistance(adjMatrix,s,n);
    printf("\nThe distance of each node from starting node : %d is\n",s);
    printf("_ _ _ _ _ _ _ _");
    for(int i = 0;i<n;i++){
        printf("\n| %d --> %d : %d |\n",s,i,dist[i]);
    }
    printf("_ _ _ _ _ _ _ _ ");
