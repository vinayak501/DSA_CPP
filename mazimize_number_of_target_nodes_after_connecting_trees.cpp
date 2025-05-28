#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>
//
// Created by vinay on 28-05-2025.
//
using namespace std;

int bfs(int curr,unordered_map<int,vector<int>>& adj,int d,int N) {
    queue<pair<int,int>> q;
    q.push({curr, 0});
    vector<bool> vis(N,false);
    vis[curr] = true;
    int count = 0;
    while (!q.empty()) {
        int currNode = q.front().first;
        int dist = q.front().second;
        q.pop();
        if (dist > d) {
            continue;
        }
        count++;
        for (auto &nghr:adj[currNode]) {
            if (!vis[nghr]) {
                vis[nghr] = true;
                q.push({nghr,dist+1});
            }
        }
    }
    return count;
}

vector<int> findCount(vector<vector<int>> &edges,int d) {
    int N = edges.size() + 1;
    unordered_map<int,vector<int>> adj;
    for (auto edge : edges) {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> result(N);
    for (int i=0;i<N;i++) {
        result[i] = bfs(i,adj,d,N);
    }
    return result;
}

vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
    int N = edges1.size() + 1;
    vector<int> result1 = findCount(edges1,k);  // within k distance
    vector<int> result2 = findCount(edges2,k-1);  //  within k-1 distance
    int maxFromResuult2 = *max_element(begin(result2),end(result2));
    for(int i=0;i<result1.size();i++) {
        result1[i] += maxFromResuult2;
    }
    return  result1;

}