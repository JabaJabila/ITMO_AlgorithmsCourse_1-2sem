#include <fstream>
#include <iostream>
using namespace std;

bool validGarland(double array[], int len)
{
    for (int i = 2; i < len; i++)
    {
        array[i] = 2.0 * array[i - 1] - array[i - 2] + 2;
        if (array[i] < 0)
            return false;
    }
    return true;
}

double garlandBinsrch(double array[], int len)
{
	double left = 0, right = array[0];

    while (right - left > 0.000001)
    {
        array[1] = (left + right) / 2.0;
        
        if (validGarland(array, len))
            right = array[1];
        else
            left = array[1];
    }
    return array[len - 1];
}
 
int main()
{
    ifstream fin("garland.in");
    ofstream fout("garland.out");

    int n;
    double A;
    fin >> n >> A;
    double bulbs[n];
    bulbs[0] = A;


    fout.precision(2);
    fout << fixed << garlandBinsrch(bulbs, n) << '\n';

    fin.close();
    fout.close();

    return 0;
}