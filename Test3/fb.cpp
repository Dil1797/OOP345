#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Post {
public:
    int postId;
    string content;
    int userId;
    string timestamp;
    int likes;
    vector<string> comments;
    vector<string> hashtags;

    // Constructor
    Post(int id, const string& content, int userId, const string& timestamp)
        : postId(id), content(content), userId(userId), timestamp(timestamp), likes(0) {}
};

class User {
public:
    int userId;
    vector<Post> posts;

    // Constructor
    User(int id) : userId(id) {}
};

class SocialMediaSystem {
public:
    vector<Post> posts;
    map<string, int> hashtagFrequency;

    void addPost(const Post& post) {
        posts.push_back(post);
        for (const string& hashtag : post.hashtags) {
            hashtagFrequency[hashtag]++;
        }
    }

    void likePost(int postId) {
        for (Post& post : posts) {
            if (post.postId == postId) {
                post.likes++;
                break;
            }
        }
    }

    void commentPost(int postId, const string& comment) {
        for (Post& post : posts) {
            if (post.postId == postId) {
                post.comments.push_back(comment);
                break;
            }
        }
    }

    vector<Post> getPostsByUser(int userId) {
        vector<Post> userPosts;
        for (const Post& post : posts) {
            if (post.userId == userId) {
                userPosts.push_back(post);
            }
        }
        return userPosts;
    }

    vector<pair<string, int>> getTrendingHashtags() {
        vector<pair<string, int>> sortedHashtags(hashtagFrequency.begin(), hashtagFrequency.end());
        sort(sortedHashtags.begin(), sortedHashtags.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second > b.second;
            });
        return sortedHashtags;
    }

    void sortPosts(vector<Post>& postsToSort, const string& sortBy) {
        if (sortBy == "timestamp") {
            sort(postsToSort.begin(), postsToSort.end(), [](const Post& a, const Post& b) {
                return a.timestamp < b.timestamp;
                });
        }
        else if (sortBy == "likes") {
            sort(postsToSort.begin(), postsToSort.end(), [](const Post& a, const Post& b) {
                return a.likes > b.likes;
                });
        }
        else if (sortBy == "comments") {
            sort(postsToSort.begin(), postsToSort.end(), [](const Post& a, const Post& b) {
                return a.comments.size() > b.comments.size();
                });
        }
    }
};

int main() {
    SocialMediaSystem system;

    // Add some posts
    system.addPost(Post(1, "Hello, world!", 1, "2023-11-22 12:00:00"));
    system.addPost(Post(2, "This is a longer post.", 2, "2023-11-23 10:30:00"));
    system.addPost(Post(3, "A post with a hashtag #trending", 3, "2023-11-24 15:15:00"));

    // Like a post
    system.likePost(1);

    // Comment on a post
    system.commentPost(2, "This is a comment.");

    // Get posts by a user
    vector<Post> userPosts = system.getPostsByUser(1);
    for (const Post& post : userPosts) {
        cout << "Post ID: " << post.postId << endl;
        cout << "Content: " << post.content << endl;
        cout << "Likes: " << post.likes << endl;
        cout << "Comments: " << endl;
        for (const string& comment : post.comments) {
            cout << "- " << comment << endl;
        }
        cout << endl;
    }

    // Get trending hashtags
    vector<pair<string, int>> trendingHashtags = system.getTrendingHashtags();
    cout << "Trending Hashtags:" << endl;
    for (const pair<string, int>& hashtag : trendingHashtags) {
        cout << hashtag.first << " (" << hashtag.second << ")" << endl;
    }

    return 0;
}
