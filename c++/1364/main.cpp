#include <bits/stdc++.h>
using namespace std;

//ofstream cou("escritura.txt");

vector<string> insertarOrdenado(vector<string> lista, string palabra, int left, int right);
int buscarEmotes(vector<string> emoticons, string text, string emoticonActual);
//int buscarEmotesSubcadena(vector<string> emoticons, string text, int tam);

int main()
{
    //ifstream fin("datos.txt");
    //ofstream cou("escritura.txt");

    // n como Numero de Emotes
    // m como Lineas de Texto
    int numeroEmotes, lineasTexto;

    vector<string> emoticons;
    vector<string> testCases;

    string emote;
    int contEmotes;
    while(cin >> numeroEmotes >> lineasTexto)
    {
        char cadena[100];
        contEmotes = 0;
        emoticons.clear();
        testCases.clear();

        if(!(numeroEmotes == 0 && lineasTexto == 0))
        {

            for(int i = 0; i < numeroEmotes; i++)
            {
                cin >> emote;

				emoticons = insertarOrdenado(emoticons, emote, 0, emoticons.size() - 1);
            }

            for(int i = -1; i < lineasTexto; i++)
            {
                string text;
                getline(cin, text);

                if(i >= 0)
                {
                    testCases.push_back(text);
                }
            }

            //for(int i = 0; i < emoticons.size(); i++)
            //{
            	//cou << emoticons[i] << endl;
			//}

            for(int i = 0; i<testCases.size(); i++)
            {
                contEmotes += buscarEmotes(emoticons, testCases[i], "");
            }
            cout << contEmotes << endl;

        }
        else
        {
            //fin.close();
            //cou.close();
            break;
        }
    }
}

vector<string> insertarOrdenado(vector<string> lista, string palabra, int left, int right)
{
    if (lista.size() == 0)
    {
        lista.push_back(palabra);
        return lista;
    }
    else
    {
        int mid = left + ((right - left) / 2);
        if(left >= right)
        {
            if(lista[left].size() > palabra.size())
            {
                lista.insert(lista.begin() + left, palabra);
                return lista;
            }
            else
            {
                if(right+1 == lista.size())
                {
                    lista.push_back(palabra);
                }
                else
                {
                    lista.insert(lista.begin() + right + 1, palabra);
                }
                return lista;
            }
        }
        else
        {
            if(lista[mid].size() > palabra.size())
            {
                return insertarOrdenado(lista, palabra, left, mid - 1);
            }
            else
            {
                return insertarOrdenado(lista, palabra, mid + 1, right);
            }
        }
    }
}

int buscarEmotes(vector<string> emoticons, string text, string emoticonActual)
{
    //cou << text << endl;
	bool parar = false;
    int cont = 0;
    string previousText;

    for(int i = 0; i < text.size(); )
    {
        parar = false;

        for(int j = 0; j < emoticons.size() && !parar; j++)
        {
            if(emoticons[j] != emoticonActual)
            {
                if(i + emoticons[j].size() <= text.size())
                {
                    //cou << "i: " << i << " emoticons[j]: " << emoticons[j] << " text: " << text.substr(i, emoticons[j].size()) << endl;
                    if(text.compare(i, emoticons[j].size(), emoticons[j]) == 0)
                    {
                        //if(text.substr(i, emoticons[j].size()) == "((")
                            //cou << "tam anterior " << tam << " tam actaul " << i + (text.substr(i, emoticons[j].size()).size()) << endl;
                        int num = buscarEmotes(emoticons, emoticons[j], emoticons[j]);
                        if(num > 1)
                        {
                            cont += num;
                        }
                        else
                        {
                            //text.erase(i, emoticons[j].size());
                            //text.insert(i, "00");
                            //cou << "niiiiiiice" << endl;
                            cont++;
                        }
                        parar = true;
                        i += emoticons[j].size();
                    }

                }
                previousText = text;
            }
        }
        if(!parar)
        {
            i++;
        }
    }
    return cont;
}
