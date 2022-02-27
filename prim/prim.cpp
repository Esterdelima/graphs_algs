#include "prim.h"

void adcAresta(vector <pair<int, int>> adj[], int vertice1, int vertice2, int peso){
	adj[vertice1].push_back(make_pair(vertice2,peso));
	adj[vertice2].push_back(make_pair(vertice1,peso));
}

void Prim(vector<pair<int,int>> adj[], int vertice)
{
	int origem = 0;

    priority_queue<Pair,vector<Pair>,greater<Pair>> fila;
	
    vector<int> indc(vertice,INF);
	vector<int> pai(vertice,-1);
	vector<bool> in(vertice,false);

	fila.push(make_pair(0,origem));
	indc[origem] = 0;

	while(!fila.empty())
	{
		int vertice1 = fila.top().second;
		fila.pop();
		in[vertice1] = true;

		for(auto x : adj[vertice1])
		{
			int vertice2 = x.first;
			int peso = x.second;

			if(in[vertice2] == false && indc[vertice2] > peso)
			{
				indc[vertice2] = peso;
				fila.push(make_pair(indc[vertice2],vertice2));
				pai[vertice2] = vertice1;
			}
		}
	}
	for(int i=1; i<vertice; ++i)
    {
        printf("%d --- %d\n",pai[i],i);
    }
}