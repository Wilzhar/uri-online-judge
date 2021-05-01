#include <bits/stdc++.h>

using namespace std;

int main()
{
    int j=60;

    for(int i=1; j>=0; i+=3)
    {
        cout << "I="<< i << " " << "J=" << j << endl;
        j-=5;
    }

    return 0;
}
