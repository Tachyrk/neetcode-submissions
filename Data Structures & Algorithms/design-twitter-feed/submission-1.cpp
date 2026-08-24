class Twitter {
public:
    struct PostList{
        PostList *next;
        int ID;
        int timestamp;
        PostList(){
            next = nullptr;
            ID = -1;
            timestamp = -1;
        }
        PostList(int val, int time){
            next = nullptr;
            ID = val;     
            timestamp = time;       
        }
        ~PostList(){
            delete next;
        }
    };
    struct ComparePost{
        bool operator()(const auto &a, const auto&b){
            return a->timestamp < b->timestamp;
        };
    };

    void addPost(PostList* head, PostList* post){
        post->next = head->next;
        head->next = post;
    }

    unordered_map<int, unordered_set<int>> mp;
    unordered_map<int, PostList*> user_posts;
    int global_time;

    Twitter() {        
        global_time = 0;
    }

    ~Twitter() {        
        for(auto [userID, head] : user_posts){
            delete head;
        }        
    }
    
    void postTweet(int userId, int tweetId) {
        PostList* newpost = new PostList(tweetId, global_time);
        if(user_posts.find(userId) != user_posts.end()){
            PostList* head = user_posts[userId];            
            addPost(head, newpost);
        }else{
            PostList* head = new PostList();            
            addPost(head, newpost);
            user_posts[userId] = head;
        }
        global_time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<PostList*, vector<PostList*>, ComparePost> pq;
        if(user_posts.find(userId) != user_posts.end() && user_posts[userId]->next){
            pq.push(user_posts[userId]->next);
        }
        for(int followeeID :  mp[userId]){
            if(user_posts.find(followeeID) != user_posts.end() && user_posts[followeeID]->next){
                pq.push(user_posts[followeeID]->next);
            }
        }

        vector<int> ans;
        int idx = 0;
        while(idx < 10 && !pq.empty()){
            PostList *post = pq.top();
            pq.pop();
            ans.push_back(post->ID);
            idx++;
            if(post->next){
                pq.push(post->next);
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
            mp[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if((mp.find(followerId) != mp.end()) && 
        (mp[followerId].find(followeeId) != mp[followerId].end())){
            mp[followerId].erase(followeeId);
        }
    }
};
