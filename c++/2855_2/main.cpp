#include <bits/stdc++.h>

using namespace std;

bool binarySearch(vector<int> secuencia, int num)
{
    if(secuencia.size()==1)
    {
        if(secuencia[0]==num)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if(num>=secuencia[secuencia.size()/2])
        {
            for(int i=0; i<secuencia.size()-1; i++)
            {
                secuencia.erase(secuencia.begin());
            }
            return binarySearch(secuencia, num);
        }
        else
        {
            secuencia.resize(secuencia.size()/2);
            return binarySearch(secuencia, num);
        }
    }
}

bool isLucky(vector<int> secuencia, int num, int pos)
{
    if(secuencia[pos]>num)
    {
        return binarySearch(secuencia, num);
    }
    else
    {
        int i=0;
        while(pos+i<secuencia.size())
        {
            secuencia.erase(secuencia.begin()+pos+i);
            i+=pos;
        }
        return isLucky(secuencia, num, pos+1);
    }
}

int main()
{
    int tamanio, num;
    int x;
    while(cin>>tamanio)
    {
        vector<int> secuencia;
        for(int i=0; i<tamanio; i++)
        {
            cin>>x;
            secuencia.push_back(x);
        }

        cin >> num;
        if(isLucky(secuencia, num, 1))
        {
            cout<<"Y"<<endl;
        }
        else
        {
            cout<<"N"<<endl;
        }

    }

}
