#include <bits/stdc++.h>

using namespace std;

int main()
{
    int cases, n, m, x;
    cin >> cases;
    for(int i = 0; i < cases ; i++)
    {
        cin >> n;
        cin >> m;
        int x = log10(pow(n, m)) + 1;
        cout << x << endl;
    }
}
