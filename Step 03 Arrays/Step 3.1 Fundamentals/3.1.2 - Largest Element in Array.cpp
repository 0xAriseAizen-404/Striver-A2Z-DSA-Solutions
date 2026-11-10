//User function Template for C++

class Solution
{
public:
    int largest(vector<int> &arr, int n)
    {
        int maxx = INT_MIN;
        for (auto x: arr)
            maxx = max(maxx, x);
        return maxx;
    }
};