#include <vector>
//
// Created by vinay on 02-06-2025.
//
using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> count(n,1);
    for (int i=1;i<n;i++) {
        if (ratings[i] > ratings[i-1]) {
            count[i] = max(count[i],count[i-1] + 1);
        }
    }
    for (int i=n-2;i>=0;i--) {
        if (ratings[i] > ratings[i+1]) {
            count[i] = max(count[i],count[i+1]+1);
        }
    }
    int res = 0;
    for (int i=0;i<n;i++) {
        res += count[i];
    }
    return res;
}