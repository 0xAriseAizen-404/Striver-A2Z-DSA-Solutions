class Twitter {
private:
    int timestamp = 0;
    unordered_map<int, unordered_set<int>> follows; // user -> followees
    unordered_map<int, vector<pair<int, int>>> tweets; // user -> {timestamp, tweetId}
public:
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({++timestamp, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> newsFeed;
        priority_queue<vector<int>> pq; // {timestamp, tweetId, userId, index}
        // Include user's own Latest Tweet
        if (!tweets[userId].empty()) {
            int idx = tweets[userId].size() - 1;
            pq.push({tweets[userId][idx].first, tweets[userId][idx].second, userId, idx});
        }
        // Include user Follwee's Latest Tweet
        for (int followee: follows[userId]) {
            if (!tweets[followee].empty()) {
                int idx = tweets[followee].size() - 1;
                pq.push({tweets[followee][idx].first, tweets[followee][idx].second, followee, idx});
            }
        }
        while (!pq.empty() && newsFeed.size() < 10) {
            auto post = pq.top(); pq.pop();
            newsFeed.push_back(post[1]); // tweetId
            int idx = post[3];
            if (idx > 0) {
                // idx > 0, meaning there are still more posts left
                int author = post[2];
                pq.push({tweets[author][idx-1].first, tweets[author][idx-1].second, author, idx - 1});
            }
        }
        return newsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */