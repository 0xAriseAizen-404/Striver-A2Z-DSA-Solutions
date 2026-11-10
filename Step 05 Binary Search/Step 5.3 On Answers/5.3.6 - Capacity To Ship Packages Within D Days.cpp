class Solution {
public:
    static bool isPossible(vector<int>& weights, int days, int capacity) {
        int currDays = 1;
        int loadCapacity = 0;
        for(int weight : weights) {
            if(weight + loadCapacity > capacity) {
                currDays += 1;
                loadCapacity = weight;
            } else
                loadCapacity += weight;
        }
        return currDays<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while(low <= high) {
            int capacity = low + (high - low) / 2;
            if(isPossible(weights, days, capacity))  high = capacity - 1;
            else low = capacity + 1;
        }
        return low;
    }
};