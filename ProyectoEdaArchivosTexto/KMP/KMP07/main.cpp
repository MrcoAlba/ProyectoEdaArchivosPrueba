#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

void lps_func(string txt, vector<int>&Lps){
    Lps[0] = 0;
    int len = 0;
    int i=1;
    while (i<txt.length()){
        if(txt[i]==txt[len]){
            len++;
            Lps[i] = len;
            i++;
            continue;
        }
        else{
            if(len==0){
                Lps[i] = 0;
                i++;
                continue;
            }
            else{
                len = Lps[len-1];
                continue;
            }
        }
    }
}

void KMP(string pat,string txt){
    int n = txt.length();
    int m = pat.length();
    cout<<"Tama"<<char(164)<<"o(m): "<<m<<" & Tama"<<char(164)<<"o(n): "<<n<<endl;
    vector<int>Lps(m);
    int contador = 0;
    lps_func(pat,Lps);

    int i=0,j=0;
    while(i<n){
        if(pat[j]==txt[i]){i++;j++;}
        if (j == m) {
            j = Lps[j - 1];
            contador=contador+1;
        }
        else if (i < n && pat[j] != txt[i]) {
            if (j == 0)
                i++;
            else
                j = Lps[j - 1];
        }
    }
    cout<<"Se encontraron "<<contador<<" repeticiones de la palabra: "<<pat;
}

int main()
{

	ifstream texto;
    texto.open("Prueba14.txt");
    string textito;
    getline(texto,textito);
    int tamano_ARREGLO = textito.length();
    char txt[tamano_ARREGLO+1];
    strcpy(txt, textito.c_str());
    string pat = "EXAMPLES";

    KMP(pat, txt);

    texto.close();
    return 0;
}
