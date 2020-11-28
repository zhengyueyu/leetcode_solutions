class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size() != popped.size()) return false;
        int i = 0;
        int j = 0;
        for(const int& push : pushed) {
            pushed[i] = push;
            while(i >= 0 && pushed[i] == popped[j]) {
                i--; j++;
            }
            i++;
        }
        return i == 0;
    }
};