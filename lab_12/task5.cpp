#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<vector<int>> & graph, vector<pair<int, int>> & d, int v) {
	d[v].first = 0;
	d[v].second = 1;

	for (int i = 0; i < graph[v].size(); ++i)
		dfs(graph, d, graph[v][i]);

	for (int i = 0; i < graph[v].size(); ++i) {
		d[v].second += d[graph[v][i]].first;
		d[v].first += max(d[graph[v][i]].first, d[graph[v][i]].second);
	}
}
 
int main() {
   	int n, v, root;
   	cin >> n;
   	vector<vector<int>> graph;
   	vector<pair<int, int>> d;
   	d.resize(n);
   	graph.resize(n);

   	for (int i = 0; i < n; ++i) {
   		cin >> v;
   		if (v != 0)
   			graph[v - 1].push_back(i);
   		else
   			root = i;
   	}

   	dfs(graph, d, root);

   	cout << max(d[root].first, d[root].second);
    
    return 0;
}