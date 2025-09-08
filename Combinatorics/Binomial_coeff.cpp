#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vi vector<int>
#define vii vector<vi>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define forn(i, a, n) for (int i = int(a); i < int(n); i++)

const int MAXN = 200000; // 2 * 10^5 para cubrir 2n-1
const int MOD = 1000000007;

vll factorial(MAXN + 1);
vll inverse_factorial(MAXN + 1);

// Exponenciación rápida para inverso modular
ll power(ll a, ll b, ll m) {
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = res * a % m;
        }
        a = a * a % m;
        b /= 2;
    }
    return res;
}

void precompute()
{
    factorial[0] = 1;
    for (int i = 1; i <= MAXN; i++)
    {
        factorial[i] = factorial[i - 1] * i % MOD;
    }

    // Inverso del último factorial usando Fermat
    inverse_factorial[MAXN] = power(factorial[MAXN], MOD - 2, MOD);

    // Precomputar inversos factorales hacia atrás
    for (int i = MAXN - 1; i >= 0; i--)
    {
        inverse_factorial[i] = (inverse_factorial[i + 1] * (i + 1)) % MOD;
    }
}

ll binomial(int n, int k)
{
    if (k > n || k < 0)
        return 0;
    return factorial[n] * inverse_factorial[k] % MOD * inverse_factorial[n - k] % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    precompute();

    int n;
    cin >> n;

    cout << ((2*binomial(2 * n - 1, n))%MOD-n)%MOD << '\n';

    return 0;
}
