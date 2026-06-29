class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> mds; // monotonic_decreasing_stack
        vector<int> ans(n, -1);
        for(int itr=1; itr<=2; ++itr) {
            for (int i=n-1; i>=0; --i) {
                int val = nums[i];
                while (!mds.empty() && val >= mds.top()) mds.pop();
                ans[i] = mds.empty() ? -1 : mds.top();
                mds.push(val);
            }
        }
        return ans;
    }
};
// TC: O(m + n)
// SC: O(m)

// BruteForce Solution
// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
//         vector<int> ans;
//         int n = nums.size();
//         for (int i=0; i<n; ++i) {
//             bool flag = false;
//             for (int ind=(i+1)%n; ind!=i; ind=(ind+1)%n) {
//                 if (nums[ind] > nums[i]) {
//                     ans.push_back(nums[ind]);
//                     flag = true;
//                     break;
//                 }
//             }
//             if (!flag) ans.push_back(-1);
//         }
//         return ans;
//     }
// };
// TC: O(m + n)
// SC: O(m)