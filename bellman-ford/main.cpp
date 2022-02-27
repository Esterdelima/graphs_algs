#include "bellman-ford.h"

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