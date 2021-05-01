#include<bits/stdc++.h>

using namespace std;

int main()
{
    int x, cont;
    while(cin>>x)
    {
        cont=0;
        for(;cont<6;x++)
        {
            if(x%2!=0)
            {
                cont++;
                cout<<x<<endl;
            }
        }
    }
}
