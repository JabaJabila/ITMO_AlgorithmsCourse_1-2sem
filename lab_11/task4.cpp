#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
 
#define INF 4000000000000000000

void dfs(vector<vector<pair<unsigned, long long>>> & Graph, vector<bool> & visited, unsigned s) {
    visited[s] = true;
    for (unsigned i = 0; i < Graph[s].size(); ++i)
        if (!visited[Graph[s][i].first])
            dfs(Graph, visited, Graph[s][i].first);
}

void mark_negcycle(vector<vector<pair<unsigned, long long>>> & Graph, vector<int> & parent, vector<bool> & negcycle, unsigned v, unsigned n) {

    for (unsigned i = 0; i < n; ++i)
        v = parent[v];

    dfs(Graph, negcycle, v);
}

vector<long long> ford_bellman(vector<vector<pair<unsigned, long long>>> & Graph, vector<bool> & visited, vector<bool> & negcycle, unsigned s, unsigned n, unsigned m) {
    vector<long long> dist;
    dist.resize(n, INF);
    dist[s] = 0;
    vector<int> parent;
    parent.resize(n, -1);

    for (unsigned a = 0; a < n - 1; ++a)      
        for (unsigned i = 0; i < n; ++i)
            for (unsigned j = 0; j < Graph[i].size(); ++j)
                if (dist[i] + Graph[i][j].second < dist[Graph[i][j].first]) {
                    dist[Graph[i][j].first] = dist[i] + Graph[i][j].second;
                    parent[Graph[i][j].first] = i;
                }

    for (unsigned i = 0; i < n; ++i)
        for (unsigned j = 0; j < Graph[i].size(); ++j)
            if (dist[i] + Graph[i][j].second < dist[Graph[i][j].first])
                if (visited[Graph[i][j].first] && !(negcycle[Graph[i][j].first])) { 
                    parent[Graph[i][j].first] = i;
                    mark_negcycle(Graph, parent, negcycle, Graph[i][j].first, n);
                }
    return dist;
}
 
 
int main() {
    ifstream fin("path.in");
    ofstream fout("path.out");
  
    unsigned n, m, s, x, y;
    long long w;
    vector<vector<pair<unsigned, long long>>> Graph;

    vector<bool> visited;
    vector<bool> negcycle;

    fin >> n >> m >> s;
    --s;

    Graph.resize(n);
    visited.resize(n, false);
    negcycle.resize(n, false);
 
    for (unsigned i = 0; i < m; ++i) {
        fin >> x >> y >> w;
        Graph[x - 1].push_back(make_pair(y - 1, w));
    }

    dfs(Graph, visited, s);
    vector<long long> dist = ford_bellman(Graph, visited, negcycle, s, n, m);

    for (unsigned i = 0; i < n; ++i) {
        if (!visited[i])
            fout << "*\n";
        else if (negcycle[i] || dist[i] < -INF)
            fout << "-\n";
        else
            fout << dist[i] << "\n";
    }
  
    return 0;
}