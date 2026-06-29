// HashMap + MonotonicStack Approach
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        stack<int> mds; // monotonic_decreasing_stack
        int sz = nums2.size();
        for (int i=sz-1; i>=0; --i) {
            int val = nums2[i];
            while (!mds.empty() && val >= mds.top()) mds.pop();
            mp[val] = mds.empty() ? -1 : mds.top();
            mds.push(val);
        }
        vector<int> ans;
        for (int &x: nums1) ans.push_back(mp[x]);
        return ans;
    }
};
// TC: O(m + n)
// SC: O(m)

// BruteForce Iterative Solution
// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> ans;
//         for (int &x: nums1) {
//             int ind = 0;
//             bool flag = false;
//             while (x != nums2[ind]) ind++;
//             for (int k=ind+1; k<nums2.size(); ++k) {
//                 if (nums2[k] > nums2[ind]) {
//                     ans.push_back(nums2[k]);
//                     flag = true;
//                     break;
//                 }
//             }
//             if (!flag) ans.push_back(-1);
//         }
//         return ans;
//     }
// };
// TC: O(n * m)
// SC: O(n)