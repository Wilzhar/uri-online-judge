#include <bits/stdc++.h>

using namespace std;

int calcularMayorIngreso(int costoManteniminentoDia, vector<int> revenuePerDay, int pos, int mayor)
{
	if(pos >= revenuePerDay.size())
	{
		return mayor;
	}
	else
    {
        int cont, temp;
        for(int j = 0; j < revenuePerDay.size(); j++)
        {
            cont = 0;
            temp = 0;
            for(int i = pos; i < revenuePerDay.size() - j; i++)
            {
                temp += revenuePerDay[i];
                cont ++;
            }
            temp = temp - (costoManteniminentoDia * cont);
            if(temp > mayor)
            {
                mayor = temp;
            }
        }
		return calcularMayorIngreso(costoManteniminentoDia, revenuePerDay, pos + 1, mayor);
    }
}

int main()
{
    ifstream fin("1310.txt");
    int nDias, costoManteniminentoDia , num;
    vector<int> revenuePerDay;
	while(fin >> nDias)
    {
        revenuePerDay.clear();
		fin >> costoManteniminentoDia;
		for(int i = 0; i < nDias; i++)
        {
            fin >> num;
            revenuePerDay.push_back(num);
        }
        cout << calcularMayorIngreso(costoManteniminentoDia, revenuePerDay, 0, 0) << endl;
    }
    fin.close();
}
