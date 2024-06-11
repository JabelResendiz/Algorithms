

#include <bits/stdc++.h>

using namespace std;


/*contar la cantidad de apariciones(posicion) de una cadena pattern dentro de otra cadena text */

vector<int> Prefix_Function(string pattern)
{

    vector<int> Phi(pattern.size(), 0);

    for (int i = 1; i < pattern.size(); i++)
    {
        int j = Phi[i - 1];

        while (j > 0 && pattern[j] != pattern[i])
            j = Phi[j - 1];

        if (pattern[i] == pattern[j])
            j += 1;

        Phi[i] = j;
    }

    return Phi;
}

void KMP_Matcher(string T,string P){

    int n=T.size();
    int m=P.size();

    vector<int> Phi= Prefix_Function(P);
    int q=0;
    int count=0;

    for(int i=0;i<n;i++){
        while(q>0 && P[q]!=T[i])
            q=Phi[q-1];
        
        if(P[q]==T[i])
            q+=1;
        
        if(q==m){
            cout<<"EL patron ocurre con corrimiento "<<i+1-m<<endl;
            count+=1;
            q=Phi[q-1];
        }
    }
    
    cout<<count<<endl;

}

int main(){

    string pattern,text;

    cin>> pattern >> text;
    
    vector<int> Phi= Prefix_Function(pattern);
    for(int i:Phi){
        cout<< i << " ";
    }
    cout<<endl;
    KMP_Matcher(text,pattern);
}
