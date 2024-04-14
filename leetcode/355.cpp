#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

class Twitter {
  public:
    int time = 0;
    unordered_map<int, pair<int, int>> umap; // 时间和 userId, tweetId 的映射
    vector<deque<int>> user_twitter;
    vector<deque<int>> user_display;
    vector<unordered_set<int>> user_display_set;
    vector<unordered_set<int>> user_follow;   // follow 的人
    vector<unordered_set<int>> user_followed; // 被哪些人 follow

    Twitter()
        : user_twitter(501), user_display(501), user_display_set(501),
          user_follow(501), user_followed(501) {}

    void postTweet(int userId, int tweetId) {
        // 1. 创建映射
        // 2. 给 自己 添加
        // 3. 给 自己和 follow 自己的人发显示
        int t = time++;
        umap[t] = {userId, tweetId};
        user_twitter[userId].push_back(t);
        user_display[userId].push_front(t);
        for (auto &u : user_followed[userId]) {
            user_display[u].push_front(t);
        }
    }

    vector<int> getNewsFeed(int userId) {

        int i = 10;
        vector<int> res;
        for (auto &t : user_display[userId]) {
            // 不是自己的且没关注的不要
            if (umap[t].first != userId &&
                user_follow[userId].find(umap[t].first) ==
                    user_follow[userId].end()) {
                continue;
            }

            res.push_back(umap[t].second);

            if (--i == 0) {
                break;
            }
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        user_follow[followerId].insert(followeeId);
        user_followed[followeeId].insert(followerId);

        for (auto t : user_twitter[followeeId]) {
            if (user_display_set[followerId].find(t) ==
                user_display_set[followerId].end()) {
                user_display_set[followerId].insert(t);
                user_display[followerId].push_back(t);
            }
        }
        sort(user_display[followerId].begin(), user_display[followerId].end(),
             std::greater<int>());
    }

    void unfollow(int followerId, int followeeId) {
        // 打标签，不真删除
        user_follow[followerId].erase(followeeId);
        user_followed[followeeId].erase(followerId);
    }
};

int main(void) {

    Twitter twitter;
    twitter.postTweet(1, 5);
    printVector(twitter.getNewsFeed(1)); // 5
    twitter.follow(1, 2);
    twitter.postTweet(2, 6);             // 时间近的在前面
    printVector(twitter.getNewsFeed(1)); // 6, 5

    twitter.unfollow(1, 2);
    printVector(twitter.getNewsFeed(1)); // 5
    return 0;
}
