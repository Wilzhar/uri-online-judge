#include <bits/stdc++.h>

using namespace std;

void convertirDecimalABinario(int numeroBinario[32], unsigned long long int num);

ofstream cou("salida.txt");
int main()
{
    ifstream fin("entrada.txt");
    unsigned long long int a, b;
    int resBinario[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    while(fin >> a >> b)
    {
        int binarioA[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int binarioB[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        convertirDecimalABinario(binarioA, a);
        convertirDecimalABinario(binarioB, b);
        string msj1, msj2 = "";
        /**for(int i = 31; i >= 0; i--)
        {
            msj1 += static_cast<ostringstream*>(&(ostringstream() << binarioA[i]))->str() + " ";
            msj2 += static_cast<ostringstream*>(&(ostringstream() << binarioB[i]))->str() + " ";
        }
        cou << msj1 << endl;
        cou << msj2 << endl;
        **/
        int sum = 0;
        for(int i = 31; i >= 0; i--)
        {
            sum = binarioA[i] + binarioB[i];
            if(sum == 2 || sum == 0)
            {
                resBinario[i] = 0;
            }
            else
            {
                resBinario[i] = 1;
            }
        }
        /**for(int i = 31; i >= 0; i--)
        {
            cou << resBinario[i] << " ";
        }
        cou << endl;**/
        unsigned long long int res = 0;
        for(int i = 0; i < 32; i++)
        {
            if(resBinario[i] == 1)
            {
                res += pow(2, i);
            }
        }
        cou << res << endl;
    }
    fin.close();
    cou.close();
}

void convertirDecimalABinario(int numeroBinario[32], unsigned long long int num)
{
    int pos = 0;
    while(num >= 2)
    {
        int mod = num % 2;
        numeroBinario[pos] = mod;
        num = num / 2;
        pos++;
    }
    numeroBinario[pos] = num;
}
