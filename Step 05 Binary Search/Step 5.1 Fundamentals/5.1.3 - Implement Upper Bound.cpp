class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> arr, long long n, long long x){
        
        // Your code here
       int n = arr.size();
      int low = 0;
       int high = n - 1;
       int ceilEle = -1;
       while (low <= high) {
           int mid = low + (high - low) / 2;
           if (arr[mid] == x) return arr[mid];
           else if (arr[mid] < x) {
               low = mid + 1;
           } else {
               ceilEle = arr[mid];
               high = mid - 1;
               
           }
       }
       return ceilEle;
    }
};
