#include <set>
#include <vector>
//
// Created by vinayak on 26-07-2024.
//
using namespace std;

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    set<pair<int,int>> st;
    vector<int> dist(V,1e9);
    st.insert({0,S});
    dist[S] = 0;
    while (!st.empty()) {
        auto it = *(st.begin());
        int node = it.second;
        int dis  = it.first;
        st.erase({dis,node});
        for (auto it : adj[node]) {
            int adjNode = it[0];
            int wt = it[1];
            if (dis + wt < dist[adjNode]) {
                if (dist[adjNode] != 1e9) {
                    st.erase({dist[adjNode],adjNode});
                }
                dist[adjNode] = dis + wt;
                st.insert({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
}