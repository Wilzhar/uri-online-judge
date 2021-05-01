#include<bits/stdc++.h>

using namespace std;

int main()
{
    float a;
    while(cin >>a)
    {
        float b, c, d;
        cin>>b;
        cin>>c;

        a=a/5;
        b=b/3.3333;
        c=c/2;
        d=a+b+c;

        cout<<fixed<<"MEDIA = "<<setprecision(1)<<d<<endl;



    }
}
