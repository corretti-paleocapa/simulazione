#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

struct processo
{
    string id;
    double durata;
    int p;
};

// funzione di confronto per ordinamento
bool confronta(processo a, processo b)
{
    if (a.p != b.p)
        return a.p > b.p; // priorità maggiore prima
    return a.durata < b.durata; // a parità, durata minore prima
}

int main()
{
    ifstream file("input.txt");

    if (!file.is_open())
    {
        cout << "Errore nell'apertura del file!" << endl;
        return 1;
    }

    int nproc;
    file >> nproc; 

    vector<processo> Processi(nproc);

    for (int i = 0; i < nproc; i++)
    {
        file >> Processi[i].id >> Processi[i].durata >> Processi[i].p;
    }

    file.close();
    sort(Processi.begin(), Processi.end(), confronta);

    // output
    for (int i = 0; i < nproc; i++)
    {
        cout << Processi[i].id << endl;
    }

    return 0;
}
