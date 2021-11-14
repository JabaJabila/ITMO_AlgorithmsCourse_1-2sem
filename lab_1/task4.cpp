#include <fstream>
using namespace std;
 
int main() {
    int len = 0, tmp;
    fstream fin("smallsort.in");
    fin >> len;
    int array[len];
    for (int i = 0; i < len; i++) {
        fin >> array[i];
    }
    fin.close();
 
    for (int i = 0; i < len - 1; i++)
        for (int j = 0; j < len - 1; j++)
            if (array[j] > array[j + 1]) {
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
 
    ofstream fout("smallsort.out");
    for (int i = 0; i < len; i++) {
        fout << array[i] << ' ';
    }
    fout.close();
    return 0;
}