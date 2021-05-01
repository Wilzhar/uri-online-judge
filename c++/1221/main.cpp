#include<bits/stdc++.h>


using namespace std;


bool isPrimo(int n)
{
    int cont=0;
    bool centinela= true;
    for(int i=2; i<sqrt(n) && centinela==true; i++)
    {
        if(n%i==0)
        {
            cont++;
        }
        if(cont>0)
        {
            centinela=false;
        }

    }
    return centinela;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
    	int x;
        cin>>x;
        if(isPrimo(x)==true)
        {
            cout<<"Prime"<<endl;
        }
        else
        {
            cout<<"Not Prime"<<endl;
        }
    }
}
