class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int sz = heights.size();
        stack<int> pse;
        int max_area = 0;
        for (int nse=0; nse<=sz; ++nse) {
            while (!pse.empty() && (nse==sz || heights[pse.top()] >= heights[nse])) {
                int curr_height = heights[pse.top()]; pse.pop();
                int width = nse - (pse.empty() ? -1 : pse.top()) - 1;
                max_area = max(max_area, curr_height * width);
            }
            pse.push(nse);
        }
        return max_area;
    }
};

// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int sz = heights.size();
//         vector<int> nse(sz, sz);
//         vector<int> pse(sz, -1);
        
//         stack<int> st;
//         for (int i=sz-1; i>=0; --i) {
//             while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
//             nse[i] = st.empty() ? sz : st.top();
//             st.push(i);
//         }
//         while (!st.empty()) st.pop();
//         for (int i=0; i<sz; ++i) {
//             while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
//             pse[i] = st.empty() ? -1 : st.top();
//             st.push(i);
//         }

//         int max_area = 0;
//         for (int i=0; i<sz; ++i) {
//             int height = heights[i];
//             int width = nse[i] - pse[i] - 1;
//             max_area = max(max_area, height * width);
//         }
//         return max_area;
//     }
// };