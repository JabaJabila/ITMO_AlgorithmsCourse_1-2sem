#include <fstream>
#include <iostream>
using namespace std;

int maxh = 0;

void tree_height(int tree[][3], int i, int h)
{
    if (tree[i][1] != 0)
        tree_height(tree, tree[i][1] - 1, h + 1);
    if (tree[i][2] != 0)
        tree_height(tree, tree[i][2] - 1, h + 1);

    if (h > maxh)
        maxh = h;
}
 
int main()
{
    ifstream fin("height.in");
    ofstream fout("height.out");

    int n;
    fin >> n;
    int array[n][3];

    for (int i = 0; i < n; i++) {
    	fin >> array[i][0];
        fin >> array[i][1];
        fin >> array[i][2];
    }

    if (n == 0)
        fout << '0';
    else
    {
        tree_height(array, 0, 1);
        fout << maxh;
    }

    fin.close();
    fout.close();

    return 0;
}