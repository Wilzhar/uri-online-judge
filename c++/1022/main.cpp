#include <bits/stdc++.h>

using namespace std;

vector<int> darNumerosPrimos(vector<int> numerosPrimos, int numMax);
int buscarNumeroMenorCercano(vector<int> numerosPrimos, int left, int right, int num);
bool isprime(int n);

int main()
{
    ifstream fin("input.txt");
    ofstream cou("output.txt");
    vector <int> numPrimos;

    int nCasos, n1, d1, n2, d2;
    char op, x;
    fin >> nCasos;
    for(int i = 0; i < nCasos; i++)
    {
        for(int j = 1; j <= 7; j++)
        {
            switch(j)
            {
                case 1:
                    fin >> n1;
                    break;
                case 3:
                    fin >> d1;
                    break;
                case 4:
                    fin >> op;
                    break;
                case 5:
                    fin >> n2;
                    break;
                case 7:
                    fin >> d2;
                    break;
                default:
                    fin >> x;
            }
        }
        int num, den;

        switch(op)
        {
            case '+':
                num = (n1*d2) + (n2*d1);
                den = d1*d2;
                break;
            case '-':
                num = (n1*d2) - (n2*d1);
                den = d1*d2;
                break;
            case '*':
                num = n1 * n2;
                den = d1 * d2;
                break;
            case '/':
                num = n1 * d2;
                den = n2 * d1;
                break;
            default:
                num = 0;
                den = 0;
        }

        int inicio;
        if(abs(num) < abs(den))
        {
            numPrimos = darNumerosPrimos(numPrimos, abs(num));
            inicio = buscarNumeroMenorCercano(numPrimos, 0, numPrimos.size() - 1, abs(num));
        }
        else
        {
            numPrimos = darNumerosPrimos(numPrimos, abs(den));
            inicio = buscarNumeroMenorCercano(numPrimos, 0, numPrimos.size() - 1, abs(den));
        }
        int numPrimo, numViejo, denViejo;
        if(num != 0 && den != 0 && inicio != -1)
        {
            numViejo = num;
            denViejo = den;
            for(int j = inicio; j >= 0; j--)
            {
                numPrimo = numPrimos[j];
                if(numPrimo <= abs(num) && numPrimo <= abs(den))
                {
                    if(num % numPrimo == 0 && den % numPrimo == 0)
                    {
                        num = num / numPrimo;
                        den = den / numPrimo;
                        j++;
                    }
                }
            }
        }
        cou << numViejo << "/" << denViejo << " = " << num << "/" << den << endl;
    }
    fin.close();
    cou.close();
    return 0;
}

vector<int> darNumerosPrimos(vector<int> numerosPrimos, int numMax)
{
    if(numerosPrimos.size() == 0)
    {
        for(int i = 0; i < numMax; i++)
        {
            if(isprime(i))
            {
                numerosPrimos.push_back(i);
            }
        }
    }
    else
    {
        int ultPrimo = numerosPrimos[numerosPrimos.size() - 1];
        for(int i = ultPrimo + 1; i < numMax; i++)
        {
            if(isprime(i))
            {
                numerosPrimos.push_back(i);
            }
        }
    }
    return numerosPrimos;
}

bool isprime(int n)
{
    if(n == 2 || n == 3)
    {
        return true;
    }
    else if(n == 0 || n == 1)
    {
        return false;
    }
    else
    {
        for(int i = 2; i <= sqrt(n); i++)
        {
            if(n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
}

int buscarNumeroMenorCercano(vector<int> numerosPrimos, int left, int right, int num)
{
    if(right >= left)
    {
        if(right - left == 1 || right - left == 0)
        {
            if(numerosPrimos[right] <= num)
                return right;
            else if(numerosPrimos[left] <= num)
                return left;
            else
                return -1;
        }
        else
        {
            int mid = left + ((right - left) / 2);
            if(num >= numerosPrimos[mid])
            {
                return buscarNumeroMenorCercano(numerosPrimos, mid, right, num);
            }
            else
            {
                return buscarNumeroMenorCercano(numerosPrimos, left, mid - 1, num);
            }
        }
    }
    return -1;
}
