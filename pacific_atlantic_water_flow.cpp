#include<bits/stdc++.h>
using namespace std;
void bfs(vector<vector<int>> &heights,queue<pair<int,int>> &ocean,vector<vector<bool>> &set){
    int m = heights.size();
    int n = heights[0].size();
    vector<pair<int,int>> dir = {{0,1},{0,-1},{-1,0},{1,0}};
    while(!ocean.empty()){
        auto [r,c] =ocean.front();
        ocean.pop();
        for(auto it:dir){
            int newX = r + it.first;
            int newY = c + it.second;
            if(newX >= 0 && newX < m && newY >= 0 && newY < n && !set[newX][newY] && heights[newX][newY] >= heights[r][c]){
                set[newX][newY] = true;
                ocean.push({newX,newY});
            }
        }
    }
}
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int m = heights.size();
    int n = heights[0].size();
    vector<vector<bool>> set_p(m,vector<bool>(n,false));
    vector<vector<bool>> set_a(m,vector<bool>(n,false));
    queue<pair<int,int>> atlantic;
    queue<pair<int,int>> pacific;
    for(int i=0;i<m;i++){
        set_p[i][0] = true;
        pacific.push({i,0});
        set_a[i][n-1] = true;
        atlantic.push({i,n-1});
    }
    for(int i=0;i<n;i++){
        set_p[0][i] = true;
        pacific.push({0,i});
        set_a[m-1][i] = true;
        atlantic.push({m-1,i});
    }
    bfs(heights,pacific,set_p);
    bfs(heights,atlantic,set_a);
    vector<vector<int>> res;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(set_p[i][j] && set_a[i][j]){
                res.push_back({i,j});
            }
        }
    }
    return res;
}