#include <iostream>
#include <algorithm>
#include <vector>
#include "kruskal.cpp"
#include "prim.cpp"
using namespace std;



int main(){

    vector<Edge> edges = {{0, 1, 3}, {0, 7, 8}, {1, 7, 11}, {1, 2, 8}, {2, 8, 2}, {2, 3, 7}, {2, 5, 4}, {3, 4, 9}, {3, 5, 14}, {4, 5, 10}, {5, 6, 2}, {6, 7, 1}, {6, 8, 6}, {7, 8, 7}};
    
    Kruskal obj;
    
    
    cout << obj.kruskal(14, edges);
}
