
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vi vector<int>
#define vii vector<vi>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()

// https://codeforces.com/contest/1093/problem/G
// O((n+q)*2^k * log(n))

const int N = 200043;
const int INF = int(1e9);

int T[4 * N][32];
int A[4 * N][5];
int n, k;

// build segment tree
void build(int v, int l, int r)
{
    if (l == r - 1)
    {
        for (int i = 0; i < (1 << k); i++)
        {
            int cur = 0;
            for (int j = 0; j < k; j++)
                if (i & (1 << j))
                    cur += A[l][j];
                else
                    cur -= A[l][j];
            T[v][i] = cur;
        }
    }
    else
    {
        int m = (l + r) / 2;
        build(v * 2 + 1, l, m);
        build(v * 2 + 2, m, r);
        for (int i = 0; i < (1 << k); i++)
            T[v][i] = min(T[v * 2 + 1][i], T[v * 2 + 2][i]);
    }
}


int query(int v, int l, int r, int L, int R, int x)
{
    if (L >= R)
        return INF;
    if (L == l && R == r)
        return T[v][x];
    int m = (l + r) / 2;
    return min(query(v * 2 + 1, l, m, L, min(R, m), x), query(v * 2 + 2, m, r, max(L, m), R, x));
}

void update(int v, int l, int r, int z)
{
    if (l == r - 1)
    {
        for (int i = 0; i < (1 << k); i++)
        {
            int cur = 0;
            for (int j = 0; j < k; j++)
                if (i & (1 << j))
                    cur += A[l][j];
                else
                    cur -= A[l][j];
            T[v][i] = cur;
        }
    }
    else
    {
        int m = (l + r) / 2;
        if (z < m)
            update(v * 2 + 1, l, m, z);
        else
            update(v * 2 + 2, m, r, z);
        for (int i = 0; i < (1 << k); i++)
            T[v][i] = min(T[v * 2 + 1][i], T[v * 2 + 2][i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> A[i][j];
        }
    }

    int q;
    cin >> q;
    build(0, 0, n);

    for (int i = 0; i < q; i++)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int index;
            cin >> index;
            --index;
            for (int p = 0; p < k; p++)
            {
                cin >> A[index][p];
            }
            update(0, 0, n, index);
        }

        else
        {
            int ans = 0;
            int l, r;
            cin>>l>>r;
            --l;
            for (int i = 0; i < (1 << (k - 1)); i++)
            {
                int x = query(0, 0, n, l, r, i);
                int y = query(0, 0, n, l, r, ((1 << k) - 1) ^ i);
                ans = max(ans, abs(x + y));
            }
            cout<< ans<<endl;
        }
    }

    return 0;
}