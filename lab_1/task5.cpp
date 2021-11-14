#include <fstream>
using namespace std;

int main() {
	int len = 0;
	fstream fin("sortland.in");
	fin >> len;
	float tmp, min, mid, max, min_index = 0, mid_index, max_index = 0;
	float array[len];
	float array_copy[len];
	for (int i = 0; i < len; i++) {
		fin >> array[i];
		array_copy[i] = array[i];
	}
	fin.close();

	min = array[0];
	max = array[0];
	for (int i = 1; i < len - 1; i++) {
		if (array[i] > max) {
			max = array[i];
			max_index = i;
		}
		if (array[i] < min) {
			min = array[i];
			min_index = i;
		}
	}

	for (int i = 0; i < len - 1; i++)
		for (int j = 0; j < len - 1; j++)
			if (array[j] > array[j + 1]) {
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}

	mid = array[(len - 1) / 2];
	for (int i = 0; i < len; i++)
		if (array_copy[i] == mid)
			mid_index = i;

	ofstream fout("sortland.out");
	fout << min_index + 1 << ' '<< mid_index + 1 << ' ' <<max_index + 1;
	fout.close();
	return 0;
}