#include <bits/stdc++.h>

using namespace std;

int hallarMCD(int a, int b);

int main()
{
    ifstream fin("input.txt");
    ofstream cou("output.txt");
    int nCasos, a, b;
    fin >> nCasos;
    for(int i = 0; i < nCasos; i++)
    {
        fin >> a >> b;
        cou << hallarMCD(a, b) << endl;
    }
    cou.close();
    fin.close();
}


int hallarMCD(int a, int b)
{
    if(a % b == 0 || b % a == 0)
    {
        if(a > b)
            return b;
        else
            return a;
    }
    else
    {
        if(a > b)
            return hallarMCD(b, a % b);
        else
            return hallarMCD(a, b % a);
    }
}
