#include <iostream>
using namespace std;

int main() {

    int n, x, y;
    cin >> n;

    int64_t ** d = new int64_t * [n];
    int * a = new int [n];

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i)
        d[i] = new int64_t [n];
    
    for (int i = 0; i < n; ++i)
    	for (int j = 0; j < n; j++)
    		d[i][j] = 0;

    for (int i = 0; i < n; ++i) {
    	x = 0;
    	y = i;
    	for (int j = 0; j < n - i; ++j) {
    		if (x == y)
    			d[x][y] = 1;
    		else if (a[x] == a[y])
    			d[x][y] = (d[x][y - 1] + d[x + 1][y] + 1) % 1000000000;
    		else {
    			if (d[x][y - 1] + d[x + 1][y] - d[x + 1][y - 1] < 0)
    				d[x][y] = (d[x][y - 1] + d[x + 1][y] - d[x + 1][y - 1] + 1000000000) % 1000000000;
    			else
    				d[x][y] = (d[x][y - 1] + d[x + 1][y] - d[x + 1][y - 1]) % 1000000000; 
    		}
    		++x;
    		++y;
    	}
    }

    cout << d[0][n - 1] % 1000000000;

    delete [] a;
    for (int i = 0; i < n; ++i) {
        // for (int j = 0; j < n; ++j)
        //     cout << d[i][j] << ' ';
        delete [] d[i];
        // cout << '\n';
    }
    delete [] d;
  
    return 0;
}