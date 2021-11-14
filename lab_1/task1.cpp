#include <fstream>
using namespace std;

int main() {
	int a = 0, b = 0;
	fstream fin("aplusb.in");
	fin >> a >> b;
	fin.close();

	ofstream fout("aplusb.out");
	fout << a + b;
	fout.close();
	return 0;
}