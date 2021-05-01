#include <bits/stdc++.h>

using namespace std;

int main()
{
   float i=0;
   int cont=1;
   for(;i<=2.1;)
   {
       cout << "I="<< i << " " << "J=" << cont+i << endl;
       cont++;
       if(cont==4)
       {
           cont=1;
           i+=.2;
       }
   }

    return 0;
}
