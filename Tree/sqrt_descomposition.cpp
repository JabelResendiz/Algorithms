

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

const int MAX_N = 100000;
int a[MAX_N];
int current_sum = 0;
int block_size;

void add(int idx)
{
    current_sum += a[idx];
}

void remove(int idx)
{
    current_sum -= a[idx];
}

int get_answer()
{
    return current_sum;
}

struct Query
{
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

vector<int> mo_s_algorithm(vector<Query> queries)
{
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure

    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries)
    {
        while (cur_l > q.l)
        {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r)
        {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l)
        {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r)
        {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }
    return answers;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    block_size = sqrt(n) + 1;
    vector<Query> queries(q);

    for (int i = 0; i < q; ++i)
    {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--, queries[i].r--;
        queries[i].idx = i;
    }

    vector<int> answers = mo_s_algorithm(queries);

    for (int ans : answers)
        cout << ans << '\n';

    return 0;
}
