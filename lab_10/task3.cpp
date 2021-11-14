#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
 
unsigned find_set(unsigned * set, unsigned i) {
    if (i == set[i])
		return i;
	return set[i] = find_set(set, set[i]);
}

unsigned long long kruskal_min_w(vector<pair<unsigned, pair<unsigned, unsigned>>>& graph, unsigned n, unsigned m) {
	unsigned count = 0;
	unsigned long long min_w = 0;
	unsigned * set = new unsigned[n];
 
    for (unsigned i = 0; i < n; ++i)
        set[i] = i;

	sort(graph.begin(), graph.end());
 
    unsigned ux, vx;

    for (unsigned i = 0; i < m; ++i) {
    	if (count == n - 1) {
    		break;
    	}
        ux = find_set(set, graph[i].second.first);
        vx = find_set(set, graph[i].second.second);
        if (ux != vx) {
        	++count;
            min_w += graph[i].first;
            set[ux] = set[vx];
        }        
    }
    delete [] set;
    return min_w;
}
 
int main() {
    ifstream fin("spantree3.in");
    ofstream fout("spantree3.out");
 
    unsigned n, m;
    fin >> n >> m;
 
    vector<pair<unsigned, pair<unsigned, unsigned>>> graph;
   
    unsigned x, y, w;
    pair<unsigned, pair<unsigned, unsigned>> tmp;
 
    for (unsigned i = 0; i < m; ++i) {
        fin >> x >> y >> w;
        tmp.first = w;
        tmp.second.first = x - 1;
        tmp.second.second = y - 1;
        graph.push_back(tmp);
    }
 
    fout << kruskal_min_w(graph, n, m);
    return 0;
}