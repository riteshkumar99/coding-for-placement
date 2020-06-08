class StockSpanner {
public:
    stack<pair<int, int> > stock;
    pair<int, int> p;
    StockSpanner() {
        while(!stock.empty()) {
            stock.pop();
        }
    }
    
    int next(int price) {
        if(stock.empty()) {
            stock.push(make_pair(price, 1));
        } else {
            int count = 1;
            while(!stock.empty()) {
                p = stock.top();
                if(p.first > price) {
                    break;
                } else {
                    count += p.second;
                    stock.pop();
                }
            }
            stock.push(make_pair(price, count));
        }
        return stock.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
