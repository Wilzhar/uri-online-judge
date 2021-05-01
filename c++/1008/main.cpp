#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a,b;
    float c, d;
    while(cin>>a)
    {
        cin>>b;
        cin>>c;

        d=b*c;

        cout<<"NUMBER = "<<a<<endl;
        cout << fixed << setprecision(2) << "SALARY = U$ "<<d<<endl;
    }
}
