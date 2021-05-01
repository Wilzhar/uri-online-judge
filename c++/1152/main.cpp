#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("datos.txt");
    ofstream cou("escritura.txt");
    int m, n, x, y, z, minimo, nodo, maxCamino = 0;
    bool nuevoNodo = true;
    vector<int> res;

    while(fin >> m >> n)
    {
        if(n == 0 && m == 0)
        {
            for(int i = 0; i < res.size(); i++)
            {
                cou << res[i] << endl;
            }
            fin.close();
            cou.close();
            break;
        }
        else
        {
            int graph [n][3];
            nuevoNodo = true;
            nodo = -1;
            maxCamino = 0;
            for(int i = 0; i < n; i++)
            {
                fin >> x >> y >> z;
                graph[i][0] = x;
                graph[i][1] = y;
                graph[i][2] = z;
            }



            for(int i = 0; i < n; i++)
            {
                cout << "i: " << i <<endl;
                if(nuevoNodo)
                {
                    nodo = graph[i][0];
                    nuevoNodo = false;
                    minimo = graph[i][2];
                }
                else
                {
                    if(graph[i][0] != nodo)
                    {
                        nuevoNodo = true;
                        cout << minimo << " i: " << i << " nodo: " << nodo << endl;
                        maxCamino += minimo;
                        i--;
                    }
                    else if(graph[i][2] < minimo)
                    {
                        minimo = graph[i][2];
                    }
                }
            }
            res.push_back(maxCamino);
        }
    }
}
