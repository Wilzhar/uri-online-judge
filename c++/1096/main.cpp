#include <bits/stdc++.h>

using namespace std;

int main()
{
    int j=7;
    int cont=1;
    int i=1;
    for(; i<11;)
    {
            cout << "I="<< i << " " << "J=" << j << endl;
        j--;
        cont++;
        if(cont == 4)
        {
            j=7;
            cont=1;
            i+=2;
        }
    }

    return 0;
}
