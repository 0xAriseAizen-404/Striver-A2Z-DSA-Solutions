#define all(v) (v).begin(), (v).end()
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
using ll = long long;
class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        fastio
        // nums.erase(unique(all(nums)), nums.end());
        // return nums.size();
        
        int n = nums.size();
        int ind = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] != nums[i + 1]) nums[ind++] = nums[i];
        }
        nums[ind++] = nums[n - 1];
        return ind;
    }
};