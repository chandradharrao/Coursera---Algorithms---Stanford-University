#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

//to count number of components
int number_of_components = 0;

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
        //printf("\nQueue is Empty\n");
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

void BFS(int** G,int* visited,int s,int n){
    //mark the strating vertex as explored
    visited[s] = number_of_components;
    //Queue to store all nodes of a particular layer whose neighbours are yet to be explored
    queue* q = (queue*)malloc(sizeof(queue));
    (q->Q) = (int*)malloc(sizeof(int)*n);
    q->size = n;
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
                if(G[v][i] == 1 && visited[i] == False){
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

    //create a boolean for each node if it has been explored or not
    int* visited = (int*)malloc(sizeof(int)*n);
    for(int i = 0;i<n;i++){
        visited[i] = False;
    }
    
    //call bfs for all nodes of the graph
    //be it connected or discconected ones
    for(int i = 0;i<n;i++){
        if(visited[i] == False){
            //if not explored call BFS to explore all nodes connected to it
            number_of_components++;
            BFS(adjMatrix,visited,i,n);
        }
    }

    printf("\nThe total Number of components in the Grapgh are %d\n",number_of_components);
}