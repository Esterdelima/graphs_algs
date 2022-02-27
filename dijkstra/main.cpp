#include "dijkstra.h"
#include "../utils/utils.h"
using namespace std;

/*
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
*/

int main(int argc, char** argv){

    int vtx1, vtx2, peso, vtx, arst, ctlr;
    ifstream input ("graph.in");
    input >> vtx >> arst;
    Grafo grafo(vtx);
    vector<Pair> adj[vtx];

    for (ctlr = 0; ctlr < arst; ctlr++){
        input >> vtx1 >> vtx2 >> peso;
        grafo.adcAresta(vtx1,vtx2,peso);
    }
    Argument args;
    bool param = get_arguments(argc, argv, &args);

    if (param){
        if (args.help) help_arguments("O algoritmo de Dijkstra encontra o menor caminho entre dois vértices de um grafo.");
        else{
            if(args.initial != -1){
                if(args.final != -1){
                    grafo.Dijkstra(args.initial, args.final);
                }
                else{
                    grafo.Dijkstra(args.initial, -1);
                }
            }
        }
    }
    return 0;
}

