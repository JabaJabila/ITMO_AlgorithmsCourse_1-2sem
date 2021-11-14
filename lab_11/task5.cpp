#include <fstream>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
 
#define INF 1000000000
 
struct Edge {
    unsigned x;
    unsigned y;
    int w;
};

bool find_negcycle(vector<Edge> & Graph, stack<unsigned> & negcycle, unsigned n) {
    vector<int> dist;
    dist.resize(n, INF);
    dist[0] = 0;
    unsigned m = Graph.size();
    vector<int> parent;
    parent.resize(n, -1);
    int v, u;

    for (unsigned i = 0; i < n; ++i) {
        v = -1;
        
        for (unsigned j = 0; j < m; ++j)
            if (dist[Graph[j].x] + Graph[j].w < dist[Graph[j].y]) {
                dist[Graph[j].y] = dist[Graph[j].x] + Graph[j].w;
                parent[Graph[j].y] = Graph[j].x;
                v = Graph[j].y;
            }
    }
 
    if (v == -1)
        return false;

    for (unsigned i = 0; i < n; ++i)
        v = parent[v];

    u = v;

    while (true) {
        negcycle.push(u);

        if (u == v && negcycle.size() > 1)
            break;

        u = parent[u];
    }

    return true;
}
 
 
int main() {
    ifstream fin("negcycle.in");
    ofstream fout("negcycle.out");
  
    unsigned n;
    int w;
    vector<Edge> Graph;
    Edge tmp;
    stack<unsigned> negcycle;

    fin >> n;
 
    for (unsigned i = 0; i < n; ++i)
        for (unsigned j = 0; j < n; ++j) {
            fin >> w;
            if (w != INF) {
                tmp.x = i;
                tmp.y = j;
                tmp.w = w;
                Graph.push_back(tmp);
            }
    }

    if (!find_negcycle(Graph, negcycle, n))
        fout << "NO\n";
    else {
        fout << "YES\n" << negcycle.size() << "\n";
        while(!negcycle.empty()) {
            fout << negcycle.top() + 1 << ' ';
            negcycle.pop();
        }
    }
  
    return 0;
}