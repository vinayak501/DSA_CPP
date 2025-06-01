#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>
//
// Created by vinay on 29-05-2025.
//
using namespace std;

int bfs(int curr,unordered_map<int,vector<int>> &adj,int N,bool even) {
    queue<pair<int,int>> q;
    q.push({curr,0});
    vector<bool> vis(N,false);
    vis[curr] = true;
    int count = 0;
    while (!q.empty()) {
        int currNode = q.front().first;
        int dis = q.front().second;
        q.pop();
        if (even) {
            if (dis/2 == 0) count++;
        }else {
            if (dis/2 != 0) count++;
        }
        for (auto &nghr:adj[currNode]) {
            if (!vis[nghr]) {
                vis[nghr] = true;
                q.push({nghr,dis+1});
            }
        }
    }
    return count;
}

vector<int> findCount(vector<vector<int>> &edges,bool even) {
    int N = edges.size()+1;
    unordered_map<int,vector<int>> adj;
    for (auto edge:edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
    }
    vector<int> res(N);
    for (int i=0;i<N;i++) {
        res[i] = bfs(i,adj,N,even);
    }
    return res;
}

vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
    int N = edges1.size() + 1;
    vector<int> result1 = findCount(edges1,true);
    vector<int> result2 = findCount(edges2,false);
    int maxFromResult2 = *max_element(result2.begin(),result2.end());
    for (int i=0;i<result1.size();i++) {
        result1[i] += maxFromResult2;
    }
    return result1;
}