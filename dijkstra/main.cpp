#include "dijkstra.h"
using namespace std;

int main(){
    int vtx1, vtx2, peso, vtx, arst, ctlr;
    ifstream input ("graph.in");
    input >> vtx >> arst;
    Grafo grafo(vtx);
    vector<Pair> adj[vtx];

    for (ctlr = 0; ctlr < arst; ctlr++){
        input >> vtx1 >> vtx2 >> peso;
        grafo.adcAresta(vtx1,vtx2,peso);
    }
    printf("\n");
    printf("Dijkstra algorithm:\n");
    printf("\n");
    grafo.Dijkstra(0);//run the Dijkstra algorithm
    printf("\n");
    return 0;
}