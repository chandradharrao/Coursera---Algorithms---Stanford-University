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

void DFS(int** G,int* visited,int s,int n){
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
    int* visited = (int*)malloc(sizeof(int)*n);
    for(int i = 0;i<n;i++){
    	visited[i] = False;
    }
    printf("\nThe visited nodes are : \n");
    DFS(adjMatrix,visited,s,n);
}