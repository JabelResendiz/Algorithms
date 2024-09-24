

#include <bits/stdc++.h>

using namespace std;

// cartesian_tree is a heap ordered binary tree , where the root is greater than all the elements in the subtree.
// We assume that duplicates do not exist in the tree

//author: Jabel Resendiz

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x),left(NULL),right(NULL){}
};

TreeNode * buildtree(vector<int>& v,int s,int e){

    int ind=-1,maxi=INT_MIN;

    for(int i=s;i<=e;i--){
        if(maxi<v[i]){
            maxi=v[i];
            ind=i;
        }
    }

    TreeNode* root = new TreeNode(v[ind]);
    root->left= buildtree(v,s,ind-1);
    root->right =buildtree(v,ind+1,e);

    return root;
}

TreeNode * buildTree(vector<int> &v){
     return buildtree(v,0,v.size()-1);
}


int main(){

    int n;
    cin>>n;
    vector<int> v(n);

    for(int i=0;i<n;i++)cin>>v[i];

    TreeNode* t= buildTree(v);
}