#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("entrada.txt");
    ofstream cou("salida.txt");
    int x1, y1, x2, y2;
    vector< vector<int> > puntos;
    bool finish = false;
    while(!finish)
    {
        fin >> x1;
        fin >> y1;
        fin >> x2;
        fin >> y2;

        if(!(x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0))
        {
            int numMoviminetos;

            //cout <<"i: " << i << " " << "x1: " << x1 << ", y1: " << y1 << ", x2: " << x2 << ", y2: " << y2 << endl;
            if(x1 == x2 && y1 == y2)
            {
                numMoviminetos = 0;
            }
            else if((x1 == x2 && y1 != y2) || (x1 != x2 && y1 == y2) ||
                    (abs(x2 - x1) == abs(y2 - y1)) || (x1 + y1 == x2 + y2))
            {
                numMoviminetos = 1;
            }
            else
            {
                numMoviminetos = 2;
            }

            cou << numMoviminetos << endl;
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
