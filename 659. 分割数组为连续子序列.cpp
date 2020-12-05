class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        for (const int& i : nums) {
            map<int, priority_queue<int, vector<int>, greater<int>>>::iterator it = mp.find(i - 1);
            if (mp.end() == it || mp[i - 1].empty()) {
                mp[i].push(1);
                continue;
            }
            int small = it->second.top();
            it->second.pop();
            mp[i].push(small + 1);
        }

        for (const auto& m : mp) {
            int top = 0;
            if(!m.second.empty())
                top = (m.second).top();
            if (top < 3 && top > 0)
                return false;
        }
        return true;
    }
};