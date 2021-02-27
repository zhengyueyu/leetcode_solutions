class StockSpanner {
public:
    StockSpanner() {

    }
    
    int next(int price) {
        count++;

        if(stk.empty() || price < stk.back().first) {
            stk.emplace_back(price, count);
            return 1;
        }

        while(!stk.empty() && price >= stk.back().first) {
            stk.pop_back();
        }

        int tmp = 0;
        if(!stk.empty()) {
            tmp = stk.back().second;
        }
        stk.emplace_back(price, count);
        return stk.back().second - tmp;
    }

private:
    vector<pair<int, int>> stk;
    int count = 0;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */