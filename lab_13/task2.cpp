#include <fstream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

void build_prefix(vector<int>& p, string s) {
    p.resize(s.size() + 1);
    p[0] = -1;
    int i = 1, j = 0;
    while (i < s.size()) {
        if (s[i] == s[j]) {
            p[i + 1] = j + 1;
            ++i;
            ++j; 
        }
        else {
            if (j == 0) {
                p[i + 1] = 0;
                ++i;
            }
            else
                j = p[j];
        }
    }
}

void build_automate(vector<vector<int>>& automate, vector<int>& prefix, unsigned n, string s) {
    automate.resize(n + 1);
    char c;

    for (int i = 0; i <= n; ++i)
        automate[i].assign(52, 0);

    for (int i = 0; i < n; ++i) {
        c = s[i];
        if (c >= 97)
            c = c - 97 + 26;
        else
            c -= 65;
        automate[i][c] = i + 1;
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < 52; ++j)
            if (automate[i][j] == 0)
                automate[i][j] = automate[prefix[i]][j];
}

int main() {

    ifstream fin("search2.in");
    ofstream fout("search2.out");
 
    string s1, s2;
    vector<unsigned> pos;
    unsigned count = 0, condition = 0;

    int n, m;
    char c;
    vector<int> prefix;

    fin >> s1 >> s2;
    n = s2.size();
    m = s1.size();

    if (m > n) {
        fout << 0;
        return 0;
    }

    build_prefix(prefix, s1);
    vector<vector<int>> automate;
    build_automate(automate, prefix, m, s1);

    for (int i = 0; i < n; ++i) {
        c = s2[i];
        if (c >= 97)
            c = c - 97 + 26;
        else
            c -= 65;
        condition = automate[condition][c];
        if (condition == m) {
            ++count;
            pos.push_back(i + 2 - m);
        }
    }

    fout << count << '\n';
    for (unsigned i = 0; i < count; ++i)
        fout << pos[i] << ' ';

    return 0;
}