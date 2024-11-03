#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
/*
The Fenwick tree is a data structure which:
- calculates the value of function f in the given range [l,r] in O(logN) time
- update the values of an element of A in O(logN) time
- requires O(N) memory

*/


struct FenwickTree{

    vi bit;
    int n;

    FenwickTree(int n){
        this->n=n;
        bit.assign(n,0);
    }

    FenwickTree(vi const& a):FenwickTree(a.size()){
        for(size_t i=0;i<a.size();i++){
            add(i,a[i]);
        }
    }

    int sum(int r){
        int ret=0;
        for(; r>=0;r=(r&(r+1)) -1)
            ret+= bit[r];
        return ret;
    }

    int sum(int l,int r){
        return sum(r)-sum(l-1);
    }

    void add(int idx, int delta){
        for(; idx<n;idx=idx | (idx+1))
            bit[idx]+= delta;
    }
};


struct FenwickTreeMin{

    vi bit;
    int n;
    const int INF =(int)1e9;

    FenwickTreeMin(int n){
        this->n=n;

        bit.assign(n,0);
    }

    FenwickTreeMin(vi a): FenwickTreeMin(a.size()){
        for(size_t i=0;i<a.size();i++){
            update(i,a[i]);
        }
    }

    int getmin(int r){
        int ret=INF;

        for(;r>=0;r<(r&(r+1))-1){
            ret = min(ret,bit[r]);
        }

        return ret;
    }

    void update(int idx, int val){
        for(;idx<n;idx= idx | (idx+1))
            bit[idx]= min(bit[idx],val);
    }
};


int main(){

    vi alpha={12,32,34,12,23,45};

   FenwickTree* t= new FenwickTree(alpha);

    cout<<t->sum(2)<<endl;

    FenwickTreeMin* q= new FenwickTreeMin(alpha);

    cout<<q->getmin(4)<<endl;
   
    return 0;

}