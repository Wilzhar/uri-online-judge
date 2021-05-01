#include <bits/stdc++.h>

using namespace std;

int main()
{
    float a, b, c;
    while(cin>>a)
    {
        cin >> b;
        cin >> c;
        cout << "TRIANGULO: " << fixed << setprecision(3) << (a*c)/2           << endl;
        cout << "CIRCULO: "   << fixed << setprecision(3) << 3.14159*pow(c, 2) << endl;
        cout << "TRAPEZIO: "  << fixed << setprecision(3) << ((a+b)/2)*c       << endl;
        cout << "QUADRADO: "  << fixed << setprecision(3) << pow(b, 2)         << endl;
        cout << "RETANGULO: " << fixed << setprecision(3) << a*b               << endl;
    }
}
