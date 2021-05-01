#include <bits/stdc++.h>

using namespace std;

vector<string> quickSort(vector<string> arreglo, int ini, int fin);

int main()
{
    ifstream fin("input.txt");
    ofstream cou("output.txt");
    int nCases;
    fin >> nCases;
    string linea;
    vector<string> palabras;
    for(int i = 0; i < nCases; i++)
    {
        linea = "";
        palabras.clear();

        while(linea == "")
        {
            getline(fin, linea);
        }

        int ini = 0;
        for(int i = 0; i < linea.size(); i++)
        {
            if(linea.compare(i, 1, " ") == 0)
            {
                palabras.push_back(linea.substr(ini, i - ini));
                ini = i + 1;
            }
        }
        palabras.push_back(linea.substr(ini, linea.size()));

        palabras = quickSort(palabras, 0, palabras.size() - 1);
        for(int j = 0; j < palabras.size() ; j++)
        {
            if(j == palabras.size() - 1)
                cou << palabras[j];
            else
                cou << palabras[j] << " ";
        }
        cou << endl;
    }
    fin.close();
    cou.close();
    return 0;
}

vector<string> quickSort(vector<string> arreglo, int ini, int fin)
{
	// Si el arreglo tiene dos o más elementos y el inicio es menor al final
    if (ini < fin)
    {
		// Si el arreglo limitado en ini fin, tiene solo dos elementos
        if (fin - ini == 1)
        {
			// Si el primer elemento es mayor al segundo
            if (arreglo[ini].size() < arreglo[fin].size())
            {
				// Primer elemento en el arreglo
				string aux = arreglo[ini];

				// intercambia el primer con el segundo elemento, si procede
                arreglo[ini] = arreglo[fin];
                arreglo[fin] = aux;
            }
            return arreglo;
        }
        else
        {
			// defino dos arreglos para la division de los numeros
            vector<string> menores;
            vector<string> mayores;
			// Selecciona un elemento de pivote
            int piv = fin;

			// define el elemento posicion pivote
            string elementPiv = arreglo[piv];

			// Recorro entre los limites
            for (int i = ini; i < fin; i++)
            {
				// Si el elemento i es mayor al elemento pivote
                if (arreglo[i].size() < arreglo[piv].size())
                {
					// El elemento i es agregado a la lista de elementos menores
                    menores.push_back(arreglo[i]);
                }
                else if (arreglo[i].size() >= arreglo[piv].size())
                {	// Si el elemento i es menor al elemento pivote
				// El elemento i es agregado a la lista de elementos mayores
                    mayores.push_back(arreglo[i]);
                }
            }

			// Recorro la longitud de los menores
            for (int i = 0; i < mayores.size(); i++)
            {
				// Sobrescribo los datos del arreglo original a partir del limite inferior
                arreglo[ini + i] = mayores[i];
            }

			// Defino la nueva posicion del pivote
            piv = ini + mayores.size();
            arreglo[piv] = elementPiv;

			// Recorro el arreglo de los elementos mayores
            // Sobrescribo en la lista los elementos mayores
            int longitudMayores = ini + mayores.size();
            for (int i = 0; i < menores.size(); i++)
            {
                arreglo[longitudMayores + i + 1] = menores[i];
            }

            // Defino los nuevos limites del arreglo, con los elementos menores al pivote;
            arreglo = quickSort(arreglo, ini, piv - 1);
			// Lo mismo pero con los elementos mayores
            arreglo = quickSort(arreglo, piv + 1, fin);
            return arreglo;


			// Retorno el nuevo arreglo

        }
    }
    return arreglo;
}
