#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <utility>

using namespace std;

struct map
{
    vector <pair <string, string>> elements;
};

int get_hash(string key)
{
    unsigned long hash = 0;

    for (int i = 0; i < key.size(); i++)
        hash += (key[i] - 65) * 31 * (i + 1);

    return (int)(hash % 1000000);
}

bool exists(struct map * Map, string key)
{
    int hash = get_hash(key);

    for (unsigned i = 0; i < Map[hash].elements.size(); i++)

        if (Map[hash].elements[i].first == key)
            return true;

    return false;
}

string get(struct map * Map, string key)
{
    int hash = get_hash(key);

    if (!exists(Map, key))
        return "none";

    for (unsigned i = 0; i < Map[hash].elements.size(); i++)

        if (Map[hash].elements[i].first == key)
            return Map[hash].elements[i].second;
}

void put(struct map * Map, string key, string element)
{
    int hash = get_hash(key);

    if (exists(Map, key))
        for (unsigned i = 0; i < Map[hash].elements.size(); i++)
            if (Map[hash].elements[i].first == key) {
                Map[hash].elements[i].second = element;
                return;
            }

    Map[hash].elements.push_back(pair <string, string> (key, element));
}

void deleteh(struct map * Map, string key)
{
    int hash = get_hash(key);

    if (Map[hash].elements.empty())
        return;

    for (unsigned i = 0; i < Map[hash].elements.size(); i++)

        if (Map[hash].elements[i].first == key)
        {
            Map[hash].elements.erase(Map[hash].elements.begin() + i);
            return;
        }
}

int main()
{
    ifstream fin("map.in");
    ofstream fout("map.out");
    string key;
    string element;
    string command;
    bool isfirst = true;
    map * Map = new map[1000000];

    while (fin >> command)
    {
        if (command.length() == 0) {
            break;
        }

        if (command == "put")
        {
            fin >> key;
            fin >> element;

            put(Map, key, element);
        }

        else if (command == "get") 
        {
            if (isfirst)
                isfirst = false;
            else
                fout << "\n";

            fin >> key;
            fout << get(Map, key);
        }

        else if (command == "delete")
        {
            fin >> key;
            deleteh(Map, key);
        }

        else
            break;
    }

    fin.close();
    fout.close();

    return 0;
}