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

int main() {
	int n, size;
    string s;
  	vector<int> prefix;
  	cin >> n;
  	cin >> s;
  	size = s.size();
  	build_prefix(prefix, s);
  	
  	vector<vector<int>> automate;
  	automate.resize(size + 1);

  	for (int i = 0; i <= size; ++i)
  		automate[i].assign(n, 0);

  	for (int i = 0; i < size; ++i)
  		automate[i][s[i] - 97] = i + 1;

  	for (int i = 1; i <= size; ++i)
  		for (int j = 0; j < n; ++j)
  			if (automate[i][j] == 0)
  				automate[i][j] = automate[prefix[i]][j];

  	for (int i = 0; i <= size; ++i) {
  		for (int j = 0; j < n; ++j) 
  			cout << automate[i][j] << ' ';
  		cout << '\n';
  	}

    return 0;
}