#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>

using namespace std;

class Twitter {
private:
	
	struct Tweet {
		int id;
		int time;
		Tweet *next;
		Tweet(int id, int time) : id(id), time(time), next(NULL) {}
	};

public:
	class User {
	public:
		int id;
		set<int> followed;
		Tweet *tweet_head;
		
		User(int id) {
			this->id = id;
			follow(id);
			tweet_head = NULL;
		}
		
		void follow(int id) {
			followed.insert(id);
		}
		
		void unfollow(int id) {
			followed.erase(id);
		}
		
		void post(int id, int time) {
			Tweet *t = new Tweet(id, time);
			t->next = tweet_head;
			tweet_head = t;
		}
	};
	
private:
	unordered_map<int, User*> usermap;
	
public:
	int timeStamp = 0;
    /** Initialize your data structure here. */
    Twitter() {
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if(usermap.find(userId) == usermap.end()) usermap[userId] = new User(userId);
        usermap[userId]->post(tweetId, timeStamp++);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
		if(usermap.find(userId) == usermap.end()) return res;
		
		set<int> users = usermap[userId]->followed;
		
		struct cmp {
			bool operator()(Tweet *left, Tweet *right) {
				if(left->id == right->id) return false;
				else return (left->time > right->time);
			}
		};
		
		set<Tweet*, cmp> tweets;
		for(int user : users) {
			Tweet *t = usermap[user]->tweet_head;
			if(t) {
				tweets.insert(t);
			}
		}
		
		while(!tweets.empty() && res.size() < 10) {
			Tweet *t = *tweets.begin();
			res.push_back(t->id);
			tweets.erase(t);
			if(t->next) {
				tweets.insert(t->next);
			}
		}
		
		return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(usermap.find(followerId) == usermap.end()) usermap[followerId] = new User(followerId);
        if(usermap.find(followeeId) == usermap.end()) usermap[followeeId] = new User(followeeId);
        usermap[followerId]->follow(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
    	if(usermap.find(followerId) == usermap.end() || followerId == followeeId) return;
        usermap[followerId]->unfollow(followeeId); 
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
