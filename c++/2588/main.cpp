#include <bits/stdc++.h>

using namespace std;

int contarLetras(string msj, char letra)
{
    int cont = 0;
    for(int i = 0; i < msj.size(); i++)
    {
        if(msj[i] == letra)
        {
            cont++;
        }
    }
    return cont;
}
bool verificarLetra(vector<char> letras, char letra)
{
    for(int i = 0; i < letras.size(); i++)
    {
        if(letra == letras[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ifstream fin("datos.txt");
    ofstream cou("escritura.txt");
    bool centro = false;
    vector<char> letras;
    string msj;
    int cont;
    while(fin >> msj)
    {
        letras.clear();
        centro = false;
        cont = 0;
        for(int i = 0; i < msj.size(); i++)
        {
        	int numLetras = contarLetras(msj, msj[i]);
        	bool verificacion = verificarLetra(letras, msj[i]);
            if((int)(numLetras % 2) != 0 && verificacion)
            {
                letras.push_back(msj[i]);
            	if(!centro)
            	{
            		centro = true;
				}
				else
				{
                	cont++;
				}
            }
        }
        cou << cont << endl;
    }
    fin.close();
    cou.close();
}
