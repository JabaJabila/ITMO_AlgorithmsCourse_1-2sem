#include <fstream>
using namespace std;

bool isheap(int array[], int len)
{
	for (int i = 0; i < len / 2; i++) 
	{
		if (2 * i + 1 < len)
			if (array[i] > array[2 * i + 1])
				return false;
		if (2 * i + 2 < len)
			if (array[i] > array[2 * i + 2])
				return false;
	}
	return true;
}

int main()
{
    int len = 0;
    fstream fin("isheap.in");
    fin >> len;
    int array[len];
    for (int i = 0; i < len; i++) {
        fin >> array[i];
    }
    fin.close();

    ofstream fout("isheap.out");
    if (isheap(array, len))
    	fout << "YES";
    else
    	fout << "NO";
    fout.close();
    return 0;
}