class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minh;
    priority_queue<int> maxh;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxh.push(num);
        if(minh.empty() or minh.size() + 1 < maxh.size()) {
            minh.push(maxh.top());
            maxh.pop();
        } else if(minh.top() < maxh.top()) {
            maxh.push(minh.top());
            minh.pop();
            minh.push(maxh.top());
            maxh.pop();
        }
    }
    
    double findMedian() {
        if(maxh.size() > minh.size()) {
            return maxh.top();
        }
        return ((double)minh.top() + maxh.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */