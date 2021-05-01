#include <bits/stdc++.h>

using namespace std;

int getColumn(char letra);

int main()
{
    ifstream fin("lectura.txt");
    ofstream cou("escritura.txt");
    string iniS, finS;
    int n, deltaX, deltaY;
    int movimientos[8][8]= {{0, 3, 2, 3, 2, 3, 4, 5},
                            {3, 2, 1, 2, 3, 4, 3, 4},
                            {2, 1, 4, 3, 2, 3, 4, 5},
                            {3, 2, 3, 2, 3, 4, 3, 4},
                            {2, 3, 2, 3, 4, 3, 4, 5},
                            {3, 4, 3, 4, 3, 4, 5, 4},
                            {4, 3, 4, 3, 4, 5, 4, 5},
                            {5, 4, 5, 4, 5, 4, 5, 6}};

    while(fin >> iniS >> finS)
    {
        int ini[2] = {getColumn(iniS[0]), iniS[1]};
        int fin[2] = {getColumn(finS[0]), finS[1]};

        deltaX = abs(fin[0] - ini[0]);
        deltaY = abs(fin[1] - ini[1]);
        n = movimientos[deltaX][deltaY];
        if (deltaX == 1 && deltaY == 1)
        {
            if(iniS == "h1" || finS == "h1" || iniS == "h8" || finS == "h8" || iniS == "a1" || finS == "a1" || iniS == "a8" || finS == "a8")
                n = 4;
            else
                n = 2;
        }
        cou << "To get from " << iniS << " to " << finS << " takes " << n << " knight moves." << endl;
    }
    fin.close();
    cou.close();
}

int getColumn(char letra)
{
    int num;
    switch(letra)
    {
        case 'a':
            num = 1;
            break;
        case 'b':
            num = 2;
            break;
        case 'c':
            num = 3;
            break;
        case 'd':
            num = 4;
            break;
        case 'e':
            num = 5;
            break;
        case 'f':
            num = 6;
            break;
        case 'g':
            num = 7;
            break;
        case 'h':
            num = 8;
            break;
        default:
            num = -1;
            break;
    }
    return num;
}
