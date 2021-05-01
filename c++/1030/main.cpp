#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("entrada.txt");
    ofstream cou("salida.txt");
    int nCases, nPersonas, tamPaso, pos;
    for(int i = 0; i < nCases; i++)
    {
        vector<int> personas;
        fin >> nPersonas >> tamPaso;
        for(int i = 0; i < nPersonas; i++)
        {
            personas.push_back(i + 1);
        }

        pos = tamPaso - 1;
        while(personas.size() != 1)
        {
            personas.erase(personas.begin() + pos);
            pos += pos;
            pos = pos % personas.size();
            [][x4][x1][x3][x5][x2]
            [0][1][x][x][4][x][6][7][x][x][10][x][12][13][x][x][16][x]
            2 - 4 - 6 - 8
        }

        cou << "Case " << i + 1 << ": " << personas[0] << endl;
    }
    fin.close();
    cou.close();
    return 0;
}
