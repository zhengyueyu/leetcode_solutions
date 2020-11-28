#include "leetcode.h"
class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(qu.empty()) return -1;
        return dq.front();
    }
    
    void push_back(int value) {
        while(!dq.empty() && dq.back() < value) dq.pop_back();
        dq.push_back(value);
        qu.push_back(value);
    }
    
    int pop_front() {
        if(qu.empty()) return -1;
        int t = qu.front();
        if(t == dq.front()) dq.pop_front();
        qu.pop_front();
        return t;
    }

private:
    deque<int> qu;
    deque<int> dq;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */