#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("lectura.txt");
    ofstream cou("escritura.txt");

    int l, c, r1, r2;

    while(fin >> l >> c >> r1 >> r2)
    {
        if(l == 0 && c == 0 && r1 == 0 && r2 == 0)
        {
            break;
        }
        else
        {
            int total = (r1 * 2) + (r2 * 2);
            double hip = sqrt(pow(l, 2) + pow(c, 2));
            double x = (hip / 2) - (r1 * 2);
            double y = (r1 * 2) + (2 * x);
            if(total <= l || total <= c)
            {
                cou << "S" << endl;
            }
            else if(total < hip && c >= y && l >= y)
            {
                cou << "S" << endl;
            }
            else
            {
                cou << "N" << endl;
            }
        }
    }

    fin.close();
    cou.close();
}
