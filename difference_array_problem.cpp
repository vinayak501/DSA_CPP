#include<bits/stdc++.h>
using namespace std;

// Question is we have to modify range of given array as they say 
// [1,2,3,4,5] this is array
// [[0,2,3],[1,4,-2]] 
// this means in range 0 to 2 we have to add 3
// and in range 1 to 4 we have to add -2

// we can do this using brute force but it will be near about O(Q*n) in worst case 
// so here we will use difference array technique 
// for example [0,0,0,0,0] here in range of [0,2] we have to add 5 
// so at arr[start] += 5 and arr[end+1] -= 5 
// [5,0,0,-5,0]
// now take cumilitive some of this 
// [5,5,5,0,0]

vector<int> differenceArray(vector<int> &nums,vector<vector<int>> &queries){
    int n = nums.size()
    for(vector<int> query:queries){
        int start = query[0];
        int end = query[1];
        int toSum = query[2];
        nums[start] += toSum;
        if(end + 1 < n){
            nums[end+1] -= toSum; 
        }
    }
    vector<int> cumSum(n,0);
    cumSum[0] = nums[0];
    for(int i=1;i<n;i++){
        cumSum[i] = cumSum[i-1] + nums[i];
    }
    return cumSum;
}