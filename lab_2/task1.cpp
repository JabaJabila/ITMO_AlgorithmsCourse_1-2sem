#include <fstream>
using namespace std;
 
void merge(int array[], int left, int mid, int right)
{
    int pointer;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int left_half[n1], right_half[n2];
    for (int i = 0; i < n1; i++)
        left_half[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        right_half[j] = array[mid + 1 + j];
    int left_p = 0;
    int right_p = 0;
    pointer = left;
 
    while (left_p < n1 && right_p < n2) {
 
        if (left_half[left_p] <= right_half[right_p]) {
            array[pointer] = left_half[left_p];
            left_p++;
        }
 
        else {
            array[pointer] = right_half[right_p];
            right_p++;
        }
 
        pointer++;
    }
 
    while (left_p < n1) {
        array[pointer] = left_half[left_p];
        left_p++;
        pointer++;
    }
 
    while (right_p < n2) {
        array[pointer] = right_half[right_p];
        right_p++;
        pointer++;
    }
}
void mergesort(int array[], int left, int right)
{
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergesort(array, left, mid);
        mergesort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}
 
int main()
{
    int len = 0, tmp;
    fstream fin("sort.in");
    fin >> len;
    int array[len];
    for (int i = 0; i < len; i++) {
        fin >> array[i];
    }
    fin.close();
 
    mergesort(array, 0, len - 1);
 
    ofstream fout("sort.out");
    for (int i = 0; i < len; i++) {
        fout << array[i] << ' ';
    }
    fout.close();
    return 0;
}