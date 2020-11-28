class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        app.push(value);
    }
    
    int deleteHead() {
        if(!del.empty()) {
            int t = del.top();
            del.pop();
            return t;
        }
        while(!app.empty()) {
            del.push(app.top());
            app.pop();
        }
        if(del.empty()) return -1;
        int t = del.top();
        del.pop();
        return t;
    }

private:
    stack<int> del;
    stack<int> app;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */