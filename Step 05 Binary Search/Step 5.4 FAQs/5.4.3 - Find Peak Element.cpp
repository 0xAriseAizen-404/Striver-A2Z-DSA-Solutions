class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0,h=nums.size();
        if(nums.size()==1)return 0;
        while(l<=h){
            int mid=(l+h)/2;
            if((mid==0 && nums[mid]>nums[mid+1]) || (mid==(nums.size()-1) && nums[mid]>nums[mid-1]) || ((mid>0 && mid<nums.size()-1) && nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])){
                return mid;
            }
            else if(mid<nums.size()-1 && (nums[mid]<nums[mid+1]))
                l=mid+1;
            else
                h=mid-1;
        }
        return -1;
    }
};