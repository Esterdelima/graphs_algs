#include <bits/stdc++.h> 
using namespace std;

struct Path {
	int orig;
    int dest;
    int weight;
};
typedef struct Path path;

struct Graph {
    int Vert;
    int Edges;
    Path* path;
};
typedef struct Graph graph;
  
struct Graph* createGraph(int V, int E) 
{ 
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->Vert = V; 
    graph-> Edges = E;
    graph -> path = (Path*)malloc(graph -> Edges * sizeof(Path));
    return graph; 
} 

void printArr(int dist[], int n) 
{ 
    printf("output\n"); 
    for (int i = 0; i < n; ++i) 
        printf("%d \t -> %d\n", i, dist[i]); 
} 

void BellmanFord(struct Graph* graph, int src) 
{ 
    int V = graph->Vert; 
    int E = graph->Edges; 
    int dist[V]; 

    for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX; 
    dist[src] = 0; 

    for (int i = 1; i <= V - 1; i++) { 
        for (int j = 0; j < E; j++) { 
            int u = graph->path[j].orig; 
            int v = graph->path[j].dest; 
            int weight = graph->path[j].weight; 
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
                dist[v] = dist[u] + weight; 
        } 
    } 
  

    for (int i = 0; i < E; i++) { 
        int u = graph->path[i].orig; 
        int v = graph->path[i].dest; 
        int weight = graph->path[i].weight; 
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) { 
           printf("Graph contains negative weight cycle"); 
            return;
        } 
    } 
  
    printArr(dist, V);
  
    return; 
} 

int main(){
    
    int vertex, edge, i, v1, v2, weights;

    cout << "Enter the number of vertex:\n";
    cin >> vertex;
    cout << "Enter the number of edges:\n";
    cin >> edge;

    Graph* graphs = createGraph(vertex, edge);

    cout << "Enter the relations in the format V1 V2 weight:" << "\n";
    for(i = 0; i < edge; i++){
        cin >> v1 >> v2 >> weights;
        graphs->path[i].orig = v1;
        graphs->path[i].dest = v2;
        graphs->path[i].weight = v2;
    }

    BellmanFord(graphs, 0);

    return 0;
}