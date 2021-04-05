#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

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

void TopoLogicalSort(int** G,int* visited,int* topoRes,int n,int pos){
    //base condition
    int isFinished = True;
    for(int i = 0;i<n;i++){
        if(visited[i] == False){
            isFinished = False;
        }
    }
    if(pos < 0 || isFinished == True){
        return;
    }
    //sink vertex:node without outgoing edges => acyclic graph
    //Identify the Sink vertex(if multiple choose first one)
    for(int i = 0;i<n;i++){
        int isSink = False;
        if(visited[i] == False){
            isSink = True;
            for(int j = 0;j<n;j++){
            if(G[i][j] == 1){
                    isSink = False;
                }
            }
        }
    
        if(isSink == True){
            //printf("\nThe sink vertex is %d\n",i);
            //visited node i
            visited[i] = True;
            //printf("\nVisited[%d] = %d",i,visited[i]);
            //put it to the last position of the topo sort result list
            //printf("\nIt is going to get placed in pos : %d",pos);
            topoRes[pos] = i;
            //remove all incoming edges to the sink vertex
            for(int k = 0;k<n;k++){
                G[k][i] = 0;
            }

            //recurse for (G - {v}) nodes
            TopoLogicalSort(G,visited,topoRes,n,pos-1);
        }
    }
}

int main(){
	printf("\n1.Automated mode\n");
    printf("\n2.Manual Mode\n");
    printf("\nEnter you choice\n");
    int choice = 1;
    scanf("%d",&choice);
    int** adjMatrix = NULL;
    int n = 6;
    switch(choice){
        case 1:{
                int inpt[6][6] = {
                    {0,0,0,0,0,0},
                    {0,0,0,0,0,0},
                    {0,0,0,1,0,0},
                    {0,1,0,0,0,0},
                    {1,1,0,0,0,0},
                    {1,0,1,0,0,0}
                };
                adjMatrix = create2DMatrix(n);
                for(int i = 0;i<n;i++){
                    for(int j = 0;j<n;j++){
                        //printf("%d ",inpt[i][j]);
                        adjMatrix[i][j] = inpt[i][j];
                    }
                }
                //printf("\nFinished Contruction of 2d array...");
                break;
        }
        case 2:
                printf("\nEnter the number of vertices in the graph\n");
                scanf("%d",&n);
                adjMatrix = create2DMatrix(n);
                init2DMatrix(adjMatrix,n);
                break;
        default:
                break;
    }

    int* result = (int*)malloc(sizeof(int)*n);
    int* visited = (int*)malloc(sizeof(int)*n);
    for(int i = 0;i<n;i++){
        visited[i] = False;
    }
    printf("Topo sort on :\n");
    print2DMatrix(adjMatrix,n);
    TopoLogicalSort(adjMatrix,visited,result,n,n-1);
    printf("\nThe result of topological sorting is...\n");
    for(int i = 0;i<n;i++){
        if(i != (n-1)){
            printf("%d->",result[i]);
        }else{
            printf("%d\n",result[i]);
        }
    }

    return 0;
}