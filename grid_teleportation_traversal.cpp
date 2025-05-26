#include<bits/stdc++.h>
using namespace std;

bool isvalid(int i,int j,int n,int m,vector<string> &matrix){
        if(i < 0 || j < 0 || i >= n || j >= m) return false;
        if(matrix[i][j] == '#') return false;
        return true;
    }
    int minMoves(vector<string>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_map<char,vector<pair<int,int>>> cells;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] != '.' && matrix[i][j] != '#'){
                    cells[matrix[i][j]].push_back({i,j});
                }
            }
        }
        if(matrix[n-1][m-1] == '#') return -1;
        deque<tuple<int,int,int>> dq;
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        unordered_set<char> used;

        dq.push_back({0,0,0});
        dis[0][0] = 0;
        int dx[4] = {0,0,-1,1};
        int dy[4] = {-1,1,0,0};

        while(!dq.empty()){
            auto [currDist,x,y] = dq.front();
            dq.pop_front();

            if(currDist > dis[x][y]) continue;

            if(x == n-1  and y == m-1) return currDist;
            if(isupper(matrix[x][y]) && used.find(matrix[x][y]) == used.end()){
                used.insert(matrix[x][y]);
                for(auto &[newX,newY] : cells[matrix[x][y]]){
                    if(currDist < dis[newX][newY]){
                        dis[newX][newY] = currDist;
                        dq.push_front({currDist,newX,newY});
                    }
                }
            }
            for(int k=0;k<4;k++){
                int nextX = x + dx[k];
                int nextY = y + dy[k];
                if(isvalid(nextX,nextY,n,m,matrix) && (1+currDist < dis[nextX][nextY])){
                    dis[nextX][nextY] = 1+currDist;
                    dq.push_back({1+currDist,nextX,nextY});
                }
            }
        }
        return -1;
    }