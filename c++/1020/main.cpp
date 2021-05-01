#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, anio, mes, dia;
    while(cin>>n)
    {
        anio=0;
        mes=0;
        dia=0;

        while(n>=365)
        {
            n=n-365;
            anio++;

        }


        while(n>=30)
        {
            n=n-30;
            mes++;
        }

        dia=n;

        cout<<anio<<" "<<"ano(s)"<<endl<<mes<<" "<<"mes(es)"<<endl<<dia<<" "<<"dia(s)"<<endl;
    }
}
