#include <fstream>
#include <iostream>
using namespace std;
 
int array[30000000] = {0};
 
int findkth(int k, int left, int right)
{
 
    while (left + 1 < right)
    {
 
        int mid = (left + right) / 2;
        swap(array[mid], array[left + 1]);
 
        if (array[left] > array[right])
            swap(array[left], array[right]);
 
        if (array[left + 1] > array[right])
            swap(array[left + 1], array[right]);
 
        if (array[left] > array[left + 1])
            swap(array[left], array[left + 1]);
 
        int left_p = left + 1;
        int right_p = right;
        int pivot = array[left_p];
 
        while (left_p <= right_p)
        {
            left_p++;
            right_p--;
            while (array[left_p] < pivot)
                left_p++;
            while (array[right_p] > pivot)
                right_p--;
            if (left_p <= right_p)
                swap(array[left_p], array[right_p]);
        }
 
        array[left + 1] = array[right_p];
        array[right_p] = pivot;
 
        if (right_p >= k)
            right = right_p - 1;
 
        if (right_p <= k)
            left = left_p;
    }

    if ((left + 1 == right) && (array[left] > array[right]))
        swap(array[left], array[right]);
    return array[k];
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int len = 0, k = 0;
    int A, B, C, a1, a2;
    freopen("kth.in", "r", stdin);
    scanf("%d %d", &len, &k);
    scanf("%d %d %d %d %d", &A, &B, &C, &a1, &a2);
 
    array[0] = a1;
    array[1] = a2;
    for (int i = 2; i < len; i++)
        array[i] = array[i - 2] * A + array[i - 1] * B + C;
 
    int kth = findkth(k - 1, 0, len - 1);
 
    freopen("kth.out", "w", stdout);
    printf("%d", kth);
    return 0;
}