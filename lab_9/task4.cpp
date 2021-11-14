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
	vector<size_t> b_adj;
	unsigned component;
};

void dfs_visit(Vertex * v, size_t i, stack<size_t> & path) {
	v[i].color = GRAY;

	for (size_t j = 0; j < v[i].adj.size(); j++) {
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

void make_condesation(Vertex * v, size_t i, unsigned c) {
	v[i].color = GRAY;

	for (size_t j = 0; j < v[i].b_adj.size(); j++) {
		if (v[v[i].b_adj[j] - 1].color == WHITE)
			make_condesation(v, v[i].b_adj[j] - 1, c);
	}

	v[i].color = BLACK;
	v[i].component = c;
}

int main() {
	ifstream fin("cond.in");
    ofstream fout("cond.out");

    size_t n, m;
    fin >> n >> m;

    Vertex * v = new Vertex[n];
   	stack<size_t> sortres;

    for (size_t i = 0; i < n; i++) {
    	v[i].color = WHITE;
    	v[i].component = 0;
    }
    	
    size_t x, y;

    for (size_t i = 0; i < m; i++) {
        fin >> x >> y;
        v[x - 1].adj.push_back(y);
        v[y - 1].b_adj.push_back(x);
    }

  	topsort(v, n, sortres);
  	size_t temp;
  	size_t comp = 1;
  	size_t size = sortres.size();

	for (size_t i = 0; i < n; i++)
    	v[i].color = WHITE;

  	for (size_t i = 0; i < size; i++) {
  		temp = sortres.top();
  		sortres.pop();
  		if (v[temp - 1].component == 0) {
  			make_condesation(v, temp - 1, comp);
  			comp++;
  		}
  	}

  	fout << --comp << "\n";
  	for (size_t i = 0; i < n; i++)
  		fout << v[i].component << " ";

    delete [] v;

	return 0;
}