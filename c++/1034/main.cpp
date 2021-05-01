#include <bits/stdc++.h>

using namespace std;

vector<int> insertarOrdenado(vector<int> lista, int num, int left, int right);

int main()
{
    ifstream fin("input.txt");
    ofstream cou("output.txt");
    int nCasos, bloque;
    fin >> nCasos;
    vector<int> bloques;
    for(int i = 0; i < nCasos; i++)
    {
        bloques.clear();
        int nBloques, longitud;
        fin >> nBloques >> longitud;
        for(int j = 0; j < nBloques; j++)
        {
            fin >> bloque;
            bloques = insertarOrdenado(bloques, bloque, 0, bloques.size() - 1);
        }


        int cont = 0;
        bool parar = false;
        for(int j = nBloques - 1; j >= 0 && !parar; j--)
        {
            bloque = bloques[j];
            if(bloque <= longitud)
            {
                cont += int(longitud / bloque);
                //
                cou << "longitud: " << longitud << " bloque: " << bloque << endl;
                //cou << "cont: " << cont << endl;
                longitud = longitud % bloque;
                //cou << "Longitud: " << longitud << endl;
                if(longitud == 0)
                {
                    parar = true;
                }
            }
        }

        cou << cont << endl;
    }
    fin.close();
    cou.close();
    return 0;
}

vector<int> insertarOrdenado(vector<int> lista, int num, int left, int right)
{
    if (lista.size() == 0)
    {
        lista.push_back(num);
        return lista;
    }
    else
    {
        int mid = left + ((right - left) / 2);
        if(left >= right)
        {
            if(lista[left] > num)
            {
                lista.insert(lista.begin() + left, num);
                return lista;
            }
            else
            {
                if(right + 1 == lista.size())
                {
                    lista.push_back(num);
                }
                else
                {
                    lista.insert(lista.begin() + right + 1, num);
                }
                return lista;
            }
        }
        else
        {
            if(lista[mid] > num)
            {
                return insertarOrdenado(lista, num, left, mid - 1);
            }
            else
            {
                return insertarOrdenado(lista, num, mid + 1, right);
            }
        }
    }
}
