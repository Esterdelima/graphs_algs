#include "dijkstra.h"
// #include <bits/stdc++.h>
// # define INF 0x3f3f3f3f
// using namespace std;

typedef pair<int, int> Pair;


Grafo::Grafo(int vertice){
    this->vertice = vertice;
    adj = new list<Pair> [vertice];
}

void Grafo::adcAresta(int vertc1, int vertc2, int peso){
    adj[vertc1].push_back(make_pair(vertc2, peso));
}

void Grafo::Dijkstra(int fonte, int final){
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
    // for (int i = 0; i < vertice; ++i){
    //     printf("Menor distancia do vertice %d ao vertice origem = %d\n", i,distancia[i]);
    // }

    printf("\n");
    printf("Dijkstra algorithm:\n");
    printf("\n");
    if (final > 0){
        for (int i = 0; i < final; ++i){
            printf("Menor distancia do vertice %d ao vertice origem = %d\n", i,distancia[i]);
        }
    }
    else{
        for (int i = 0; i < vertice; ++i){
            printf("Menor distancia do vertice %d ao vertice origem = %d\n", i,distancia[i]);
        }
    }
    printf("\n");
}