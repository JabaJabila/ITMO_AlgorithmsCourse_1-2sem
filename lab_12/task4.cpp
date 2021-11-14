#include <iostream>
#include <fstream>
using namespace std;
 
int main() {
    ifstream fin("knight2.in");
    ofstream fout("knight2.out");
 
    int n, m;
    fin >> n >> m;
    n += 2;
    m += 2;
 
    int ** board = new int * [n + 1];
 
    for (int i = 0; i <= n; ++i)
        board[i] = new int [m + 1];
 
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            board[i][j] = 0;   
 
    board[2][2] = 1;
    int x = 2, y = 2, i, j;
 
    while (x != n - 1 || y != m - 1) {
        i = x;
        j = y;
 
        while (i <= n - 1 && j >= 2) {
            board[i][j] += board[i - 2][j + 1] + board[i - 2][j - 1] + board[i - 1][j - 2] + board[i + 1][j - 2];
            ++i;
            --j;
        }
        y != m - 1 ? ++y : ++x;
    }
 
    i = n - 1;
    j = m - 1; 
    board[i][j] += board[i - 2][j + 1] + board[i - 2][j - 1] + board[i - 1][j - 2] + board[i + 1][j - 2];
 
    fout << board[i][j] << '\n';
 
    // for (int i = 0; i <= n; ++i) {
    //     for (int j = 0; j <= m; ++j)
    //         cout << board[i][j] << ' ';
    //     cout << '\n';
    // }        
    
    for (int i = 0; i <= n; ++i)
        delete [] board[i];
    delete [] board;
   
    return 0;
}