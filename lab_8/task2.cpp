#include <fstream>
using namespace std;

unsigned ** create_array(size_t n) {
    unsigned ** a = new unsigned *[n];
    for (size_t i = 0; i < n; i++)
        a[i] = new unsigned [n];
    return a;
}

void free_array(unsigned ** a, size_t n) {
    for (size_t i = 0; i < n; i++)
        delete [] a[i];
    delete [] a;
}

bool check_undirected(unsigned ** v, size_t n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++) {
            if ((i == j) and (v[i][j] % 2 != 0))
                return false;
            if (v[i][j] != v[j][i])
                return false;
        }
    return true;
}

int main() {
	ifstream fin("input.txt");
    ofstream fout("output.txt");

    size_t n = 0;
    fin >> n;
    unsigned ** v_matrix = create_array(n);

    for (size_t i = 0; i < n; i++)
    	for (size_t j = 0; j < n; j++)
    		fin >> v_matrix[i][j];

    if (check_undirected(v_matrix, n))
        fout << "YES\n";
    else
        fout << "NO\n";

    free_array(v_matrix, n);

	return 0;
}