// class Solution {
// public:
//     int smallestDivisor(vector<int>& nums, int threshold) {
//         int minn = INT_MAX;
//         for(int i=*max_element(nums.begin(),end(nums));i>0;--i){
//             int sum = 0;
//             for(int j=0;j<nums.size();++j){
//                 sum += ceil(nums[j]/(float)i);
//             }
//             if (sum<=threshold)
//                 minn = min(minn,i);
//         }
//         return minn;
//     }
// };

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int i=1, j=INT_MAX;
        while(i<j){
            int mid=i+(j-i)/2;
            int cnt=0;
            for(auto it: nums){
                cnt+=(it/mid)+(it%mid!=0);
            }
            //cout<<cnt<<endl;
            if(cnt>threshold){
                i=mid+1;
            }
            else{
                j=mid;
            }
        }
        return i;
    }
};