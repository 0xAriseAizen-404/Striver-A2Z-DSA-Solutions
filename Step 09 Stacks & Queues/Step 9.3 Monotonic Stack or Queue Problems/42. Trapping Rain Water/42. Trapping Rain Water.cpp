class Solution {
public:
    int trap(vector<int>& height) {
        // we can store the NGE bar of the right for each bar
        // we can store the PGE bar of the left for each bar
        // we can use arrays and store the values with duplicated
        // or
        // we can just use stack and only store the indexes of NGE or PGE.
        // Because if we store only indexes no need of storing duplicated values

        int sz = height.size();
        stack<int> rightNGE;
        for (int i=sz-1; i>=0; --i) {
            int val = height[i];
            if (rightNGE.empty() || val > height[rightNGE.top()]) rightNGE.push(i); // '>' or '>=', No need to include duplicates, it works just fine.
            // here why we are not poping, because below code, we are popping the nge when that Index comes, but what about the later indexes, those indexes has the nges in these popped elements, so we should not pop these nges, we should keep them, so that when those relevant indexes arive, we can use these nges.
        }
        int contained_water = 0;
        int leftPGE = height[0];
        for (int ind=0; ind<sz; ++ind) {
            if (leftPGE < height[ind]) leftPGE = height[ind]; // '<' or '<='
            contained_water += min(leftPGE, height[rightNGE.top()]) - height[ind];
            if (ind == rightNGE.top()) rightNGE.pop();
        }
        return contained_water;
    }
};