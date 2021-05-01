#include <bits/stdc++.h>

using namespace std;

bool binarySearch(vector<int> secuencia, int num)
{

    for(int i=0; i<secuencia.size(); i++)
    {
        cout<<secuencia[i]<<" ";
    }

    cout<<endl;
    if(secuencia.size()==1)
    {
        if(secuencia[0]==num)
        {
            return true;
        }
        return false;
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
        if(binarySearch(secuencia, num))
        {
            return true;
        }
        return false;
    }
    else
    {
        int i=1;
        while(pow(pos, i)-2<secuencia.size())
        {
            secuencia.erase(secuencia.begin()+pow(pos, i)-2);
            i++;
        }
        return isLucky(secuencia, num, pos+1);
    }
}

int main()
{
    int tamanio, num;
    vector<int> secuencia;
    int x;
    while(cin>>tamanio)
    {
        for(int i=0; i<tamanio; i++)
        {
            cin>>x;
            secuencia.push_back(x);
        }

        cin >> num;
        bool centinela = true;
        int x=2;
        while(num>secuencia[x] && centinela)
        {
            int exp=1;
            while(pow(x, exp)-2<secuencia.size())
            {
                if(num==secuencia[pow(x, exp)-2])
                {
                    centinela=false;
                }
                secuencia.erase(secuencia.begin()+pow(x, exp)-2);
                exp++;
            }
            cout<< "elements:";
            for(int i=0; i<secuencia.size(); i++)
            {
                cout<<secuencia[i]<<" ";
            }
            cout<<endl;
            x++;
        }
        if(centinela)
        {
            cout<<"Y"<<endl;
        }
        else
        {
            cout<<"N"<<endl;
        }

    }

}
