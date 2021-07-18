#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;
#define NO_OF_CHARS 256
void badCharHeuristic( string str, int size,int badchar[NO_OF_CHARS])
{
    int i;
    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;
    for (i = 0; i < size; i++)
        badchar[(int) str[i]] = i;
}
void BoyerMoore( string pat, string txt)
{
    int m = pat.size();
    int n = txt.size();
    int badchar[NO_OF_CHARS];
    cout<<"Tama"<<char(164)<<"o(m): "<<m<<" & Tama"<<char(164)<<"o(n): "<<n<<endl;
    int contador = 0;
    badCharHeuristic(pat, m, badchar);
    int s = 0;
    while(s <= (n - m))
    {
        int j = m - 1;
        while(j >= 0 && pat[j] == txt[s + j])
            j--;
        if (j < 0)
        {
            contador++;
            s += (s + m < n)? m-badchar[txt[s + m]] : 1;
        }
        else
            s += max(1, j - badchar[txt[s + j]]);
    }

    cout<<"Se encontraron "<<contador<<" repeticiones de la palabra: "<<pat;
}

int main()
{
    ifstream texto;
    texto.open("Prueba8.txt");
    string textito;
    getline(texto,textito);
    int tamano_ARREGLO = textito.length();
    char txt[tamano_ARREGLO+1];
    strcpy(txt, textito.c_str());
    char pat[] = "EXAMPLES";

    BoyerMoore(pat, txt);

    texto.close();
    return 0;
}
