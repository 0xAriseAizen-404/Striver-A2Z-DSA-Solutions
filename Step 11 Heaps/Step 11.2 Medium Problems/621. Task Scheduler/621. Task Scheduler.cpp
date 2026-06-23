class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int *hash = new int[26]();
        int maxFreq = 0;
        for (char &x: tasks) maxFreq = max(maxFreq, ++hash[x - 'A']);
        int noOf_maxFreqs = 0;
        for (int i=0; i<26; ++i) {
            if (hash[i] == maxFreq) noOf_maxFreqs++;
        }
        return max(((1+n)*(maxFreq - 1)+noOf_maxFreqs), (int)tasks.size());
    }
};