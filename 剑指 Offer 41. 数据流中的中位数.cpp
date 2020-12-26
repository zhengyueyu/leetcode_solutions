class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        //这里要注意 不可以只判断heap大小来判断元素应该装入哪个heap
        //因为装入某一个size小的堆后，如果发现这个num其实应该装入另外一个堆
        //就要进行弹出，这时两个堆size的差距又加1，就找不出中位数了
        if(maxheap.size() == minheap.size()) {
            maxheap.push(num);
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else {
            minheap.push(num);
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        if(minheap.empty()) return 0;
        if(maxheap.size() - minheap.size() == 0) {
            return (maxheap.top() + minheap.top()) / 2.0f;
        }
        else return minheap.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> minheap;
    priority_queue<int, vector<int>, less<int>> maxheap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */