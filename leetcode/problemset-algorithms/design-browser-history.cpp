class BrowserHistory {
public:
    vector<string> history;
    int currPos, maxPos;
    
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        currPos = maxPos = 0;
    }
    
    void visit(string url) {
        if(history.size() == (currPos + 1)) {
            history.push_back(url);
        } else {
            history[currPos+1] = url;
        }
        currPos++;
        maxPos = currPos;
    }
    
    string back(int steps) {
        currPos = max(0, currPos - steps);
        return history[currPos];
    }
    
    string forward(int steps) {
        currPos = min(maxPos, currPos + steps);
        return history[currPos];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
