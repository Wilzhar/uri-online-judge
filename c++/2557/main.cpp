#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("entrada.txt");
    ofstream cou("salida.txt");
    string ecuacion;
    string r, l, j;
    while(fin >> ecuacion)
    {
        int posIni = 0;
        for(int i = 0; i < ecuacion.size(); i++)
        {
            if(ecuacion[i] == '+')
            {
                r = ecuacion.substr(0, i);
                posIni = i + 1;
            }
            else if(ecuacion[i] == '=')
            {
                l = ecuacion.substr(posIni, i - posIni);
                posIni = i + 1;
            }
        }

        j = ecuacion.substr(posIni, ecuacion.size() - posIni);

        if(r == "R")
        {
            int lN, jN;
            istringstream iss(l);
            iss >> lN;
            istringstream isss(j);
            isss >> jN;
            cou << jN - lN << endl;
        }
        else if(l == "L")
        {
            int rN, jN;
            istringstream iss(r);
            iss >> rN;
            istringstream isss(j);
            isss >> jN;
            cou << jN - rN << endl;
        }
        else
        {
            int rN, lN;
            istringstream iss(r);
            iss >> rN;
            istringstream isss(l);
            isss >> lN;
            cou << rN + lN << endl;
        }
    }
    cou.close();
    fin.close();
    return 0;
}
