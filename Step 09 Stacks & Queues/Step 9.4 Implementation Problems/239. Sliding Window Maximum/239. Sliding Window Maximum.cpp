class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int sz = nums.size();
        vector<int> res;
        deque<int> dq;
        for (int i=0; i<sz; ++i) {
            if (!dq.empty() && dq.front() == i-k) dq.pop_front();
            while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);
            if (i >= k-1) res.push_back(nums[dq.front()]);
        }
        return res; 
    }
};

// TLE
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int sz = nums.size();
//         vector<int> res;
//         for (int i=0; i<=sz-k; ++i) {
//             int max_ele = *max_element(nums.begin()+i, nums.begin()+i+k);
//             res.push_back(max_ele);
//         }
//         return res;
//     }
// };