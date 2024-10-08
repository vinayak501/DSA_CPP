#include <stack>
#include <unordered_map>
#include <vector>
//
// Created by vinayak on 15-07-2024.
//
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,int> mpp;
    stack<int> st;
    for (int i=nums2.size()-1;i>=0;i--) {
        while (!st.empty() && nums2[i] >= st.top()) {
            st.pop();
        }
        mpp[nums2[i]] = st.empty() ? -1 : st.top();
        st.push(nums2[i]);
    }
    vector<int> ans;
    for (int i:nums1) {
        ans.push_back(mpp[i]);
    }
    return ans;
}