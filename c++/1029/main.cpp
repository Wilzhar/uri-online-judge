#include <bits/stdc++.h>

using namespace std;

int calls = 0;

void hacerFibonacciCalls(int num)
{
    if(num > 1)
    {
        calls += 2;
        hacerFibonacciCalls(num - 1);
        hacerFibonacciCalls(num - 2);
    }
}
int hacerFibonacci(int num)
{
    if(num <= 1)
    {
        return num;
    }
    else
    {
        return hacerFibonacci(num - 1) + hacerFibonacci(num - 2);
    }
}

int main()
{
    ifstream fin("datos.txt");
    ofstream cou("escritura.txt");
    int nCasos;
    int num, result;
    vector<int> arreglo;
    fin >> nCasos;
    for(int i = 0; i < nCasos; i++)
    {
    	calls = 0;
        fin >> num;
        result = hacerFibonacci(num);
        hacerFibonacciCalls(num);
        cou << "fib(" << num << ") = " << calls << " calls = " << result << endl;
    }
    fin.close();
    cou.close();
}
