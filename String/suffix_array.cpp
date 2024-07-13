
#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define pi pair<int,int>


vi sort_cyclic_shifts(string const &s)
{
    int n = s.size();
    const int alphabet = 256;
    vi p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i - 1];

    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    
    for(auto c:p){
        cout<<c<<" ";
    }
    cout<<endl;
    
    
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[p[i]] != s[p[i - 1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    
     for(auto f:c){
        cout<<f<<" ";
    }
    cout<<endl;
    
    /// hasta aqui ya tenemos el p y c relativos a las primeros caracteres de mi cadena


    vi pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h)
    {
        for (int i = 0; i < n; i++)
        {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++)
        {
            pi cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pi prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

int main(){
    
    string s="dabbb";
    s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    for(auto c:sorted_shifts){

        cout<<c<<" ";
    }
}