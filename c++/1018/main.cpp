#include<bits/stdc++.h>

using namespace std;

string imprimirArray(int arreglo[])
{
    string msj="[";
    for(int i=0; sizeof(arreglo); i++)
    {
        msj+=arreglo[i]+", ";
    }

    return msj+"]";
}


void descomponerBilletes(int num, int billetes[], int pos, int numBilletes[])
{
    cout<<"pos: "<<pos<<imprimirArray(billetes)<<endl;
    if(pos!=sizeof(billetes))
    {
        numBilletes[pos] = num/billetes[pos];
        descomponerBilletes(num%billetes[pos], billetes, pos+1, numBilletes);
    }
}


int main()
{
    int num;
    int billetes[] = {100, 50, 20, 10, 5, 2, 1};

    while(cin >> num)
    {
        int numBilletes[] = {0,0,0,0,0,0,0};
        descomponerBilletes(num, billetes, 0, numBilletes);

        for(int i=0; i<sizeof(billetes); i++)
        {
            cout<< numBilletes[i] <<  " nota(s) de R$ " << billetes[i] << endl;
        }
    }
}
