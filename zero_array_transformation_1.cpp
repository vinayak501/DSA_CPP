#include<bits/stdc++.h>
using namespace std;
bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) { 
    int n = nums.size();
    vector<int> temp(n,0);
    for(vector<int> query:queries){
        temp[query[0]]++;
        if(query[1]+1 < n){
            temp[query[1]+1]--;
        }
    } 
    vector<int> cumsum(n,0);
    cumsum[0] = temp[0];
    for(int i=1;i<n;i++){
        cumsum[i] = cumsum[i-1] + temp[i];
    }
    for(int i=0;i<n;i++){
        if(nums[i] > cumsum[i]){
            return false;
        }
    }
    return true;
}