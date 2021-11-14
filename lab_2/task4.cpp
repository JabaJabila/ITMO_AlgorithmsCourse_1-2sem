#include <fstream>
using namespace std;

int main()
{
    unsigned len = 0;
    fstream fin("antiqs.in");
    fin >> len;
    fin.close();
    unsigned array[70000];

    array[0] = 1;
    array[1] = 2;
    unsigned tmp = 0;
    for (int i = 2; i < len; i++) {
        array[i] = i + 1;
        tmp = array[i];
        array[i] = array[i / 2];
        array[i / 2] = tmp;
    }

    ofstream fout("antiqs.out");
    for (int i = 0; i < len; i++) {
        fout << array[i] << ' ';
    }
    fout.close();
    return 0;
}