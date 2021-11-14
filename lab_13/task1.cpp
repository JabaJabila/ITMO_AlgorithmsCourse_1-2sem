#include <fstream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ifstream fin("search1.in");
    ofstream fout("search1.out");

    string s1, s2;
    vector<unsigned> pos;
    unsigned count = 0, cur, j;
    
    fin >> s1 >> s2;
    if (s1.size() > s2.size()) {
    	fout << 0;
    	return 0;
	}

    for (unsigned i = 1; i <= s2.size() - s1.size() + 1; ++i) {
    	if (s2[i - 1] == s1[0]) {
    		cur = i;
    		for (j = 1; j < s1.size(); ++j) {
    			if (s2[cur] != s1[j])
    				break;
    			++cur;
    		}
    		if (j == s1.size()) {
    			++count;
    			pos.push_back(i);
    		}
    	}
    }


    fout << count << '\n';
    for (unsigned i = 0; i < count; ++i)
    	fout << pos[i] << ' ';
  
    return 0;
}