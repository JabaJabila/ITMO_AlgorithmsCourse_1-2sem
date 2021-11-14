#include <fstream>
#include <iostream>
using namespace std;

int binsrch(int array[], int key, int len, bool leftsrch)
{
	if (array[0] > key || array[len - 1] < key)
		return -1;

	int left = -1;
	int right = len;
	int mid;

	while(right - left > 1)
	{
		mid = (right + left) / 2;
		if (leftsrch ? array[mid] < key : array[mid] <= key)
			left = mid;
		else
			right = mid;
	}

	if (leftsrch ? array[right] == key : array[right - 1] == key)
		return leftsrch ? right + 1 : right;

	return -1;

}
 
int main()
{
    ifstream fin("binsearch.in");
    ofstream fout("binsearch.out");

    int n, m, srch, first, last;
    fin >> n;
    int array[n];

    for (int i = 0; i < n; i++)
    	fin >> array[i];

    fin >> m;

    for (int i = 0; i < m; i++)
    	{
    		fin >> srch;
    		first = binsrch(array, srch, n, true);
    		last = binsrch(array, srch, n, false);
    		fout << first << ' ' << last << '\n';
    	}

    fin.close();
    fout.close();

    return 0;
}