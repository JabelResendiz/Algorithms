
// encontrar el elemento en la posicion i si el array S estuviese ordenado
// encontrar el i-esimo elemento mas pequeño de S(indice 0-based)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#define all(x) (x).begin(), (x).end()
#define forn(i,a,n) for (int i=int(a);i<int(n);i++)
#define CIN(...) input(__VA_ARGS__)

template<typename T>
void input(T &x) {cin >> x;}

template<typename T, typename... Args>
void input(T &x, Args&... args)
{
    cin >> x ;
    input(args...);
}

#define COUT(...) output(__VA_ARGS__)

template<typename T>
void output(const T&x) {cout << x <<endl;}

template<typename T, typename... Args>
void output(const T&x, const Args&...args)
{
    cout << x << " ";
    output(args...);
}

//----------------------------------------------------------------------

//----------------------------------------------------------------------

//----------------------------------------------------------------------

//----------------------------------------------------------------------

//----------------------------------------------------------------------

//----------------------------------------------------------------------

//----------------------------------------------------------------------

//----------------------------------------------------------------------

int getMedian(vi &v)
{
    sort(all(v));
    return v[v.size()/2];
}


int MedianOfMedians(vi &S)
{
    // dividir en grupos de 5
    int n= S.size();

    if(n<=5) return getMedian(S);

    vi medians;


    for(int i=0;i< n;i +=5)
    {
        vi group;
        for(int j=i;j< min(i+5,n);j++)
        {
            group.push_back(S[j]);
        }

        medians.push_back(getMedian(group));
    }

    return MedianOfMedians(medians);
}



int Select(vi &S, int i)
{
    if(S.size() == 1)return S[0];

    int x = MedianOfMedians(S);

    vi less,equal,greater;

    for(int val:S)
    {
        if(val < x) less.push_back(val);
        else if(val == x) equal.push_back(val);
        else greater.push_back(val);
    }
    int k= equal.size() + less.size();

    if(k == i)
        return x;
        
    if(k > i)
        return Select(less,i);

    return Select(greater,i - k);
}

void solve(){

    int n,q;
    CIN(n,q);

    vi a(n);

    forn(i,0,n)CIN(a[i]);

    while(q--)
    {
        int p;
        CIN(p);

        COUT(Select(a,p));
    }
}

int main()
{

    ios::sync_with_stdio(false);
    int t;
    CIN(t);

    while(t--) solve();
    
    return 0;
    
}