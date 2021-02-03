class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.empty()) return -1;
        priority_queue<int> pq;
        for(const int& n : nums) {
            pq.push(n);
        }

        int res = -1;
        while(k--) {
            res = pq.top();
            pq.pop();
        }
        return res;
    }


};