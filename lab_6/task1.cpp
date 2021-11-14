#include <fstream>
#include <iostream>
#include <vector>
 
using namespace std;
 
struct set
{
    vector <int> elements;
};
 
int get_hash(int key)
{
    return abs(key) % 1000003;
}
 
bool exists(struct set * Set, int key)
{
    int hash = get_hash(key);
 
    for (unsigned i = 0; i < Set[hash].elements.size(); i++)
 
        if (Set[hash].elements[i] == key)
            return true;
 
    return false;
}
 
void insert(struct set * Set, int key)
{
    int hash = get_hash(key);
 
    if (exists(Set, key))
        return;
 
    else
        Set[hash].elements.push_back(key);
}
 
void deleteh(struct set * Set, int key)
{
    int hash = get_hash(key);
 
    if (Set[hash].elements.empty())
        return;
 
    for (unsigned i = 0; i < Set[hash].elements.size(); i++)
 
        if (Set[hash].elements[i] == key)
        {
            Set[hash].elements.erase(Set[hash].elements.begin() + i);
            return;
        }
 
}
  
int main()
{
    ifstream fin("set.in");
    ofstream fout("set.out");
    int key;
    string command;
    set * Set = new set[1000003];
 
    while (fin >> command)
    {
        if (command.length() == 0) {
            break;
        }
 
        if (command == "insert")
        {
            fin >> key;
            insert(Set, key);
        }
 
        else if (command == "exists") 
        {
            fin >> key;
 
            if (exists(Set, key))
                fout << "true\n";
 
            else
                fout << "false\n";
        }
 
        else if (command == "delete")
        {
            fin >> key;
            deleteh(Set, key);
        }
 
        else
            break;
    }
 
    fin.close();
    fout.close();
 
    return 0;
}