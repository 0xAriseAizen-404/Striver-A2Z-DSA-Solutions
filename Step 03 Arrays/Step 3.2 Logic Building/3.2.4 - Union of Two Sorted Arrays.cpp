class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        vector < int > res;

        int i = 0, j = 0;

        while (i < n && j < m) {
            if (arr1[i] <= arr2[j]) {
                res.push_back(arr1[i]);
                i++;
                while (i < n && arr1[i] == arr1[i - 1]) {
                    i++;
                }
                while (j < m && arr2[j] == arr1[i - 1]) {
                    j++;
                }
            } else {
                res.push_back(arr2[j]);
                j++;
                while (j < m && arr2[j] == arr2[j - 1]) {
                    j++;
                }
                while (i < n && arr1[i] == arr2[j - 1]) {
                    i++;
                }
            }
        }

        while (i < n) {
            res.push_back(arr1[i]);
            i++;
            while (i < n && arr1[i] == arr1[i - 1]) i++;
        }

        while (j < m) {
            res.push_back(arr2[j]);
            j++;
            while (j < m && arr2[j] == arr2[j - 1]) j++;
        }

        return res;
    }
};