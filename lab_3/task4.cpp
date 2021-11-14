#include <fstream>
#include <iostream>
using namespace std;
 
int n = 0;
int array[1000000];
int indexes[1000000];
ofstream fout("priorityqueue.out");

void maxHeapify(int i)
{
    int l_leaf = 2 * i + 1;
    int r_leaf = 2 * i + 2;
    int min = i;

    if ((l_leaf < n) && (array[i] > array[l_leaf]))
        min = l_leaf;

    if ((r_leaf < n) && (array[min] > array[r_leaf]))
        min = r_leaf;

    if (i != min)
    {
        swap(array[i], array[min]);
        swap(indexes[i], indexes[min]);
        maxHeapify(min);
    }
}
 
void siftUp(int i)
{
    int parent = (i - 1) / 2;

    if (i != 0 && array[i] < array[parent])
    {
        swap(array[i], array[parent]);
        swap(indexes[i], indexes[parent]);
        siftUp(parent);
    }
}

void push(int item, int i)
{
    n++;
    array[n - 1] = item;
    indexes[n - 1] = i;
    siftUp(n - 1);
}

void extractMin()
{
    if (n == 0)
        fout << "*\n";

    else
    {
        fout << array[0] << "\n";
        swap(array[0], array[n - 1]);
        swap(indexes[0], indexes[n - 1]);
        n--;
        maxHeapify(0);
    }
}

void decreaseKey(int ind, int key)
{
    for (int j = 0; j <= n - 1; j++)
    {
        if (indexes[j] == ind)
        {
            array[j] = key;
            if (j != 0 && array[j] < array[(j - 1) / 2])
                siftUp(j);

            else
                maxHeapify(j);

            break;
        }
    }
}
 
 
int main()
{
    ifstream fin("priorityqueue.in");
    int i = 0;
    string command;
    while (fin >> command)
    {
        i++;
 
        if (command.length() == 0) {
            break;
        }

        if (command == "push")
        {
            int item;
            fin >> item;
            push(item, i);
        }

        else if (command == "extract-min")
            extractMin();

        else if (command == "decrease-key")
        {
            int ind, key;
            fin >> ind >> key;
            decreaseKey(ind, key);      
        }

        else
            break;
    }

    fin.close();
    fout.close();

    return 0;
}