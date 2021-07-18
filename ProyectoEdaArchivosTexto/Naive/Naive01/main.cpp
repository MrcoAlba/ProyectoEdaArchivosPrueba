#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

void NaiveAlgorithm(char* pat, char* txt){
    int m = strlen(pat);
    int n = strlen(txt);
    cout<<"Tama"<<char(164)<<"o(m): "<<m<<" & Tama"<<char(164)<<"o(n): "<<n<<endl;
    int contador = 0;
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++)
            if (txt[i + j] != pat[j])
                break;
        if (j == m){
            contador++;
        }
    }
    cout<<"Se encontraron "<<contador<<" repeticiones de la palabra: "<<pat;
}

int main()
{
    ifstream texto;
    texto.open("Prueba2.txt");
    string textito;
    getline(texto,textito);
    int tamano_ARREGLO = textito.length();
    char txt[tamano_ARREGLO+1];
    strcpy(txt, textito.c_str());
    char pat[] = "EXAMPLES";;

    NaiveAlgorithm(pat, txt);

    texto.close();
    return 0;
}
