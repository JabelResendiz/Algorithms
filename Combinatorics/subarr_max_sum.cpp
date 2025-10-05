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


// buscar el subarray de suma maxima en O(n)

void search_maximum_sum(const vi&a)
{
    int n= a.size();

    ll ans= a[0]; // resultado: el valor del maximo
    ll sum =0; // prefijo acumulado actual
    ll min_sum = 0; // el prefijo mas pequeño visto hasta el momento
    int ans_l =0, ans_r = 0; 

    int min_pos = -1; //indice del prefijo maximo


    forn(r,0,n)
    {
        sum += a[r];
        ll cur = sum - min_sum; // valor del prefijo actaul menos le minimo encontrado

        if(cur > ans) // si cur es mejor que lo que teniamos
        {
            ans = cur;
            ans_l = min_pos +1;
            ans_r = r;
        }


        if(sum < min_sum) // si la suma actual es menor que lo que hemos encontrado, entonces actualizar
        {
            min_sum = sum;
            min_pos = r;
        }
    }


    COUT("Maxima suma: ", ans);
    COUT("Subarray desde indice: ", ans_l," hasta ", ans_r );

    forn(i,ans_l,ans_r+1)cout<< a[i] << " ";
    cout << endl;
}


void search_minimum_sum(const vi&a)
{
    int n= a.size();

    ll ans= a[0];
    ll sum =0;
    ll max_sum = 0;
    int ans_l =0, ans_r = 0;

    int max_pos = -1;


    forn(r,0,n)
    {
        sum += a[r];
        ll cur = sum - max_sum;

        if(cur< ans)
        {
            ans = cur;
            ans_l = max_pos +1;
            ans_r = r;
        }


        if(sum > max_sum)
        {
            max_sum = sum;
            max_pos = r;
        }
    }


    COUT("Maxima suma: ", ans);
    COUT("Subarray desde indice: ", ans_l," hasta ", ans_r );

    forn(i,ans_l,ans_r+1)cout<< a[i] << " ";
    cout << endl;
}

int main()
{

    ios::sync_with_stdio(false);
    
    vi a  = {2,4,-1,3,5,9};

    search_maximum_sum(a);
    search_minimum_sum(a);
    
    
    return 0;
    
}