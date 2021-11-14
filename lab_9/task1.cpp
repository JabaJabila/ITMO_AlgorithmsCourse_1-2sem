#include <fstream>
#include <vector>
#include <stack>
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

void dfs_visit(Vertex * v, size_t i, stack<size_t> & path) {
	v[i].color = GRAY;

	for (size_t j = 0; j < v[i].adj.size(); j++) {
		if (v[v[i].adj[j] - 1].color == GRAY)
			path.push(0);

		if (v[v[i].adj[j] - 1].color == WHITE)
			dfs_visit(v, v[i].adj[j] - 1, path);
	}

	v[i].color = BLACK;
	path.push(i + 1);
}

void topsort(Vertex * v, size_t n, stack<size_t> & path) {
	for (size_t i = 0; i < n; i++) 
		if (v[i].color == WHITE) {
			dfs_visit(v, i, path);
		}
}

int main() {
	ifstream fin("topsort.in");
    ofstream fout("topsort.out");

    size_t n, m;
    fin >> n >> m;

    Vertex * v = new Vertex[n];
   	stack<size_t> sortres;

    for (size_t i = 0; i < n; i++)
    	v[i].color = WHITE;
    	
    size_t x, y;

    for (size_t i = 0; i < m; i++) {
        fin >> x >> y;
        v[x - 1].adj.push_back(y);
    }

  	topsort(v, n, sortres);
  	if (sortres.size() == n)
    	for (size_t i = 0; i < n; i++){
       		fout << sortres.top() << " ";
       		sortres.pop();
    	}
    else
    	fout << -1;

    delete [] v;

	return 0;
}