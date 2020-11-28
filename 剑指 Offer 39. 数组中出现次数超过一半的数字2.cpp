class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        for(const int& i : nums) {
            hash[i]++;
            if(hash[i] > nums.size() / 2)
                return i;
        }
        return 0;
    }
};