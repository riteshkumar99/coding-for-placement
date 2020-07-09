class NumMatrix {
    int n, m;
    vector<vector<int> > v;
    bool isValid;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) {
            isValid = false;
            return;
        }
        isValid = true;
        n = matrix.size();
        m = matrix[0].size();
        v = matrix;
        for(int i = 0; i<n; i++) {
            for(int j = 1; j<m; j++) {
                v[i][j] += v[i][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(!isValid) {
            return 0;
        }
        int sum = 0;
        for(int i = row1; i<=row2; i++) {
            sum += v[i][col2] - ((col1 - 1 >= 0) ? v[i][col1-1] : 0);
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
