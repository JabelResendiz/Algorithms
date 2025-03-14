

/*
Findig sum of the elements of the sub-array
Findgin the maximla/minimal element

O(sqrt(N))

*/

/*Finding sum of the elements on the interval [l,r]*/

#include <bits/stdc++.h>

using namespace std;

void sqrt_descomposition()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int len = (int)sqrt(n + .0) + 1; // size of the block and the number of blocks

    vector<int> b(len);

    for (int i = 0; i < n; ++i)
        b[i / len] += a[i];

    for (;;)
    {
        int l, r; // query
        cin >> l >> r;

        int sum = 0;
        int c_l = l / len, c_r = r / len;
        if (c_l == c_r)
            for (int i = l; i <= r; ++i)
                sum += a[i];
        else
        {
            for (int i = l, end = (c_l + 1) * len - 1; i <= end; ++i)
                sum += a[i];
            for (int i = c_l + 1; i <= c_r - 1; ++i)
                sum += b[i];
            for (int i = c_r * len; i <= r; ++i)
                sum += a[i];
        }

        cout << sum << endl;
    }
}

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     sqrt_descomposition();
// }

//// MO's Algorithm
//// Complxty: O((N+Q) sqrt(N))


#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;
const int maxq = 1e5+10;
const int bucket = 320;

struct Query {
	int l, r, bloco, id;
} q[maxq];

int ans[maxn], num[maxn], aux;

// arbitrary functions
void add(int x) {}

void rem(int x) {}

bool comp(Query a, Query b)
{
	if (a.bloco == b.bloco) return a.r < b.r;
	return a.bloco < b.bloco;
}

int main(void)
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> num[i];

	for (int i = 0; i < m; i++)
	{
		cin >> q[i].l >> q[i].r;

		q[i].id = i, q[i].bloco = q[i].l/bucket;
	}

	sort(q, q+m, comp);

	int l = 1, r = 1;

	for (int i = 0; i < m; i++)
	{
		int ql = q[i].l, qr = q[i].r;

		while (r > qr) rem(r--);
		while (r < qr) add(++r);
		while (l > ql) add(--l);
		while (l < ql) rem(l++);

		ans[q[i].id] = aux;
	}
}