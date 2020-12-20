 class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size() != popped.size()) return false;
        if(popped.empty()) return true;
        stack<int> emul;
        int i = 0;
        for(const int& push : pushed) {
            emul.push(push);
            while(i < popped.size() && !emul.empty() && popped[i] == emul.top()) {
                i++;
                emul.pop();
            }
        }
        return emul.empty();
    }
};