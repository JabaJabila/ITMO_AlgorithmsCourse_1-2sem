#include <fstream>
#include <vector>
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
};

bool dfs_visit(Vertex * v, size_t i, vector<size_t> & path) {
	v[i].color = GRAY;

	for (size_t j = 0; j < v[i].adj.size(); j++) {
		if (v[v[i].adj[j] - 1].color == GRAY && path.size() == 0) {
			v[v[i].adj[j] - 1].color = RED;
			path.push_back(v[i].adj[j]);
			v[i].color = RED;
		}

		if (v[v[i].adj[j] - 1].color == WHITE)
			if (!dfs_visit(v, v[i].adj[j] - 1, path))
				v[i].color = RED;
	}

	if (v[i].color == RED) {
		if (i + 1 != path[0]) {
			path.push_back(i + 1);
			return false;
		}
		return true;
	}
	
	v[i].color = BLACK;
	return true;
}

void search_cycle(Vertex * v, size_t n, vector<size_t> & path) {
	for (size_t i = 0; i < n; i++) 
		if (v[i].color == WHITE)
			dfs_visit(v, i, path);
}

int main() {
	ifstream fin("cycle.in");
    ofstream fout("cycle.out");

    size_t n, m;
    fin >> n >> m;

    Vertex * v = new Vertex[n];
   	vector<size_t> cycle;

    for (size_t i = 0; i < n; i++)
    	v[i].color = WHITE;
    	
    size_t x, y;

    for (size_t i = 0; i < m; i++) {
        fin >> x >> y;
        v[x - 1].adj.push_back(y);
    }

  	search_cycle(v, n, cycle);

  	if (cycle.size() > 0) {
  		fout << "YES\n";
    	for (size_t i = cycle.size(); i > 0; i--)
    		fout << cycle[i - 1] << " ";
    }
    else
    	fout << "NO\n";

    delete [] v;

	return 0;
}