#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

#define INF 100000000000

void dijkstra(vector<vector<long long int>> & Graph, vector<long long int> & dist, unsigned s, unsigned n) {
	
	vector<bool> visited;
	visited.resize(n, false);
	int min_v;

	for (unsigned i = 0; i < n; ++i) {
		min_v = -1;
		
		for (unsigned j = 0; j < n; ++j) 
			if ((!visited[j]) && ((min_v == -1) || (dist[j] < dist[min_v])))
				min_v = j;

		visited[min_v] = true;
		if (dist[min_v] == INF)
			return;

		for (unsigned j = 0; j < n; ++j) {
			if (!(Graph[min_v][j] == -1 || j == min_v))
				if (dist[min_v] + Graph[min_v][j] < dist[j])
					dist[j] = dist[min_v] + Graph[min_v][j];
		}
	}
}


int main() {
    ifstream fin("pathsg.in");
    ofstream fout("pathsg.out");
 
    unsigned n, m, x, y;
    long long int w;
    fin >> n >> m;

	vector<vector<long long int>> Graph;
	Graph.resize(n);

	vector<long long int> dist;
	dist.resize(n, INF);

	for (unsigned i = 0; i < n; ++i) {
		Graph[i].resize(n);
		for (unsigned j = 0; j < n; ++j) {
			if (i == j)
				Graph[i][j] = 0;
			else
				Graph[i][j] = -1;
		}
	}

	for (unsigned i = 0; i < m; ++i) {
		fin >> x >> y >> w;
		Graph[x - 1][y - 1] = w;
	}

	for (unsigned i = 0; i < n; ++i) {
		for (unsigned j = 0; j < n; ++j)
			dist[j] = INF;
		dist[i] = 0;
		dijkstra(Graph, dist, i, n);
		for (unsigned j = 0; j < n; ++j)
			fout << dist[j] << ' ';
		fout << '\n';
	}
 
    return 0;
}