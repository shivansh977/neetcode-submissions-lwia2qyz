class Twitter {
private:
    map<int,set<int>> follower;
    map<int,set<pair<int,int>>> posts;
    int t;
    void putTweets(set<pair<int,int>>& tweets, int userId){
        int count=0;
        for(auto it=posts[userId].begin();it!=posts[userId].end()&&count<10;it++){
            tweets.insert(*it);
            count++;
        }
    }
public:
    Twitter() {
        t=0;
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].insert({t--,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        set<pair<int,int>> tweets;
        vector<int> fa;
        putTweets(tweets,userId);
        for(int user: follower[userId]){
            putTweets(tweets,user);
        }
        int count=0;
        for(auto it=tweets.begin();it!=tweets.end()&&count<10;it++){
            fa.push_back((*it).second);
            count++;
        }
        return fa;
    }
    
    void follow(int followerId, int followeeId) {
        follower[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follower[followerId].erase(followeeId);
    }
};
