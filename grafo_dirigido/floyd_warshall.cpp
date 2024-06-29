#include <bits/stdc++.h>

#define vi vector<int>
#define vii vector<vector<int>>

using namespace std;

int infinite = (int)1e9;

// Restriccion: Pueden haber arcos de costo negativo pero no ciclos de costo negativo
// o(V^3)
void floyd_warshall(vii &matrix){

    for(int k=0;k<matrix.size();k++){
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix.size();j++){
                matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
            }
        }
    }
}
