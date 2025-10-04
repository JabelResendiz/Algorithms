


// finding the nearest pair of points


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

struct pt {
    int x,y,id;
};


struct cmp_x {
    bool operator() (const pt&a, const pt & b) const {
        return a.x < b.x || (a.x== b.x && a.y < b.y);
    }
};


struct cmp_y {
    bool operator() (const pt& a, const pt&b) const {
        return a.y < b.y;
    }
};



int n;
vector<pt> a, t;
double mindist;
ii best_pair;


// actualizar la mejor distancia y el par mas cercano
void upd_ans(const pt &a, const pt&b)
{
    double dist = sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));

    if (dist < mindist)
    {
        mindist = dist;
        best_pair ={a.id,b.id};
    }
}



void rec(int l, int r)
{
    if(r-l <= 3)
    {
        for(int i=l;i<r; ++i)
        {
            for(int j=i+1;j<r; ++j)
            {
                upd_ans(a[i],a[j]);
            }
        }

        sort(a.begin()+l,a.begin()+r,cmp_y());
        return;
    }


    int m = (l+r) >> 1; // punto medio
    int midx = a[m].x;

    rec(l,m);
    rec(m,r);

    merge(a.begin() + l, a.begin() + m, a.begin() + m, a.begin() + r, t.begin(), cmp_y());
    copy(t.begin(), t.begin() + r - l, a.begin() + l);


    int tsz = 0;
    for (int i = l; i < r; ++i) {
        if (abs(a[i].x - midx) < mindist) {
            for (int j = tsz - 1; j >= 0 && a[i].y - t[j].y < mindist; --j)
                upd_ans(a[i], t[j]);
            t[tsz++] = a[i];
        }
    }

}


void solve()
{
    CIN(n);

    a.resize(n);

    forn(i,0,n)
    {
        CIN(a[i].x,a[i].y);
        a[i].id = i;
    }

    t.resize(n);

    sort(all(a),cmp_x());

    mindist = 1E20;
    rec(0,n);

    COUT("Par mas cercano: ", best_pair.first," ",best_pair.second);
    COUT("Distncia minima: ", mindist);
}

int main()
{

    ios::sync_with_stdio(false);
    int t;
    cin >>t;

    while(t--) solve();
    
    return 0;
    
}