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
    ifstream fin("prefix.in");
    ofstream fout("prefix.out");

    string s;
  	vector<int> prefix;

  	fin >> s;
  	build_prefix(prefix, s);
  	for (int i = 0; i < s.size(); ++i)
  		fout << prefix[i + 1] << ' ';

    return 0;
}