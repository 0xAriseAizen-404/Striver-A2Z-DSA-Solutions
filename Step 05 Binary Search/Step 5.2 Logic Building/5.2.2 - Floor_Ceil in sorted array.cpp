// User code template

class Solution {
  public:
  
  int getFloor(vector<int> &arr, int x) {
      int n = arr.size();
      int low = 0;
       int high = n - 1;
       int floorEle = -1;
       while (low <= high) {
           int mid = low + (high - low) / 2;
           if (arr[mid] == x) return arr[mid];
           else if (arr[mid] < x) {
               floorEle = arr[mid];
               low = mid + 1;
           } else high = mid - 1;
       }
       return floorEle;
  }
  
  int getCeil(vector<int> &arr, int x) {
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
  
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        vector<int> p(2);
        p[0] = getFloor(arr, x);
        p[1] = getCeil(arr, x);
        return p;
    }
};