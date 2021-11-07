#include <bits/stdc++.h>

using namespace std;

bool isSet(string set);
bool isElementList(string set);
bool isList(string set);
bool isElement(string set);
bool isAtom(string set);

int main()
{
    ifstream fin("input.txt");
    ofstream cou("output.txt");
    int nCasos;
    string set;
    fin >> nCasos;
    for (int i = 0; i < nCasos; i++)
    {
        fin >> set;

        if (isSet(set))
        {
            cou << "Word #" << (i + 1) << ": Set" << endl;
        }
        else
        {
            cou << "Word #" << (i + 1) << ": No Set" << endl;
        }
    }
    fin.close();
    cou.close();
}

bool isSet(string set)
{
    if (!(set[0] == '{' && set[set.length() - 1] == '}'))
    {
        return false;
    }

    if (isElementList(set.substr(1, set.length() - 2)))
    {
        return true;
    }

    return false;
}

bool isElementList(string set)
{
    if (set == "")
    {
        return true;
    }

    if (isList(set))
    {
        return true;
    }

    return false;
}

bool isList(string set)
{
    if (isElement(set))
    {
        return true;
    }

    for (int i = 1; i < set.length() - 1; i++)
    {
        if (set.at(i) == ',')
        {
            if (isElementList(set.substr(0, i)))
            {
                if (set[i] == ',')
                {
                    if (isList(set.substr(i + 1)))
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool isElement(string set)
{
    if (isAtom(set) || isSet(set))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isAtom(string set)
{
    if (set == "{" || set == "}" || set == ",")
    {
        return true;
    }
    else
    {
        return false;
    }
}
