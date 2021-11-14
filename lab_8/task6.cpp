#include <fstream>
#include <queue>
#include <vector>

enum Color {
    WHITE,
    GRAY,
    BLACK
};

enum Blocktype {
    WALL,
    FREE,
    START,
    TARGET
};

struct Vertex {
	Color color;
    Blocktype type;
    bool adj[4];            // URDL
    std::vector<char> path;
};

struct Pair {
    Pair(size_t x = 0, size_t y = 0) : first(x) , second(y) {}
    size_t first;
    size_t second;
};

Vertex ** create_array(size_t n, size_t m) {
    Vertex ** a = new Vertex *[n];
    for (size_t i = 0; i < n; i++)
        a[i] = new Vertex [m];
    return a;
}

void free_array(Vertex ** a, size_t n) {
    for (size_t i = 0; i < n; i++)
        delete [] a[i];
    delete [] a;
}

void build_path (Pair & ind, size_t x, size_t y, Vertex ** v, char sym) {
    v[ind.first + x][ind.second + y].color = GRAY;
    v[ind.first + x][ind.second + y].path = v[ind.first][ind.second].path;
    v[ind.first + x][ind.second + y].path.push_back(sym);
    return;
}

void bfs(size_t x, size_t y, Vertex ** v) {
	v[x][y].color = GRAY;
	std::queue<Pair> q;
    Pair index;
	q.push(Pair(x, y));

	while (!q.empty()) {
		index = q.front();
		q.pop();
		v[index.first][index.second].color = GRAY;

        if ((v[index.first][index.second].adj[0]) && (v[index.first - 1][index.second].color == WHITE)) {
            q.push(Pair(index.first - 1, index.second));
            build_path(index, -1, 0, v, 'U');
            if (v[index.first - 1][index.second].type == TARGET)
                return;
        }
        if ((v[index.first][index.second].adj[1]) && (v[index.first][index.second + 1].color == WHITE)) {
            q.push(Pair(index.first, index.second + 1));
            build_path(index, 0, 1, v, 'R');
            if (v[index.first][index.second + 1].type == TARGET)
                return;
        }
        if ((v[index.first][index.second].adj[2]) && (v[index.first + 1][index.second].color == WHITE)) {
            q.push(Pair(index.first + 1, index.second));
            build_path(index, 1, 0, v, 'D');
            if (v[index.first + 1][index.second].type == TARGET)
                return;
        }
        if ((v[index.first][index.second].adj[3]) && (v[index.first][index.second - 1].color == WHITE)) {
            q.push(Pair(index.first, index.second - 1));
            build_path(index, 0, -1, v, 'L');
            if (v[index.first][index.second - 1].type == TARGET)
                return;
        }

		v[index.first][index.second].color = BLACK;
	}
}

int main() {
	std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    size_t n, m;
    size_t sx, sy, tx, ty;
    char c;
    fin >> n >> m;

    Vertex ** v = create_array(n, m);

    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++) {
            fin >> c;
            v[i][j].color = WHITE;
            v[i][j].adj[0] = false;
            v[i][j].adj[1] = false;
            v[i][j].adj[2] = false;
            v[i][j].adj[3] = false;

            if (c == '.')
                v[i][j].type = FREE;
            else if (c == 'S') {
                v[i][j].type = START;
                sx = i;
                sy = j;
            }
            else if (c == 'T') {
                v[i][j].type = TARGET;
                tx = i;
                ty = j;
            }
            else if (c == '#')
                v[i][j].type = WALL;
        }

    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++) {
            if (v[i][j].type != WALL) {
                if (i != 0 && v[i - 1][j].type != WALL)
                    v[i][j].adj[0] = true;
                if (i != n - 1 && v[i + 1][j].type != WALL)
                    v[i][j].adj[2] = true;
                if (j != 0 && v[i][j - 1].type != WALL)
                    v[i][j].adj[3] = true;
                if (j != m - 1 && v[i][j + 1].type != WALL)
                    v[i][j].adj[1] = true;
            }
    }

    bfs(sx, sy, v);

    if (v[tx][ty].path.size() == 0)
        fout << -1 << '\n';
    else {
        fout << v[tx][ty].path.size() << '\n';
        for (size_t i = 0; i < v[tx][ty].path.size(); i++)
            fout << v[tx][ty].path[i];
    }

    free_array(v, n);

	return 0;
}