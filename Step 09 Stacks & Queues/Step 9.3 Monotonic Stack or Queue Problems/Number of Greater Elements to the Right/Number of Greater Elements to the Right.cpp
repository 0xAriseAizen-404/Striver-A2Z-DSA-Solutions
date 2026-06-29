// https://www.geeksforgeeks.org/problems/number-of-nges-to-the-right/1

class Solution {
  public:
    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        vector<int> ans;
        for (int idx : indices) {
            int cnt = 0;
            for (int j = idx + 1; j < arr.size(); j++) {
                if (arr[j] > arr[idx]) cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};