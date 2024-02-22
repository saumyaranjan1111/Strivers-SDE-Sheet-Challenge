class RecentCounter {
public:
    int count;
    queue<int> q;
    RecentCounter() {
        count = 0;
    }
    
    int ping(int t) {
        q.push(t);
        while(q.front() < t-3000) q.pop();
        count = q.size();
        return count;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */