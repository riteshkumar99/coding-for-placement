class DSU {
    vector<int> parent;
    public:
    DSU(int N) {
        parent = vector<int>(N);
        for(int i = 0; i<N; i++) {
            parent[i] = i;
        }
    }
    
    int Find(int x) {
        if(parent[x] != x) parent[x] = Find(parent[x]);
        return parent[x];
    }
    
    void Union(int x, int y) {
        parent[Find(x)] = Find(y);
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int N = stones.size();
        DSU dsu = DSU(20000);
        
        for(auto stone: stones) {
            dsu.Union(stone[0], stone[1] + 10000);
        }
        
        unordered_set<int> seen;
        for(auto stone: stones) {
            seen.insert(dsu.Find(stone[0]));
        }
        return N - seen.size();
    }
};
