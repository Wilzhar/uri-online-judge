#include <bits/stdc++.h>

using namespace std;


int main()
{
    fstream fin("entrada.txt");
    int nColumnas, nFilas, num;
    fin >> nFilas >> nColumnas;
    int nCeldas = nFilas * nColumnas;
    vector<int> celdas ;
    int coordenadas[2] = {0, 0};
    for(int i = 0; i < nCeldas; i++)
    {
        fin >> num;
        celdas.push_back(num);
    }
    int pos, iActual, jActual;
    bool foundLightSaber;
    for(int i = 0; i < nCeldas; i++)
    {
        if(celdas[i] == 42)
        {
            iActual = i / nColumnas;
            jActual = i % nColumnas;
            if((jActual != 0 || jActual != nColumnas - 1) && (iActual != 0 || iActual != nFilas - 1))
            {
                foundLightSaber = true;
                for(int deltaI = -1; deltaI <= 1 && foundLightSaber; deltaI++)
                {
                    for(int deltaJ = -1; deltaJ <= 1 && foundLightSaber; deltaJ++)
                    {
                        if(!(deltaI == 0 && deltaJ == 0))
                        {
                            pos = abs(((iActual + deltaI) * nColumnas) + (jActual + deltaJ));
                            if(celdas[pos] != 7)
                            {
                                foundLightSaber = false;
                            }
                        }
                    }
                }
            }

            if(foundLightSaber)
            {
                coordenadas[0] = iActual + 1;
                coordenadas[1] = jActual + 1;
            }
        }
    }

    cout << coordenadas[0] << " " << coordenadas[1] << endl;
    fin.close();


}
