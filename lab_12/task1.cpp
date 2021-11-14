#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, p = 0, max = 1;
    cin >> n;
    int * a = new int [n];
    int * d = new int [n];
    int * prev = new int [n];
    vector<int> ans;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        d[i] = 1;
        prev[i] = -1;

        for (int j = 0; j < i; ++j) {
            if (a[j] < a [i] && d[j] + 1 > d[i]) {
                d[i] = d[j] + 1;
                if (d[i] == d[j] + 1)
                    prev[i] = j;
            }
        }
    }

    for (int i = 1; i < n; ++i)
        if (d[i] > max) {
            max = d[i];
            p = i;
        }

    cout << max << '\n';
    while (p != -1) {
        ans.push_back(a[p]);
        p = prev[p];
    }

    for (int i = max - 1; i >= 0; --i)
        cout << ans[i] << ' ';

    delete [] a;
    delete [] d;
    delete [] prev;
  
    return 0;
}