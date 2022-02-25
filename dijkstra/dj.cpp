#include<bits/stdc++.h>
# define INF 0x3f3f3f3f
using namespace std;

typedef pair<int, int> Pair;

class Grafo{
    int vertice;
    list<pair<int, int>>*adj;
public:
    Grafo(int vertice);
    void adcAresta(int vertc1, int vertc2, int peso);
    void Dijkstra(int fonte);
};

Grafo::Grafo(int vertice){
    this->vertice = vertice;
    adj = new list<Pair> [vertice];
}
void Grafo::adcAresta(int vertc1, int vertc2, int peso){
    adj[vertc1].push_back(make_pair(vertc2, peso));
}
void Grafo::Dijkstra(int fonte){
    priority_queue<Pair,vector<Pair>,greater<Pair>> priority_queue;
    vector<int> distancia(vertice, INF);
    priority_queue.push(make_pair(0, fonte));
    distancia[fonte] = 0;
    while (!priority_queue.empty()){
        int vertc_1 = priority_queue.top().second;
        priority_queue.pop();
        list<pair<int, int>>::iterator i;
        for(i = adj[vertc_1].begin(); i!=adj[vertc_1].end(); i++){
            int vertc_2 = (*i).first;
            int peso = (*i).second;
            if (distancia[vertc_2] > distancia[vertc_1] + peso){
                distancia[vertc_2] = distancia[vertc_1] + peso;
                priority_queue.push(make_pair(distancia[vertc_2],vertc_2));

            }
        }
    }
    for (int i = 0; i < vertice; ++i){
        printf("Menor distancia do vertice %d ao vertice origem = %d\n", i,distancia[i]);
    }
}

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
}