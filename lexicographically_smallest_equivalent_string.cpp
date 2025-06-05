#include<bits/stdc++.h>

string dfs(unordered_map<int,vector<int>> &adj,char currChar,vector<int> &vis){
    vis[currChar - 'a'] = 1;
    char minChar = currChar;
    for(auto &v:adj[currChar]){
        if(vis[v-'a'] == 0){
            minChar = min(minChar,dfs(adj,v,vis));
        }
    }
    return minChar;
}

string smallestEquivalentString(string s1, string s2, string baseStr) {
    int n = s1.size();
    unordered_map<char,vector<char>> adj;
    for(int i=;i<n;i++){
        int u = s1[i];
        int v = s2[i];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }        
    string result;
    for(int i=0;i<baseStr.size();i++){
        char currChar = baseStr[i];
        vector<int> vis(26,0);
        char minChar = dfs(adj,currChar,vis);
        result.push_back(minChar);
    }
    return minChar;
}