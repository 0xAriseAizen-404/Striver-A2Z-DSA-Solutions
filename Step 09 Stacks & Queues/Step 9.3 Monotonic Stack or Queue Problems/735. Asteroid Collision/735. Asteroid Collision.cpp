class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int sz = asteroids.size();
        vector<int> ans;
        stack<int> st;
        for (int &ast: asteroids) {
            if (ast > 0) st.push(ast);
            else {
                bool isDestroyed = false;
                while (!st.empty()) {
                    if (st.top() < abs(ast)) st.pop();
                    else if (st.top() == abs(ast)) {
                        st.pop();
                        isDestroyed = true;
                        break;
                    } else {
                        isDestroyed = true;
                        break;
                    }
                }
                if (!isDestroyed) ans.push_back(ast); // negative one
            }
        }
        sz = ans.size();
        ans.resize(ans.size() + st.size());
        for (int i=st.size()-1; i>=0; --i) { // all the survived positive ones
            ans[sz + i] = st.top();
            st.pop();
        }
        return ans;
    }
};

// This is Wrong
// class Solution {
// public:
//     vector<int> asteroidCollision(vector<int>& asteroids) {
//         int sz = asteroids.size();
//         stack<int> st;
//         for (int i=0; i<sz; ++i) {
//             while (!st.empty() && (st.top()>0 && asteroids[i]<0)) {
//                 if (abs(st.top()) < abs(asteroids[i])) st.pop();
//                 else continue;
//              }
//             st.push(asteroids[i]);
//         }
//         vector<int> ans(st.size(), 0);
//         for (int i=st.size()-1; i>=0; --i) {
//             ans[i] = st.top();
//             st.pop();
//         }
//         return ans;
//     }
// };