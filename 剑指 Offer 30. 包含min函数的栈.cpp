class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        int nowmin;
        if(minstack.empty()) 
            nowmin = x;
        else {
            int lastmin = minstack.back().minx;
            nowmin = (lastmin > x) ? x : lastmin;
        }
        minstack.push_back(move(node(x, nowmin)));
    }
    
    void pop() {
        if(minstack.empty()) return;
        minstack.pop_back();
    }
    
    int top() {
        if(minstack.empty()) return 0;
        return minstack.rbegin()->x;
    }
    
    int min() {
        if(minstack.empty()) return 0;
        return minstack.rbegin()->minx;
    }

private:
    struct node{
        int x;
        int minx;
        node(int a, int b) : x(a), minx(b) {}
    };
    vector<node> minstack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */