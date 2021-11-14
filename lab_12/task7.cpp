#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    ifstream fin("knapsack.in");
    ofstream fout("knapsack.out");

    int W, n;
    fin >> W >> n;

    int ** w = new int * [n + 1];
    int * a = new int [n + 1];

    for (int i = 1; i <= n; ++i)
        fin >> a[i];

    for (int i = 0; i <= n; ++i)
        w[i] = new int [W + 1];
    
    for (int i = 0; i <= n; ++i)
        w[i][0] = 0;

    for (int i = 0; i <= W; ++i)
        w[0][i] = 0;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= W; ++j) {
            if (j >= a[i])
                w[i][j] = max(w[i - 1][j], w[i - 1][j - a[i]] + a[i]);
            else
                w[i][j] = w[i - 1][j];
        }

    fout << w[n][W];

    delete [] a;
    for (int i = 0; i <= n; ++i) {
        delete [] w[i];
    }
    delete [] w;
  
    return 0;
}