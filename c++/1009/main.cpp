#include <bits/stdc++.h>

using namespace std;

int main()
{
    string name;
    float salary, ventas;

    while(cin>>name)
    {
        cin>>salary;
        cin>>ventas;
        cout << fixed << setprecision(2) << "TOTAL = R$ "<<(salary+(ventas*0.15))<<endl;
    }
}
