#include "prim.h"
using namespace std;

int main()
{
    int vertice1,vertice2,peso;
    int vertice,aresta;
    //int i;
        
    ifstream input("graph.in");//catch the graph
    input >> vertice >> aresta;//catch the number of vertice and aresta
    vector<Pair> adj[vertice];
    
    for(int i=0;i<aresta;i++)//fills the graph
    {
        input >> vertice1 >> vertice2 >> peso;
        adcAresta(adj,vertice1,vertice2,peso);
    }
    printf("\n");
    printf("Minimum spanning tree:\n");
    printf("\n");
    Prim(adj,vertice);//run the Prim algorithm
    printf("\n");
    return 0;
}