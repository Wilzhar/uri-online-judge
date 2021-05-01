#include <bits/stdc++.h>

using namespace std;

void quickSort(int arreglo[], int ini, int fin);

int main()
{
    int nCanicas, nQuestions;
    int cont = 0;
    while(cin >> nCanicas >> nQuestions)
    {
        if(nCanicas == 0 && nQuestions == 0)
        {
            break;
        }
        else
        {
            cont++;
            int canicas[nCanicas];
            int questions[nQuestions];
            for(int i = 0; i < nCanicas; i++)
            {
                cin >> canicas[i];
            }

            quickSort(canicas, 0, nCanicas);
            cout << "CASE# " << cont << ":" << endl;
            for(int i = 0; i < nQuestions; i++)
            {
                cin >> questions[i];
                bool parar = false;
                int question = questions[i];
                for(int i = 0; i < nCanicas && !parar; i++)
                {
                    int canica = canicas[i];
                    if(canica == question)
                    {
                        cout << question << " found at " << i + 1 << endl;
                        parar = true;
                    }
                }

                if(!parar)
                {
                    cout << question << " not found" << endl;
                }
            }
        }
    }
}

void quickSort(int arreglo[], int ini, int fin)
{
	// Si el arreglo tiene dos o más elementos y el inicio es menor al final
    if (ini < fin)
    {
		// Si el arreglo limitado en ini fin, tiene solo dos elementos
        if (fin - ini == 1)
        {
			// Si el primer elemento es mayor al segundo
            if (arreglo[ini] > arreglo[fin])
            {
				// Primer elemento en el arreglo
				int aux = arreglo[ini];

				// intercambia el primer con el segundo elemento, si procede
                arreglo[ini] = arreglo[fin];
                arreglo[fin] = aux;
            }
        }
        else
        {
			// defino dos arreglos para la division de los numeros
            vector<int> menores;
            vector<int> mayores;
			// Selecciona un elemento de pivote
            int piv = fin;

			// define el elemento posicion pivote
            int elementPiv = arreglo[piv];

			// Recorro entre los limites
            for (int i = ini; i < fin; i++)
            {
				// Si el elemento i es mayor al elemento pivote
                if (arreglo[i] <= arreglo[piv])
                {
					// El elemento i es agregado a la lista de elementos menores
                    menores.push_back(arreglo[i]);
                }
                else if (arreglo[i] > arreglo[piv])
                {	// Si el elemento i es menor al elemento pivote
				// El elemento i es agregado a la lista de elementos mayores
                    mayores.push_back(arreglo[i]);
                }
            }

			// Recorro la longitud de los menores
            for (int i = 0; i < menores.size(); i++)
            {
				// Sobrescribo los datos del arreglo original a partir del limite inferior
                arreglo[ini + i] = menores[i];
            }

			// Defino la nueva posicion del pivote
            piv = ini + menores.size();
            arreglo[piv] = elementPiv;

			// Recorro el arreglo de los elementos mayores
            // Sobrescribo en la lista los elementos mayores
            int longitudMenores = ini + menores.size();
            for (int i = 0; i < mayores.size(); i++)
            {
                arreglo[longitudMenores + i + 1] = mayores[i];
            }

            // Defino los nuevos limites del arreglo, con los elementos menores al pivote;
            quickSort(arreglo, ini, piv - 1);
			// Lo mismo pero con los elementos mayores
            quickSort(arreglo, piv + 1, fin);

			// Retorno el nuevo arreglo

        }
    }
}

