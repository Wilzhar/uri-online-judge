#include <bits/stdc++.h>

using namespace std;

int main()
{
    float pi = 3.14159;
    int radio;
    while(cin>>radio)
    {
        double volume = ((4.0/3.0)*pi*pow(radio, 3));
        cout<<fixed<<setprecision(3)<<"VOLUME = "<<volume<<endl;
    }
}
