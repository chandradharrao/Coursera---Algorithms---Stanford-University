#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdbool.h>
#include <cstring>
using namespace std;

class Edge{
    public:
    int s;
    int d;
    int w;
    Edge(int s,int d,int w):s{s},d{d},w{w}{}
};

class Graph{
    public:
    //this is the graph
    int** adjM;

    //constructor
    Graph(int n):n{n}{}

    //graph creation
    void constructGraph(){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                adjM[i] = new bool[n];
                memset(adjM[i],0,n*sizeof(bool));
            }
        }
    }

    //add edge to Graph
    void addEdge(int s,int d,int w){
        adjM[s][d] = w;
    }

    //add all edges to the Graph's adjacency matrix
    void graphInit(){
        int e;
        cout << "Enter the graph edge\n";
        cin >> e;

        for(int i = 0;i<n;i++){
            int s,d,w;
            cin>>s;
            cin>>d;
            cin>>w;
            addEdge(s,d,w);
        }
    }

    //destructor
    ~Graph(){
        for(int i = 0;i<n;i++){
            delete adjM[i];
        }
        delete adjM;
    }
};

class Tree{
    public:
    //attributes
    int n;
    //this is the tree
    int** T;
    //The Graph object
    Graph G;

    //constructor
    Tree(int n){
        this->n = n;
        this->G = Graph(n);
    }   

    //Tree creation
    void constructTree(){
        //construct the graph's adjMatrix first
        G.constructGraph();

        //construct the tree
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                T[i] = new int[n];
                memset(T[i],0,n*sizeof(int));
            }
        }
    }

    //Once the edge is added to the tree,we perform dfs on the tree matrix
    //the dfs starts with node 0,par -1 and calls dfs on the unvisisted neighs
    //there would be a cycle if a node has an already visited neighboutr and that
    //neighbour is not the parent but an ancestor.
    bool util(bool* visited,int src,int par){
        //mark the starting
        visisted[src] = true;

        //go through the neighbours of src
        for(int i = 0;i<n;i++){
            if(G.adjM[src][i] > 0){
                //if not visisted explore it
                if(!visited[i]){
                    if(util(visited,i,src) == true) return true;
                }
                //if the neighbour is already visited and if its not the
                //parent node,then there is cycle
                else if(visited[i] && i!=par){
                    return true;
                }
            }
        }
        //there is no cycle for this src,par combo
        return false;
    }

    //to check for cycle after inserting edge
    void addEdge(int src,int dest,int wei){
        //add the edge to the graph and then do cycle check.
        //if cycle,then remoe the edge from the graph
        G.adjM[src][dest] = wei;
        //array to keep track of visited nodes
        bool* visited = new bool[n];
        //call the utility function to do the recursive check
        //let the parent of node 0 be -1
        if(util(visited,0,-1) == true){
            //there is a cycle,hence remove the edge
            G.adjM[src][des] = 0;
        }
        delete visited;
    }

    //function to create the Tree
    void createTree(){
        //create the adj matrix of the graph
        G.graphInit();

        //Now populate the Tree using the created Graph Matrix
        //note that we need min spanning tree
        vector <Edge> edges = new vector<Edge>;
        //sort the edges based on the eight
        sort(edges.begin(),edges.end(),[](const Edge& lhs,const Edge& rhs){
            return lhs.w<rhs.w;
        })

        //traverse through all the edges
        for(auto e : edges){
            //add the edge to the Tree
            addEdge(e.s,e.d,e.w);
        }

    }

    //calculate the value of the MST
    int MST(){
        int sum = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(T[i][j]){

                }
            }
        }
    }

    //destructor
    ~Tree(){
        for(int i = 0;i<n;i++){
            delete T[i];
        }
        delete T;
    }
};

int main(){
    cout << "Enter the number of vertices in the graph :"<<endl;
    int n;
    cin >> n;
    Tree* T = new Tree(n)
}