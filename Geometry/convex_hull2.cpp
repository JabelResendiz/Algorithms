
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using point = pair<ll,ll>;
#define x first
#define y second

point operator-(point a, point b){ return {a.x - b.x, a.y - b.y}; }
ll cross(point a, point b){ return a.x*b.y - a.y*b.x; }
ll area2(point a, point b, point c){ return cross(b-a, c-a); }

class Solution {
public:
    vector<vector<int>> findConvexHull(vector<vector<int>>& points) {
        if (points.size() <= 2) return {{-1}};

        sort(points.begin(), points.end());

        vector<point> pts(points.size());
        for (int i = 0; i < points.size(); i++)
            pts[i] = {points[i][0], points[i][1]};

        vector<point> lower, upper;

        // lower hull
        for (auto &p : pts) {
            while (lower.size() >= 2 && area2(lower[lower.size()-2], lower.back(), p) <= 0)
                lower.pop_back();
            lower.push_back(p);
        }

        // upper hull
        for (int i = (int)pts.size()-1; i >= 0; i--) {
            auto p = pts[i];
            while (upper.size() >= 2 && area2(upper[upper.size()-2], upper.back(), p) <= 0)
                upper.pop_back();
            upper.push_back(p);
        }

        lower.pop_back();
        upper.pop_back();

        vector<point> hull = lower;
        hull.insert(hull.end(), upper.begin(), upper.end());

        vector<vector<int>> output;
        
        if(hull.size()<3) return  {{-1}};
        
        for (auto &p : hull)
            output.push_back({(int)p.x, (int)p.y});
        
        
        
        return output;
    }
};
