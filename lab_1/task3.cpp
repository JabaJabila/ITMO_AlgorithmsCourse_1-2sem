#include <fstream>
using namespace std;
 
int main() {
    int h, w, score;
    fstream fin("turtle.in");
    fin >> h >> w;
    int field[h][w];
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            fin >> field[i][j];
    fin.close();

    for (int i = h - 2; i >= 0; i--)
        field[i][0] += field[i + 1][0];
    for (int i = 1; i < w; i++)
        field[h - 1][i] += field[h - 1][i - 1];

    for (int j = 1; j < w; j++)
        for (int i = h - 2; i >= 0; i--) {
            if (field[i][j - 1] > field[i + 1][j])
                field[i][j] += field[i][j - 1];
            else
                field[i][j] += field[i + 1][j];
        } 

    score = field[0][w - 1];
 
    ofstream fout("turtle.out");
    fout << score;
    fout.close();
    return 0;
}