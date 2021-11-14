#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

#define INF 10000000;

double dist(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
 
double prim_min_w(vector<pair<int, int>>& points, int n) {

	double ** distances = new double* [n];
	bool * visited = new bool[n];
	double * array = new double[n];
	double min_w = 0;

	for (int i = 0; i < n; ++i) {
		distances[i] = new double[n];
		visited[i] = false;
		array[i] = INF;
	}

	array[0] = 0;
	
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			distances[i][j] = dist(points[i].first, points[i].second, points[j].first, points[j].second);

	for (int i = 0; i < n; ++i) {
		int a = -1;

		for (int j = 0; j < n; ++j)
			if ((a == -1||array[a] > array[j]) && (!visited[j]))
				a = j;

		visited[a] = true;

		for (int b = 0; b < n; ++b)
			if ((!visited[b]) && (a != b) && (distances[a][b] < array[b]))
				array[b] = distances[a][b];
	}

	for (int i = 0; i < n; ++i) {
		delete[] distances[i];
		min_w += array[i];
	}

	delete[] distances;
	delete[] visited;
	delete[] array;

	return min_w;
}
 
int main() {
    ifstream fin("spantree.in");
    ofstream fout("spantree.out");
 
    int n, x, y;
    fin >> n;

	vector<pair<int, int>> points;
	pair<int, int> tmp;

	for (int i = 0; i < n; ++i) {
		fin >> x >> y;
		tmp.first = x;
		tmp.second = y;
		points.push_back(tmp);
	}

	fout << setprecision(10) << prim_min_w(points, n);
 
    return 0;
}