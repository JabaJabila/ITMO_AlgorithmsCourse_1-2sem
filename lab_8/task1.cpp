#include <fstream>
using namespace std;
 
unsigned ** create_array(size_t n) {
    unsigned ** a = new unsigned *[n];
    for (size_t i = 0; i < n; i++) {
        a[i] = new unsigned [n];
        for (size_t j = 0; j < n; j++)
            a[i][j] = 0;
        }
    return a;
}
 
void free_array(unsigned ** a, size_t n) {
    for (size_t i = 0; i < n; i++)
        delete [] a[i];
    delete [] a;
}
 
int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
 
    unsigned n = 0, m = 0;
    fin >> n >> m;
    unsigned ** v_matrix = create_array(n);
    unsigned x, y;
 
    for (int i = 0; i < m; i++) {
        fin >> x >> y;
        v_matrix[x - 1][y - 1]++;
    }
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            fout << v_matrix[i][j] << " ";
        fout << "\n";
    }
 
    free_array(v_matrix, n);
    
    return 0;
}