typedef pair<int,int> pi;

class Twitter {
    
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pi>> tweets;
    
    int timer;
    const int k = 10;

public:
    
    Twitter() {
        timer = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        
        // User's own tweets
        int n = tweets[userId].size();
        
        for(int i = n - 1; i >= max(0, n - k); i--) {
            
            pq.push(tweets[userId][i]);
            
            if(pq.size() > k)
                pq.pop();
        }
        
        // Followees' tweets
        for(int followee : following[userId]) {
            
            n = tweets[followee].size();
            
            for(int i = n - 1; i >= max(0, n - k); i--) {
                
                pq.push(tweets[followee][i]);
                
                if(pq.size() > k)
                    pq.pop();
            }
        }
        
        vector<int> feed;
        
        while(!pq.empty()) {
            feed.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(feed.begin(), feed.end());
        
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId, tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId, followeeId);
 * obj->unfollow(followerId, followeeId);
 */
