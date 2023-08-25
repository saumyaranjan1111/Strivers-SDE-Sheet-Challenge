class MedianFinder {
    priority_queue<int> first, second;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int k1 = first.size();
        int k2 = second.size();

        first.push(num);
        second.push(-first.top());
        first.pop();

        if(first.size() < second.size()){
            first.push(-second.top());
            second.pop();
        }
        
    }
    
    double findMedian() {
        int k1 = first.size();
        int k2 = second.size();

        if(k1 == k2) return (first.top() - second.top())/2.0;
        else if(k1 > k2) return first.top();
        else return -second.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */