#ifndef PRIM_H
#define PRIM_H

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

typedef pair <int, int>Pair;

void adcAresta(vector <pair<int, int>> adj[], int vertice1, int vertice2, int peso);
void Prim(vector<pair<int,int>> adj[], int vertice);



#endif
