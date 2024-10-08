#include <vector>
//
// Created by vinayak on 11-07-2024.
//
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int n = nums.size();
    int maxlen = 0;
    int r=0,l=0;
    int zeros = 0;
    while (r < n) {
        if (nums[r] == 0) zeros++;
        while (zeros > k) {
            if (nums[l] == 0) zeros--;
            l++;
        }
        if (zeros <= k) {
            maxlen = max(maxlen , r-l+1);
        }
        r++;
    }
    return maxlen;
}