class SubrectangleQueries {
    vector<vector<int> > rect;
    vector<pair<array<int, 4>, int> > v;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        rect = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        v.push_back({array<int, 4>{row1, row2, col1, col2}, newValue});
    }
    
    int getValue(int row, int col) {
        for(int i = v.size()-1; i>=0; i--) {
            array<int, 4> coor = v[i].first;
            if(coor[0] <= row && row <= coor[1] && coor[2] <= col && col <= coor[3]) {
                return v[i].second;
            }
        }
        return rect[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
