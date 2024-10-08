#include <vector>
//
// Created by vinayak on 17-07-2024.
//
using namespace std;

#include "TreeNode.h"

void solve(TreeNode* root,int level,vector<int>& ans) {
    if (root == NULL) return;
    if (ans.size() == level) ans.push_back(root->val);
    solve(root->right,level+1,ans);
    solve(root->left,level+1,ans);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    solve(root,0,ans);
    return ans;
}