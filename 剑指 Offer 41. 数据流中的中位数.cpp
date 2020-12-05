class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(minH.size() == maxH.size()) {
            maxH.push(num);
            minH.push(maxH.top());
            maxH.pop();    
        }
        else {
            minH.push(num);
            maxH.push(minH.top());
            minH.pop();
        }
    }
    
    double findMedian() {
        if(minH.size() == 0 && maxH.size() == 0) return 0;
        if(minH.size() > maxH.size()) return minH.top();
        if(minH.size() < maxH.size()) return maxH.top();
        return (maxH.top() + minH.top()) / 2.0f;
    }

private:
    priority_queue<int, vector<int>, less<int>> maxH;
    priority_queue<int, vector<int>, greater<int>> minH;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */