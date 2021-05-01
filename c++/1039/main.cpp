#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("lectura.txt");
    ofstream cou("escritura.txt");
    int r1, x1, y1, r2, x2, y2;
    while(fin >> r1)
    {
        fin >> x1 >> y1 >> r2 >> x2 >> y2;
        int deltaX = pow((x2 - x1), 2);
        int deltaY = pow((y2 - y1), 2);
        double dist = sqrt(deltaX + deltaY);
        if(r1 >= dist + r2)
        {
            cou << "RICO" << endl;
        }
        else
        {
            cou << "MORTO" << endl;
        }
    }
    fin.close();
    cou.close();
}
