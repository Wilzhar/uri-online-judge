#include <bits/stdc++.h>

using namespace std;

int main()
{
    int nDigitos, dBorrar;
    string numero, numeroNuevo = "";

    while(cin >> nDigitos >> dBorrar)
    {
        if(nDigitos == 0 && dBorrar == 0)
            break;
        else
        {
            bool parar = false;
            numeroNuevo = "";
            cin >> numero;
            for(int i = 0; i < nDigitos && !parar; i++)
            {
                if(dBorrar == 0)
                {
                    parar = true;
                    numeroNuevo += numero.substr(i, nDigitos - i);
                }
                else
                {
                    if(i < nDigitos - 1)
                    {
                        if(int(numero[i + 1]) < int(numero[i]))
                        {
                            numeroNuevo += numero[i];
                        }
                        else
                        {
                            dBorrar--;
                        }
                    }
                }
            }
        }

        cout << numeroNuevo << endl;
    }
}


