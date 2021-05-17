//naive union and find to detect cycle in the graph
#include <iostream>
#include <stdbool.h>
#include <bits/stdc++.h>
using namespace std;

//this is supposed to return the leader of theconnected components
//O(1) time complexity
int find(int* parent,int x){
    cout <<"To find parent of "<<x<<endl;
    if(parent[x] == -1) return x;
    return parent[x];
}

//union operation to combine two connected components and rewire the leaders
//O(n) time complexity
void Union(int* parent,int u,int v,int n){
    //make the larger of the nodes the leader
    cout << "Union of "<<u<<" and "<<v<<endl;
    int prevPar;
    int newPar;
    if(v>= u){
        parent[u] = find(parent,v);
        prevPar = u;
        newPar = v;
        cout << "Parent of "<<u<<" is "<<parent[u]<<endl;
    }else{
        parent[v] = find(parent,u);
        prevPar = v;
        newPar = u;
        cout << "Parent of "<<v<<" is "<<parent[v]<<endl;
    }

    //rewire the older leaders of the nodes to the newer found leader
    for(int i = 0;i<n;i++){
        if(parent[i] == prevPar){
            parent[i] = newPar;
        }
    }
}

class Edge{
    public:
    int src;
    int dest;
};

class Graph{
    public:
    int nV;
    int nE;
    Edge* edges;
    //declare constructor inside the class
    Graph(int nV,int nE);
    void addEdge(int src,int dest,int i);
    bool isCycle();
};

//constructor defination outside the class using 
//name of class and scope res operator
Graph::Graph(int nV,int nE){
    this->nV = nV;
    this->nE = nE;
    //array of edges
    this->edges = new Edge[nE*sizeof(Edge)];
}

void Graph::addEdge(int src,int dest,int i){
    this->edges[i].src = src;
    this->edges[i].dest = dest;
}

//check if the graph is cyclic using the UNION and FIND operation
bool Graph::isCycle(){
    int* parent = new int[this->nV*sizeof(int)];
    //init all parents with -1
    for(int i = 0;i<this->nV;i++) parent[i] = -1;

    //iterate through all the edges
    for(int i = 0;i<this->nE;i++){
        Edge e = this->edges[i];
        //if the edges have same parent,then there is a cycle
        cout<<"**********\n";
        if(find(parent,e.src) == find(parent,e.dest)) return true;
        cout<<"*********\n";
        //union of the edges if not cyclic
        Union(parent,e.src,e.dest,this->nV);
    }
    //print the parent array
    cout <<"-----------------------\n";
    for(int i = 0;i<this->nE;i++){
        cout << parent[i]<<",";
    }
    cout <<"\n";
    cout << "------------------------\n";
    //if not returned till now
    return false;
}

int main(){
    Graph* g = new Graph(3,3);

    //construct the graph's edges
    for(int i = 0;i<(g->nE);i++){
        int s,d;
        cin >> s;
        cin >> d;
        g->addEdge(s,d,i);
    }

    //check for cyclic nature
    if(g->isCycle()) cout << "Cyclic Graph\n";
    else cout << "Acyclic Graph\n";
    return 0;
}