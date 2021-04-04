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

int isEmpty(queue q){
    if((q.top) == -1 || (q.->top) == (q.rear)){
        return True;
    }
    return False;
}

int dequeue(queue*q){
    //check for empty condition
    if((q->top == q->rear) || (q->top == -1)){
        printf("\nQueue empty\n");
        return -1;
    }
    return (q->Q)[(q->top)++];
}

void enqueue(queue*q,int x){
    //check for full condition
    if(q->rear == (q->size)-1){
        printf("\nQueue is full\n");
        return;
    }
    (q->Q)[++(q->rear)] = x;
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

init2DMatrix(int** G,int n){
    for(int i =0;i<n;i++){
        for(int j = 0;j<n;j++){
            printf("\nIs there an Edge between G[%d][%d]?\n",i,j);
            scanf("%d",&G[i][j]);
        }
    }
    print2DMatrix(G,n);
}

void BFS(int** G,int s,int n){
    //create a boolean for each node if it has been explored or not
    int* visited = (int*)malloc(sizeof(int)*n);
    for(int i = 0;i<n;i++){
        visited[i] = False;
    }
    //mark the strating vertex as explored
    visited[s] = True;
    //Queue to store all nodes of a particular layer whose neighbours are yet to be explored
    queue* q;
    q->Q = (int*)malloc(sizeof(int)*n);
    q->top = -1;
    q->rear = -1;
    //add the first node to the queue
    enqueue(q,s);
    //while there are elements with unexplored neighbours
    while(!isEmpty(*q)){
        int v = dequeue(q);
        if(v != -1){
            //go through all neighbours
            for(int i = 0;i<n;i++){
                //if there exist an edge  it is unexplored
                if(G[v][i] == True && !visited[v]){
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
    BFS(adjMatrix,s,n);
}