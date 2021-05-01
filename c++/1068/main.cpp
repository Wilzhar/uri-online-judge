#include <iostream>
#include <string>

using namespace std;

int main()
{
    string cadena;
    while(cin >> cadena){

        int cont = 0;

        for (int i = 0; i < cadena.length(); i++)
        {
            if(cadena[i] == ')')
            {
                if(cont > 0)
                {
                    cont--;
                }
                else
                {
                    cont = -1;
                    break;
                }
            }
            else if(cadena[i] == '(')
            {
                cont++;
            }
        }

        if (cont == 0)
        {
            cout << "correct" << endl;
        }
        else
        {
            cout << "incorrect" << endl;
        }
    }

    return 0;
}
