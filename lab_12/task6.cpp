#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<pair<vector<int>, int>> & graph, vector<pair<int, int>> & d, int v) {
	d[v].first = 0;
	d[v].second = graph[v].second;

	for (int i = 0; i < graph[v].first.size(); ++i)
		dfs(graph, d, graph[v].first[i]);

	for (int i = 0; i < graph[v].first.size(); ++i) {
		d[v].second += d[graph[v].first[i]].first;
		d[v].first += max(d[graph[v].first[i]].first, d[graph[v].first[i]].second);
	}
}
 
int main() {
   ifstream fin("selectw.in");
   ofstream fout("selectw.out");
   int n, v, root, w;
	fin >> n;
	vector<pair<vector<int>, int>> graph;
	vector<pair<int, int>> d;
	d.resize(n);
	graph.resize(n);

   for (int i = 0; i < n; ++i) {
   	fin >> v >> w;
      graph[i].second = w;
   	if (v != 0)
   		graph[v - 1].first.push_back(i);
   	else
   	   root = i;
	}

	dfs(graph, d, root);

   fout << max(d[root].first, d[root].second);
    
   return 0;
}