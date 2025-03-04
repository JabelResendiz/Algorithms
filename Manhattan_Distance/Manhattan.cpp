
#include <bits/stdc++.h>

using namespace std;


// d(p,q)= |xp - xq| + |yp - yq|
// max [(xp + (-xq)) + (yp + (-yq))] = max (xp + yp) + max(-xq-yq)
// maximum distance between two points in a d-dimensional space

//vector<vector<int>> p - n points of d-dimensional
// O(n*d*2^d)

long long FarthestPairManhattanDistance(int d,int n, vector<vector<int>>p)
{
    long long ans =0;

    for (int msk = 0; msk < (1 << d); msk++) {
        long long mx = LLONG_MIN, mn = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            long long cur = 0;
            for (int j = 0; j < d; j++) {
                if (msk & (1 << j)) cur += p[i][j];
                else cur -= p[i][j];
            }
            mx = max(mx, cur);
            mn = min(mn, cur);
        }
        ans = max(ans, mx - mn);
    }

    return ans;
}

int main()
{
    

}