#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("entrada.txt");
    ofstream cou("salida.txt");
    int h1, m1, h2, m2;
    vector< vector<int> > puntos;
    bool finish = false;
    while(!finish)
    {
        fin >> h1 >> m1 >> h2 >> m2;

        if(!(h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0))
        {
            int minTotales1, minTotales2 = 0;
            minTotales1 = h1 * 60 + m1;
            minTotales2 = h2 * 60 + m2;
            if(minTotales2 < minTotales1)
            {
                minTotales2 += 1440;
            }

            if(minTotales2 - minTotales1 == 0)
            {
                cou << 1440 << endl;
            }
            else
            {
                cou << minTotales2 - minTotales1 << endl;
            }
        }
        else
        {
            finish = true;
        }
    }
    fin.close();
    cou.close();
    return 0;
}
