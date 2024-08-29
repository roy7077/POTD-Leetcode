// Method - 2
// DJS
class Disjoint_set{
    
    public:
    vector<int> par, size;
    Disjoint_set(int n){
        par.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 0; i <= n; i++)par[i] = i;
    }
    int findP(int u){
        if(u == par[u])return u;
        return par[u] = findP(par[u]);
    }
    void unionBySize(int u, int v){
        int upu = findP(u), upv = findP(v);
        if(upu == upv)return;
        if(size[upu] > size[upv]){
            par[upv] = upu;
            size[upu] += size[upv];
        }else{
            par[upu] = upv;
            size[upv] += size[upu];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = -1, maxCol = -1, n = stones.size();
        for(auto& it : stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        unordered_set<int> mpp;
        Disjoint_set ds(maxRow + maxCol + 2);
        for(auto& it : stones){
            int nodeRow = it[0], nodeCol = it[1] + maxRow + 1;
            ds.unionBySize(nodeRow, nodeCol);
            mpp.insert(nodeRow);
            mpp.insert(nodeCol);
        }
        int ct = 0;
        for(auto&it : mpp){
            if(ds.findP(it) == it)ct++;
        }
        return n - ct;
    }
};





// Method - 1
// DFS
class Solution {
    public:
    int dfs(unordered_map<int, vector<int>>& rows, unordered_map<int, vector<int>>& cols, unordered_map<int, int>& v_rows, int row) {
        int res = 0;
        res += rows[row].size();  // Add the number of columns in this row

        for (auto c : rows[row]) {  // For each column in this row
            for (auto r : cols[c]) {  // For each row in this column
                if (v_rows[r] == 0) {  // If this row hasn't been visited
                    v_rows[r] = 1;  // Mark this row as visited
                    res += dfs(rows, cols, v_rows, r);  // Recur on the connected row
                }
            }
        }
        
        return res;
    }

    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, vector<int>> rows, cols;
        unordered_map<int, int> v_rows;

        // Build adjacency list
        for (auto& stone : stones) {
            rows[stone[0]].push_back(stone[1]);
            cols[stone[1]].push_back(stone[0]);
            v_rows[stone[0]] = 0;  // Initialize all rows as unvisited
        }

        int ans = 0;

        // Start DFS from each unvisited row
        for (auto& stone : stones) {
            int row = stone[0];
            if (v_rows[row] == 0) {  // If the row hasn't been visited
                v_rows[row] = 1;  // Mark the row as visited
                ans += max(0,dfs(rows, cols, v_rows, row) - 1);  // Remove all but one stone in the connected component
            }
        }

        return ans;
    }
};


/*
//------First test case-------
1 1 0
1 0 1
0 1 1

row 0  cnt - 1 -> col 0  cnt=0 -> row 1 cnt = 1

row visited -> 0 , 1
vol visited -> 0 , 
//-------Second test case-----
1 0 1
0 1 0
1 1 1
    
//------Third test case---------
1 1 1 
1 1 1
1 1 1

// fourth test case
0 1
0 1

// Time complexity
N*M*(N+M)
1e6*(2000)
*/
