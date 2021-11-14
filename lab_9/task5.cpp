#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

enum Color {
    WHITE,
    GRAY,
    BLACK
};

struct Vertex {
	Color color;
	vector<size_t> adj;
};

void dfs_visit(Vertex * v, size_t i, vector<size_t> & path) {
	v[i].color = GRAY;

    for (size_t j = 0; j < v[i].adj.size(); j++) 
		if (v[v[i].adj[j] - 1].color == WHITE)
			dfs_visit(v, v[i].adj[j] - 1, path);


	v[i].color = BLACK;
	path.push_back(i);
}

void topsort(Vertex * v, size_t n, vector<size_t> & path) {
	for (size_t i = 0; i < n; i++) 
		if (v[i].color == WHITE) {
			dfs_visit(v, i, path);
		}
}

bool check_hamiltonian(size_t i, size_t j, Vertex * v) {
    for (size_t k = 0; k < v[i].adj.size(); k++)
        if (v[i].adj[k] - 1 == j)
            return true;
    return false;
}

int main() {
	ifstream fin("hamiltonian.in");
    ofstream fout("hamiltonian.out");

    size_t n, m;
    fin >> n >> m;

    Vertex * v = new Vertex[n];
   	vector<size_t> sortres;

    for (size_t i = 0; i < n; i++)
    	v[i].color = WHITE;
    	
    size_t x, y;

    for (size_t i = 0; i < m; i++) {
        fin >> x >> y;
        v[x - 1].adj.push_back(y);
    }

  	topsort(v, n, sortres);

  	for (size_t i = n - 1; i > 0; i--)
        if (!check_hamiltonian(sortres[i], sortres[i - 1], v)) {
            fout << "NO\n";
            delete [] v;
            return 0;
        }

    fout << "YES\n";

    delete [] v;

	return 0;
}