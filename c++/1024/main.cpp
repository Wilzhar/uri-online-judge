#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream cou("output.txt");
    int nCasos;
    string palabra;
    fin >> nCasos;
    for(int i = -1; i < nCasos; i++)
    {
        string palabra;
        getline(fin, palabra);
        if(i >= 0)
        {
            string palabraNueva = "";
            for(int j = 0; j < palabra.size(); j++)
            {
                if((palabra.at(j) >= 97 && palabra.at(j) <= 122) || (palabra.at(j) >= 65 && palabra.at(j) <= 90))
                {
                    palabraNueva = (palabra.at(j) += 3) + palabraNueva;
                }
                else
                {
                    palabraNueva = palabra[j] + palabraNueva;
                }
            }

            for(int j = palabraNueva.size() / 2; j < palabraNueva.size(); j++)
            {
                palabraNueva.at(j) -= 1;
            }
            cou << palabraNueva << endl;
        }

    }
    fin.close();
    cou.close();
    return 0;
}
