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

void DFS(int** G,int* visited,int* result,int pos,int s,int n){
    //mark node s as visited
    printf("\t%d\t",s);
    visited[s] = True;
    //goto the depth of each node
    for(int i = 0;i<n;i++){
        if(G[s][i] == True && visited[i] == False){
            //call DFS
            DFS(G,visited,i,n);
        }
    }

    //if no outgoing edge from this node "s",then sink
    result[pos] = s;
    //decreement number of sink vertexes
    s--;
    return;
}

void TopoSort(int** G,int* visited,int n){
    //index of the sink vertexes in the graph
    int topoIndex = n-1;

    //result array to store topoSort
    int* result = (int*)malloc(Sizeof(int)*n);

    //traverse through all nodes of the graph
    for(int i = 0;i<n;i++){
        if(visited[i] == False){
            DFS(G,visited,result,topoIndex,i,n);
        }
    }

    printf("\nThe result of topological sorting is...\n");
    for(int i = 0;i<n;i++){
        if(i != (n-1)){
            printf("%d->",result[i]);
        }else{
            printf("%d\n",result[i]);
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

    int* visited = (int*)malloc(sizeof(int)*n);
    for(int i = 0;i<n;i++){
        visited[i] = False;
    }
    printf("Topo sort on :\n");
    print2DMatrix(adjMatrix,n);
    TopoSort(adjMatrix,visited,n);

    return 0;
}
