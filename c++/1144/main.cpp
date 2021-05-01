#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    while(cin >> n)
    {
        for(int i = 1; i<n+1; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                cout << (long long)pow(i, 1) << " " << (long long)pow(i, 2)+j << " " << (long long)pow(i,3)+j << endl;
            }
        }
    }
}
