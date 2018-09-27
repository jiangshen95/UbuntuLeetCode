class Twitter:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.followed = {}
        self.tweet = []

    def postTweet(self, userId, tweetId):
        """
        Compose a new tweet.
        :type userId: int
        :type tweetId: int
        :rtype: void
        """
        if userId not in self.followed:
            self.followed[userId] = [userId]
        self.tweet.append((userId, tweetId))

    def getNewsFeed(self, userId):
        """
        Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
        :type userId: int
        :rtype: List[int]
        """
        res = []
        if userId not in self.followed:
            return res
        users = self.followed[userId]
        for t in reversed(self.tweet):
            if t[0] in users:
                res.append(t[1])
            if len(res) == 10:
                break
        return res

    def follow(self, followerId, followeeId):
        """
        Follower follows a followee. If the operation is invalid, it should be a no-op.
        :type followerId: int
        :type followeeId: int
        :rtype: void
        """
        if followerId not in self.followed:
            self.followed[followerId] = [followerId]
        self.followed[followerId].append(followeeId)

    def unfollow(self, followerId, followeeId):
        """
        Follower unfollows a followee. If the operation is invalid, it should be a no-op.
        :type followerId: int
        :type followeeId: int
        :rtype: void
        """
        if followerId not in self.followed or followeeId == followerId:
            return
        if followeeId in self.followed[followerId]:
            self.followed[followerId].remove(followeeId)


if __name__ == '__main__':
    tweeter = Twitter()
    tweeter.postTweet(1, 5)
    print(tweeter.getNewsFeed(1))
    tweeter.follow(1, 2)
    tweeter.postTweet(2, 6)
    print(tweeter.getNewsFeed(1))
    tweeter.unfollow(1, 2)
    print(tweeter.getNewsFeed(1))
