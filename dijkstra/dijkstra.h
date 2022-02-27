#ifndef DIJKSTRA_H
#define DIJKSTRA_H

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
    void Dijkstra(int fonte, int final);
};



#endif