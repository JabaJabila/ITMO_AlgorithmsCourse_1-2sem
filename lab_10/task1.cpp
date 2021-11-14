#include <fstream>
#include <vector>
using namespace std;

int main() {
	ifstream fin("input.txt");
    ofstream fout("output.txt");

    unsigned n, m, x, y;
    fin >> n >> m;

    vector<unsigned> v_rank;
    v_rank.assign(n, 0);

    for (unsigned i = 0; i < m; i++) {
        fin >> x >> y;
        ++v_rank[x - 1];
        ++v_rank[y - 1];
    }

   	for (unsigned i = 0; i < n; i++)
     	fout <<  v_rank[i] << " ";

	return 0;
}