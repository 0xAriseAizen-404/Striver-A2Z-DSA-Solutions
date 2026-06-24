// Optimal Solution 2
class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0;
        int lastSeen_A = -1;
        int lastSeen_B = -1;
        int lastSeen_C = -1;
        for (int ind = 0; ind < s.length(); ++ind) {
            if (s[ind] == 'a') lastSeen_A = ind;
            else if (s[ind] == 'b') lastSeen_B = ind;
            else lastSeen_C = ind;
            
            if (lastSeen_A != -1 && lastSeen_B != -1 && lastSeen_C != -1) {
                int min_lastSeenInd = min(lastSeen_A, min(lastSeen_B, lastSeen_C));
                cnt += (min_lastSeenInd - (-1));
                // min_lastSeenInd is nothing but left. (in below Optimal Solution 1)
            }
        }
        return cnt;
    }
};
// TC: O(N)
// SC: O(1)

// Optimal Solution 1
// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int left = 0;
//         int *abc = new int[3]();
//         int maxLen = 0;
//         int cnt = 0;
//         for (int right = 0; right < s.length(); ++right) {
//             ++abc[s[right]-'a'];
//             while (abc[0] && abc[1] && abc[2]) --abc[s[left++]-'a'];
//             cnt += left;
//         }
//         return cnt;
//     }
// };
// TC: O(N)
// SC: O(1)


// BruteForce Solution - 2: TLE
// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int cnt = 0;
//         for (int i=0; i<s.length(); ++i) {
//             int *abc = new int[3]();
//             for (int j=i; j<s.length(); ++j) {
//                 abc[s[j]-'a']++;
//                 if (abc[0] && abc[1] && abc[2]) {
//                     cnt += (s.length() - j);
//                     break;
//                     // bbacbacbca
//                     // 0123456789
//                     // we got a valid string at 3 index, bbac
//                     // Now from this point forward everything will be a valid string
//                     // bbacb, bbacba, bbacbac, ... everything will be valid, so we count how many more characters are there (len - ind). this many valid string we can form at Index i.
//                 }
//             }
//         }
//         return cnt;
//     }
// };
// TC: O(N^2)
// SC: O(1)

// BruteForce Solution: TLE
// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int cnt = 0;
//         for (int i=0; i<s.length(); ++i) {
//             int *abc = new int[3]();
//             for (int j=i; j<s.length(); ++j) {
//                 abc[s[j]-'a']++;
//                 if (abc[0] && abc[1] && abc[2]) cnt++;
//             }
//         }
//         return cnt;
//     }
// };
// TC: O(N^2)
// SC: O(1)

// This is a dummy .cpp file
class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0;
        int right = 0;
        int *abc = new int[3]();
        int maxLen = 0;
        int count = 0;
        while (right < s.length()) {
            abc[s[right] - 'a']++;
            while (abc[0] && abc[1] && abc[2]) {
                abc[s[left++] - 'a']--;
            }
            count += left;
            right++;
        }
        return count;
    }
};