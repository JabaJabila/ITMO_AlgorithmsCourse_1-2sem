#include <fstream>
using namespace std;

unsigned long long merge(long long array[], unsigned long long left,
    unsigned long long mid, unsigned long long right, unsigned long long inversions)
{
    unsigned long long k;
    unsigned long long n1 = mid - left + 1;
    unsigned long long n2 = right - mid;
    unsigned long long left_half[n1], right_half[n2];
    for (unsigned long long i = 0; i < n1; i++)
        left_half[i] = array[left + i];
    for (unsigned long long j = 0; j < n2; j++)
        right_half[j] = array[mid + 1 + j];
    unsigned long long i = 0;
    unsigned long long j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (left_half[i] <= right_half[j]) {
            array[k] = left_half[i];
            i++;
        }
        else {
            array[k] = right_half[j];
            j++;
            inversions += n1 - i;
        }
        k++;
    }
    while (i < n1) {
        array[k] = left_half[i];
        i++;
        k++;
    }
    while (j < n2) {
        array[k] = right_half[j];
        j++;
        k++;
    }
    return inversions;
}
unsigned long long mergesort(long long array[], unsigned long long left,
    unsigned long long right, unsigned long long inversions)
{
    if (left < right) {
        unsigned long long tmp_inv = 0;
        unsigned long long mid = left + (right - left) / 2;
        tmp_inv = mergesort(array, left, mid, inversions);
        inversions += mergesort(array, mid + 1, right, inversions);
        inversions += merge(array, left, mid, right, 0);
        return inversions + tmp_inv;
    }
    return 0;
}

int main()
{
    unsigned long long len = 0;
    fstream fin("inversions.in");
    fin >> len;
    long long array[len];
    for (int i = 0; i < len; i++) {
        fin >> array[i];
    }
    fin.close();

    unsigned long long inversions = mergesort(array, 0, len - 1, 0);

    ofstream fout("inversions.out");
    fout << inversions << "\n";
    fout.close();
    return 0;
}