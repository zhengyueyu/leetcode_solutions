class Solution {
public:
    int minArray(vector<int>& numbers) {
        if(numbers.empty()) return 0;
        if(numbers.size() == 1) return numbers[0];
        int l = 0;
        int r = numbers.size() - 1;
        int mid = l;
        while(numbers[l] >= numbers[r]) {
            if(r - l == 1) return numbers[r];
            mid = (l + r) / 2;

            //不像下面写l = mid是因为当numbers[mid] > numbers[r]条件成立时，最小值一定在右边
            if(numbers[mid] > numbers[r]) l = mid + 1;

            //不写r = mid - 1是防止[2,2,0,1]的情况，避免右边界出错的情况
            else if(numbers[mid] < numbers[r]) r = mid;
            else r--;
        }
        return numbers[l];
    }
};