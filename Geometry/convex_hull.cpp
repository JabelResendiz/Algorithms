
#include<bits/stdc++.h>
using namespace std;


/*

Resolver de DP 

*/


using ll= long long;
using point =pair<ll,ll>;

#define x first
#define y second

point operator -(point a,point b){
    return {a.x-b.x,a.y-b.y};
}

ll dot(point a,point b){
    return a.x*b.x+a.y*b.y;
}

ll cross(point a, point b){
    return a.x*b.y-a.y*b.x;
}

ll area2(point a,point b,point c){
    return cross(b-a,c-a);
}

struct ConvexHull: vector<point>{

    //Complexity Time: O(1)
    void add(point p){
        // point p should e given in increase x order , if not, sort y
        while(size()>= 2 && area2(at(size()-2),at(size()-1),p)>=0)
            pop_back();

        push_back(p);
    }

    //Complexity Time:O(log(n) ) Binary Search
    ll max_dot(point q){
        int l=0,r=size()-1;

        while(l<r){
            int mid=(l+r)/2;
            point p1=at(mid);
            point p2 =at(mid-1);
            if(dot(p1,q)<dot(p2,q)){
                l=mid+1;
            }else{
                r=mid;
            }
        }

        return dot(at(l),q);
    }
};



int main(){

    
}