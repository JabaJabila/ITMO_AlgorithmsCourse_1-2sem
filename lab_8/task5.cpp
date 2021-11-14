#include <fstream>
#include <queue>
#include <vector>
using namespace std;

enum Color {
    WHITE,
    GRAY,
    BLACK
};

struct Vertex {
	Color color;
    unsigned distance;
	vector<unsigned> adj;
};

void bfs(size_t x, Vertex * v) {
	v[x].color = GRAY;
    v[x].distance = 0;
	queue<size_t> q;
	size_t index;
	q.push(x);

	while (!q.empty()) {
		index = q.front();
		q.pop();
		v[index].color = GRAY;

		for (size_t i = 0; i < v[index].adj.size(); i++)
			if (v[v[index].adj[i] - 1].color == WHITE) {
				v[v[index].adj[i] - 1].color = GRAY;
                v[v[index].adj[i] - 1].distance = v[index].distance + 1;
				q.push(v[index].adj[i] - 1);
			}
		v[index].color = BLACK;
	}
}

int main() {
	ifstream fin("pathbge1.in");
    ofstream fout("pathbge1.out");

    size_t n, m;
    fin >> n >> m;

    Vertex * v = new Vertex[n];

    for (size_t i = 0; i < n; i++) {
    	v[i].color = WHITE;
    	v[i].distance = -1;
    }

    unsigned x, y;

    for (size_t i = 0; i < m; i++) {
        fin >> x >> y;
        if (x == y)
        	continue;
        else { 
        	v[x - 1].adj.push_back(y);
        	v[y - 1].adj.push_back(x);
	    }
    }

    bfs(0, v);

    for (size_t i = 0; i < n; i++)
       	fout << v[i].distance << " ";

    delete [] v;

	return 0;
}