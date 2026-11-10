class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        // int n = nums.size();
        // if(n==0) return {-1, -1};
        // int low = 0;
        // int high = n - 1;
        // int startPos = -1;
        // int endPos = -1;
        // while(low < high){
        //     int mid = low + (high - low) / 2;
        //     if(nums[mid] == target){
        //         if(startPos == -1) startPos = mid;
        //         else endPos = mid;
        //         low = mid+1;
        //     }
        //     else if(nums[mid] < target) low = mid;
        //     else high = mid;
        // }
        // return {startPos, endPos};
        
        
        int low = 0, high = nums.size()-1;
        int start = -1, end = -1;

        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid] < target){ low = mid+1; }
            else if(nums[mid] > target){ high = mid-1; }
            else{   // nums[mid] == target
                start = mid;
                high = mid-1;
            }
        }
        
        // Searching the end index of target
        if(start!=-1){
            low = 0, high = nums.size()-1;
            while(low<=high){
                int mid = low + (high-low)/2;
                if(nums[mid] < target){ low = mid+1; }
                else if(nums[mid] > target){ high = mid-1; }
                else{   // nums[mid] == target
                    end = mid;
                    low = mid+1;
                }
            }
        }

        return {start, end};
    }
};