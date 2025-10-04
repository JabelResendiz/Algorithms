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



int merge(vi &arr, int left, int mid, int right)
{

    int n1 = mid-left +1;
    int n2 = right - mid;

    vi leftArr(n1);
    vi rightArr(n2);

    forn(i,0,n1) leftArr[i] = arr[left +i];
    forn(i,0,n2) rightArr[i] = arr[mid+1+i];


    // contar el numero de inversiones O(n)
    int inversions = 0;

    int a = mid, b= right;

    while(a >=left && b > mid)
    {
        if(arr[a] > arr[b])
        {
            inversions += (b-mid);
            a --;
        }
        else if(arr[a] < arr[b])
        {
            b--;
        }
    }

    // continuar con el ordenamiento

    int i =0, j =0, k=left;

    while(i < n1 && j<n2)
    {
        if(leftArr[i] < rightArr[j])
        {
            arr[k] = leftArr[i++];
        }
        else 
        {
            arr[k] = rightArr[j++];
        }

        k++;
    }


    while(i< n1)
    {
        arr[k] = leftArr[i++];
        k++;
    }

    while(i < n2)
    {
        arr[k] = rightArr[i++];
        k++;
    }


    return inversions;
}

int mergeSort(vi &arr, int left, int right)
{
    if(left < right)
    {
        int mid = left + ((right-left) >> 1);

        int h=mergeSort(arr,left,mid);
        int v= mergeSort(arr,mid+1,right);

        return h+v+merge(arr,left,mid,right);
    }

    return 0;
}

int mergeSort(vi &arr)
{
    return mergeSort(arr,0,arr.size()-1);
}

int counting_inversions(vi &a)
{
    // si es necesario copiar el array para no afectar el original a 
    return mergeSort(a);
}


// void solve()
// {
//      int n;
//      CIN(n);

//      vi a(n);
//      forn
    

// }


int main()
{

    ios::sync_with_stdio(false);
    // int t;
    // cin >>t;

    // while(t--) solve();


    vi a  = {2,4,1,3,5,-9};

    cout << counting_inversions(a) <<endl;

    forn(i,0,a.size())
    {
        cout << a[i] << " ";
    }

    cout << endl;
    
    return 0;
    
}