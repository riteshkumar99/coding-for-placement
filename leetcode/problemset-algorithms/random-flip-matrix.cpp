class Solution {
public:
    int nrows, ncols;
    unordered_set<int> s;
    vector<vector<bool> > v;
    Solution(int n_rows, int n_cols) {
        nrows = n_rows;
        ncols = n_cols;
    }
    
    bool hashXY(int x, int y) {
        int hash;
        if(x >= y) {
            hash = x*x + x + y;
        } else {
            hash = y*y + x;
        }
        if(s.find(hash) != s.end()) {
            return true;
        }
        else {
            s.insert(hash);
            return false;
        }
    }
    
    vector<int> flip() {
        int x = rand() % nrows, y = rand() % ncols;
        while(hashXY(x, y)) {
            x = rand() % nrows, y = rand() % ncols;
        }
        return vector<int> {x, y};
    }
    
    void reset() {
        s.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
