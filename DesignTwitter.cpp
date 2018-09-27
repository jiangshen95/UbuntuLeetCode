#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Twitter {
private:
	vector<pair<int, int> > twitters;
	unordered_map<int, vector<int> > follows;
	
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        twitters.push_back(make_pair(userId, tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        for(int i = twitters.size() - 1; i >= 0; i--) {
        	if(twitters[i].first == userId) {
        		res.push_back(twitters[i].second);
			}else {
				if(follows.find(userId) != follows.end()) {
					vector<int> fusers = follows[userId];
					bool isfollow = false;
					for(int j = 0; j < fusers.size(); j++) {
						if(fusers[j] == twitters[i].first) {
							isfollow = true;
							break;
						}
					}
					if(isfollow) res.push_back(twitters[i].second);
				}
			}
			if(res.size() == 10) break;
		}
		
		return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(follows.find(followerId) == follows.end()) follows[followerId] = vector<int>();
        follows[followerId].push_back(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        for(int i = 0; i < follows[followerId].size(); i++) {
        	if(follows[followerId][i] == followeeId) {
        		follows[followerId].erase(follows[followerId].begin() + i);
        		i--;
			}
		}
    }
};

int main() {
	
	Twitter *twitter = new Twitter();
	twitter->postTweet(1, 5);
	vector<int> v = twitter->getNewsFeed(1);
	for(int i = 0; i < v.size(); i++) cout<<v[i]<<"  ";
	cout<<endl;
	twitter->follow(1, 2);
	twitter->postTweet(2, 6);
	v = twitter->getNewsFeed(1);
	for(int i = 0; i < v.size(); i++) cout<<v[i]<<"  ";
	cout<<endl;
	twitter->unfollow(1, 2);
	v = twitter->getNewsFeed(1);
	for(int i = 0; i < v.size(); i++) cout<<v[i]<<"  ";
	cout<<endl;
	
	return 0;
	
} 
