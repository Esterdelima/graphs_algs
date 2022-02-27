#ifndef PRIM_H
#define PRIM_H

#include <bits/stdc++.h> 
using namespace std;

typedef struct Path {
	int orig;
    int dest;
    int weight;
}path;

//typedef struct Path path;

typedef struct Graph {
    int Vert;
    int Edges;
    Path* path;
}graph;
//typedef struct Graph graph;
  
graph* createGraph(int V, int E);

void printArr(int dist[], int n);

void BellmanFord(struct Graph* graph, int src);

#endif
