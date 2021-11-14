#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1000000001

int bin_srch(int * array, int key, int len) {

    int left = -1;
    int right = len;
    int mid;

    while(right - left > 1)
    {
        mid = (right + left) / 2;
        if (mid == key)
            return mid;
        else if (array[mid] < key)
            left = mid;
        else
            right = mid;
    }

    return right;
}

int main() {
    int n, j, max_s = 0;
    cin >> n;
    int * a = new int [n];
    int * d = new int [n + 1];
    int * p = new int [n + 1];
    int * prev = new int [n];
    vector<int> ans;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i - 1];
        d[i] = INF;
    }

    d[0] = -INF;
    p[0] = -1;

    for (int i = 0; i < n; ++i) {
        j = bin_srch(d, a[i], n);
        if (d[j - 1] < a[i] && a[i] < d[j]) {
            d[j] = a[i];
            p[j] = i;
            prev[i] = p[j - 1];
            max_s = max(max_s, j); 
        }  
    }

    cout << max_s << '\n';
    j = p[max_s];
    while (j != -1) {
        ans.push_back(a[j]);
        j = prev[j];
    }

    for (int i = max_s - 1; i >= 0; --i)
        cout << ans[i] << ' ';

    delete [] a;
    delete [] d;
    delete [] p;
    delete [] prev;
  
    return 0;
}