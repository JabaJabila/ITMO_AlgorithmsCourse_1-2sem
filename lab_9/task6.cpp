#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

enum Color {
    WHITE,
    BLACK
};

struct Vertex {
	Color color;
	vector<size_t> adj;
    bool isWin;
};

void dfs_mark(Vertex * v, size_t i) {
	v[i].color = BLACK;

    for (size_t j = 0; j < v[i].adj.size(); j++) 
		if (v[v[i].adj[j] - 1].color == WHITE) {
			dfs_mark(v, v[i].adj[j] - 1);
            if (!v[v[i].adj[j] - 1].isWin)
                v[i].isWin = true;
        }
        else
            if (!v[v[i].adj[j] - 1].isWin)
                v[i].isWin = true;
	v[i].color = BLACK;
}

int main() {
	ifstream fin("game.in");
    ofstream fout("game.out");

    size_t n, m, k;
    fin >> n >> m >> k;

    Vertex * v = new Vertex[n];

    for (size_t i = 0; i < n; i++) {
        v[i].isWin = false;
    	v[i].color = WHITE;
    }
    	
    size_t x, y;

    for (size_t i = 0; i < m; i++) {
        fin >> x >> y;
        v[x - 1].adj.push_back(y);
    }

    dfs_mark(v, k - 1);

    v[k - 1].isWin ? fout << "First player wins\n" : fout << "Second player wins\n"; 
  	
    delete [] v;

	return 0;
}