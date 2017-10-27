#include <iostream>
#include <vector>
#include <list>
#include <queue>

//#define INF 2147483647
#define INF 100000000

using namespace std;

void printMatrix(long int** matrix, int sz)
{
	for(int i = 0; i < sz; i++)
	{
		for(int j = 0; j < sz; j++)
		{	
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}	
}

int main(int argc, char** argv)
{

	int temp = 0;
	int sz;
	int** matrix;
	int* dist; //vetor de distancias
	bool* visited; //vetor de visitados
	list<pair<int, int> >* adj; //lista de adj
	priority_queue < pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

	cin >> sz;
	
	matrix = new int*[sz];
	adj = new list<pair<int, int> >[sz];
	dist = new int[sz];
	visited = new bool[sz];

	for(int i = 0; i < sz; i++)
	{
		matrix[i] = new int[sz];
	}
	
	/*for(int i = 0; i < sz; i++)
	{	
		for(int j = 0; j < sz; j++)
		{
			matrix[i][j] = 0;
		}
	}*/

	for(int i = 0; i < sz; i++)
	{
		dist[i] = INF;
		visited[i] = false;
	}

	//printMatrix(matrix, sz);

	for(int i = 0; i < sz; i++)
	{
		for(int j = 0; j < sz; j++)
		{	
			if(i == j)
			{
				matrix[i][j] = 0;
				adj[i].push_back(make_pair(j, 0));
			}
			else if(matrix[i][j] != 0) {}
			else
			{
				cin >> temp;
				matrix[i][j] = temp;
				matrix[j][i] = temp;
				adj[i].push_back(make_pair(j, temp));
			}
		}
	}

	//cout << endl;
	//printMatrix(matrix, sz);

	dist[0] = 0; //o primeiro sempre inicia com zero pela definição do trabalho

	pq.push(make_pair(dist[0], 0));

	while(!pq.empty())
	{
		pair<int, int> p = pq.top(); // extrai o pair do topo
		int v_p = p.second; // obtém o vértice do pair
		pq.pop(); // remove da fila

		if(visited[v_p] == false)
		{
			// marca como visitado
			visited[v_p] = true;

			list<pair<int, int> >::iterator it;

			// percorre os vértices "v" adjacentes de "u"
			for(it = adj[v_p].begin(); it != adj[v_p].end(); it++)
			{
				// obtém o vértice adjacente e o custo da aresta
				int v = it->first;
				int custo_aresta = it->second;

				// relaxamento (u, v)
				if(dist[v] > (dist[v_p] + custo_aresta))
				{
					// atualiza a distância de "v" e insere na fila
					dist[v] = dist[v_p] + custo_aresta;
					pq.push(make_pair(dist[v], v));
				}
			}
		}

	}

	cout << "Custo: "<< dist[sz-1] << endl;

	return 0;

}