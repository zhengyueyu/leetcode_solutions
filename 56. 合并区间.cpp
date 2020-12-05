class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0 || intervals.size() == 1)
            return intervals;
        quicksort(intervals, 0, intervals.size() - 1);
        vector<vector<int>> res;
        int l = intervals[0][0];
        int r = intervals[0][1];
        int tap = intervals[0][1];
        for(const auto& i : intervals) {
            if(i[0] <= tap) {
                tap = tap > i[1] ? tap : i[1];
                r = r > i[1] ? r : i[1];
            }
            else if(i[0] > tap) {
                res.push_back({ l, r });
                l = i[0];
                r = i[1];
                tap = r;
            }
        }
        if(res.empty() || res.back()[0] != l) 
            res.push_back({ l, r });
        return res;
    }

    void quicksort(vector<vector<int>>& intervals, int left, int right) {
        if(left < right) {
            int pivot = partition(intervals, left, right);
            quicksort(intervals, left, pivot - 1);
            quicksort(intervals, pivot + 1, right);
        }
    }

    int partition(vector<vector<int>>& intervals, int i, int j) {
        vector<int> pivot = intervals[i];
        while(i < j) {
            while(i < j && intervals[j][0] >= pivot[0]) j--;
            intervals[i] = std::move(intervals[j]);
            while(i < j && intervals[i][0] <= pivot[0]) i++;
            intervals[j] = std::move(intervals[i]);
        }
        intervals[i] = pivot;
        return i;
    }
};