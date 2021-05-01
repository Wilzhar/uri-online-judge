#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("datos.txt");
    ofstream cou("escritura.txt");
    int nCasos, numPos, numChar;
    string cadena;
    string newCadena;
    fin >> nCasos;
    for(int i = 0; i < nCasos; i++)
    {
        newCadena = "";
        fin >> cadena;
        fin >> numPos;

        for(int i = 0; i < cadena.size(); i++)
        {
            numChar = ((cadena[i] - 65 - numPos) % 26) + 65;
            if(!(numChar >= 65 && numChar <= 90))
            {
                if(numChar < 65)
                {
                    numChar += 26;
                }
                else
                {
                    numChar -= 26;
                }
            }
            newCadena += numChar;
        }
        cou << newCadena << endl;
    }
    fin.close();
    cou.close();
}
