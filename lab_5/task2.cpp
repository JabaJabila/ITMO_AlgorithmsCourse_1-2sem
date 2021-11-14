#include <fstream>
#include <iostream>
using namespace std;

bool istree = true;

void check_tree(int tree[][3], int i, int l_barrier=-1000000001, int r_barrier=1000000001)
{
    if (tree[i][1] != 0) {
        if (tree[tree[i][1] - 1][0] >= tree[i][0])
            istree = false;
        if (tree[tree[i][1] - 1][0] >= r_barrier || tree[tree[i][1] - 1][0] <= l_barrier)
            istree = false;
        check_tree(tree, tree[i][1] - 1, l_barrier, tree[i][0]);
    }
    if (tree[i][2] != 0) {
        if (tree[tree[i][2] - 1][0] <= tree[i][0])
            istree = false;
        if (tree[tree[i][2] - 1][0] >= r_barrier || tree[tree[i][2] - 1][0] <= l_barrier)
            istree = false;
        check_tree(tree, tree[i][2] - 1, tree[i][0], r_barrier);
    }
}
 
int main()
{
    ifstream fin("check.in");
    ofstream fout("check.out");

    int n;
    fin >> n;
    int array[n][3];

    for (int i = 0; i < n; i++) {
    	fin >> array[i][0];
        fin >> array[i][1];
        fin >> array[i][2];
    }

    if (n == 0)
        fout << "YES";

    else
    {
        check_tree(array, 0);
        if (istree)
            fout << "YES";
        else
            fout << "NO";
    }

    fin.close();
    fout.close();

    return 0;
}