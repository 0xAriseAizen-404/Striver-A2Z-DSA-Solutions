// Better Solution with Unordered_Map + Min_Heap
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int sz = hand.size();
        if (sz%groupSize != 0) return false;
        unordered_map<int, int> umap;
        for (int &x: hand) ++umap[x];
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto &[x, c]: umap) pq.push(x);
        while (!pq.empty()) {
            int card = pq.top();
            int freq = umap[card];
            for (int i=0; i<groupSize; ++i) {
                if (umap[card + i] < freq) return false;
                umap[card + i] -= freq;
            }
            while (!pq.empty() && umap[pq.top()] == 0) pq.pop();
        }
        return true;
    }
};
// TC: O(n + m log m) ≈ O(n log n) worst case
// SC: O(m) ≈ O(n) worst case


// Better Solution with Ordered_Map
// class Solution {
// public:
//     bool isNStraightHand(vector<int>& hand, int groupSize) {
//         map<int, int> mp;
//         for (int &x: hand) mp[x]++;
//         while (!mp.empty()) {
//             int start = mp.begin()->first;
//             int cnt = mp.begin()->second;
//             for (int i = 0; i < groupSize; i++) {
//                 auto it = mp.find(start + i);
//                 if (it == mp.end() || it->second < cnt)
//                     return false;
//                 it->second -= cnt;
//                 if (it->second == 0)
//                     mp.erase(it);
//             }
//         }
//         return true;
//     }
// };
// TC = O(n log n)
// SC = O(n)

// My Own Solution
// class Solution {
// public:
//     bool isNStraightHand(vector<int>& hand, int groupSize) {
//         if (hand.size()%groupSize != 0) return false;
//         unordered_map<int, int> umap;
//         for (int &x: hand) umap[x]++;
//         priority_queue<int, vector<int>, greater<int>> pq;
//         for (auto &pair: umap) pq.push(pair.first);
        
//         int prevCard = -1;
//         int cnt = 0;
//         vector<int> temp;
//         while (!pq.empty()) {
//             if (prevCard == -1 || prevCard+1 == pq.top()) {
//                 int X = pq.top();
//                 prevCard = X;
//                 cnt++;
//                 pq.pop();
//                 umap[X] -= 1;
//                 if (umap[X] > 0) temp.push_back(X);
//                 if (umap[X] == 0) umap.erase(X);
//             } else {
//                 return false;
//             }
//             if (cnt == groupSize) {
//                 cnt = 0;
//                 prevCard = -1;
//                 for (int &x: temp) pq.push(x);
//                 temp.clear();
//             }
//         }
//         return (temp.size() == 0) && (umap.size() == 0);
//     }
// };
// TC: O(N) + O(M log M) + O(N log M) => O(N log M)   (Worst case O(N log N))
// M = no. of Distinct Values
// SC: O(M)         (Worst case O(N))
