#include <fstream>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

enum Color {
    WHITE,
    GRAY,
    BLACK,
    RED
};

struct Vertex {
	Color color;
	vector<size_t> adj;
    bool component;
};

void dfs_visit(Vertex * v, size_t i, bool comp) {
    v[i].color = GRAY;
    v[i].component = comp;

    for (size_t j = 0; j < v[i].adj.size(); j++) {
        if (v[v[i].adj[j] - 1].color == WHITE)
            dfs_visit(v, v[i].adj[j] - 1, !comp);
        else
            if (v[v[i].adj[j] - 1].component == v[i].component)
                v[i].color = RED;
    }
    if (v[i].color != RED)
        v[i].color = BLACK;
}

bool check_bipartite(Vertex * v, size_t n) {
	for (size_t i = 0; i < n; i++)
        if (v[i].color == WHITE)
            dfs_visit(v, i, true);
    for (size_t i = 0; i < n; i++) {
        if (v[i].color != BLACK)
            return false;
    }
    return true;
}

int main() {
	ifstream fin("bipartite.in");
    ofstream fout("bipartite.out");

    size_t n, m;
    fin >> n >> m;

    Vertex * v = new Vertex[n];

    for (size_t i = 0; i < n; i++)
    	v[i].color = WHITE;
    	
    size_t x, y;

    for (size_t i = 0; i < m; i++) {
        fin >> x >> y;
        v[x - 1].adj.push_back(y);
        v[y - 1].adj.push_back(x);
    }

  	if (check_bipartite(v, n))
        fout << "YES\n";
    else
        fout << "NO\n";

    delete [] v;

	return 0;
}