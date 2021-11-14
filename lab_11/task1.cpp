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
    ifstream fin("pathmgep.in");
    ofstream fout("pathmgep.out");
 
    unsigned n, s, f;
    fin >> n >> s >> f;
    --s;
    --f;

	vector<vector<long long int>> Graph;
	Graph.resize(n);

	vector<long long int> dist;
	dist.resize(n, INF);
	dist[s] = 0;
	

	for (unsigned i = 0; i < n; ++i) {
		Graph[i].resize(n);
		for (unsigned j = 0; j < n; ++j) {
			fin >> Graph[i][j];
		}
	}

	dijkstra(Graph, dist, s, n);

	if (dist[f] != INF)
		fout << dist[f];
	else
		fout << -1;
 
    return 0;
}