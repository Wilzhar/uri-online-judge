#include <bits/stdc++.h>

using namespace std;

int main()
{

    int hIni, hFin;
    cin >> hIni >> hFin;

    if(hFin < hIni)
    {
        hFin += 24;
    }

    if(hIni == hFin)
    {
        cout << "O JOGO DUROU " << 24 << " HORA(S)" << endl;
    }

    else
    {
        cout << "O JOGO DUROU " << hFin - hIni << " HORA(S)" << endl;
    }

    return 0;
}
