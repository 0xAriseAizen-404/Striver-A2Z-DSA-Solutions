class StockSpanner {
public:
    int ind = 0;
    stack<pair<int, int>> data;

    StockSpanner() {
    }
    
    int next(int price) {
        while (!data.empty() && data.top().second <= price) data.pop();
        // int span = data.empty() ? ind + 1 : ind - data.top().first;
        int span = ind - (data.empty() ? -1 : data.top().first);
        data.push({ind++, price});
        return span;
    }
};


/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */