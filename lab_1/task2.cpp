#include <fstream>
using namespace std;

int main() {
	long long a = 0, b = 0, c = 0;
	fstream fin("aplusbb.in");
	fin >> a >> b;
	fin.close();

	ofstream fout("aplusbb.out");
	c = a + b * b;
	fout << c;
	fout.close();

	return 0;
}