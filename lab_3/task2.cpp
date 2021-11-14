#include <fstream>
using namespace std;

void maxHeapify(int array[], int len, int i)
{
    int largest = i;   
    int l_leaf = 2 * i + 1;
    int r_leaf = 2 * i + 2;

    if (l_leaf < len && array[l_leaf] > array[largest])
        largest = l_leaf;

    if (r_leaf < len && array[r_leaf] > array[largest])
        largest = r_leaf;

    if (largest != i)
    {
        swap(array[i], array[largest]);
        maxHeapify(array, len, largest);
    }
}

void buildMaxHeap(int array[], int len)
{
	for (int i = len / 2 - 1; i >= 0; i--)
        maxHeapify(array, len, i);
}

void heapsort(int array[], int len)
{
    buildMaxHeap(array, len);

    for (int i = len - 1; i >= 0; i--)
    {
        swap(array[0], array[i]);
        maxHeapify(array, i, 0);
    }
}

int main()
{
    int len = 0;
    fstream fin("sort.in");
    fin >> len;
    int array[len];
    for (int i = 0; i < len; i++) {
        fin >> array[i];
    }
    fin.close();

    heapsort(array, len);

    ofstream fout("sort.out");
    for (int i = 0; i < len; i++)
    	fout << array[i] << ' ';
    fout.close();
    return 0;
}