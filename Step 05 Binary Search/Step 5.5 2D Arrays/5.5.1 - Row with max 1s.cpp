// User function template for C++
class Solution {
  public:
     //optimal approach tc->o(arr.size() * log(2,(arr[i].size())) sc->o(1)

int first_occurence_index(vector<int>&arr,int n,int x){
        int low=0;int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]>=x){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }

 int rowWithMax1s(vector<vector<int>> arr) {

int cnt_max=0;int row=-1;
for(int i=0;i<arr.size();i++){
    int cnt_ones=arr[i].size()-first_occurence_index(arr[i],arr[i].size(),1);
    if(cnt_ones>cnt_max){
        cnt_max=cnt_ones;
        row=i;
    }
    }
   return row; 
 }
};


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    Returns the index of the row
    with the maximum number of 1s.
    */
    int rowWithMax1s(vector<vector<int>>& mat) {
        // Store the best count of 1s found so far.
        int maxCount = 0;

        // Store the row index that gives the current best answer.
        int answer = -1;

        for (int i = 0; i < (int)mat.size(); i++) {
            // Count the number of 1s in the current row.
            int count = 0;

            for (int j = 0; j < (int)mat[i].size(); j++) {
                if (mat[i][j] == 1) {
                    count++;
                }
            }

            // Update the answer because this row has more 1s.
            if (count > maxCount) {
                maxCount = count;
                answer = i;
            }
        }

        return answer;
    }
};

// Driver code starts
int main() {
    vector<vector<int>> mat = {
        {0, 0, 1, 1},
        {0, 1, 1, 1},
        {0, 0, 0, 1}
    };

    Solution obj;
    cout << obj.rowWithMax1s(mat) << endl;

    return 0;
}