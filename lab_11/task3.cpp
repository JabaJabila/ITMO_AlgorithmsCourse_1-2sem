#include <fstream>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
 
#define INF 10000000
 
void dijkstra(vector<vector<pair<unsigned, int>>> & Graph, vector<int> & dist, unsigned s, unsigned n) {
     
    vector<bool> visited;
    visited.resize(n, false);
    int min_v, next;
    set <pair<int, unsigned>> set_v;
    set_v.insert(make_pair(dist[s], s));
 
    for (unsigned j = 0; j < n; ++j) {
        min_v = set_v.begin()->second;
        set_v.erase(set_v.begin());
 
        visited[min_v] = true;
 
        for (unsigned j = 0; j < Graph[min_v].size(); ++j) {
            if (dist[min_v] + Graph[min_v][j].second < dist[Graph[min_v][j].first]) {
                set_v.erase(make_pair(dist[Graph[min_v][j].first], Graph[min_v][j].first));
                dist[Graph[min_v][j].first] = dist[min_v] + Graph[min_v][j].second;
                set_v.insert(make_pair(dist[Graph[min_v][j].first], Graph[min_v][j].first));
            }
        }
    }
}
 
 
int main() {
    ifstream fin("pathbgep.in");
    ofstream fout("pathbgep.out");
  
    unsigned n, m, x, y;
    int w;
    fin >> n >> m;
 
    vector<vector<pair<unsigned, int>>> Graph;
    Graph.resize(n);
 
    vector<int> dist;
    dist.resize(n, INF);
    dist[0] = 0;
 
    for (unsigned i = 0; i < m; ++i) {
        fin >> x >> y >> w;
        Graph[x - 1].push_back(make_pair(y - 1, w));
        Graph[y - 1].push_back(make_pair(x - 1, w));
    }
 
    dijkstra(Graph, dist, 0, n);
    for (unsigned j = 0; j < n; ++j)
        fout << dist[j] << ' ';
  
    return 0;
}