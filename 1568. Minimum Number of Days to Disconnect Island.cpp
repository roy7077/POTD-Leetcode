// Method - 1
// By disjoing set
class DisjointSet {
    public:
    vector<int> parent;
    vector<int> size;

    // constructor
    DisjointSet(int n) 
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    // find ultimate parent with path compression
    int fUp(int node) 
    {
        if (parent[node] == node)
            return node;

        // Path compression
        return parent[node] = fUp(parent[node]);
    }

    // Union by size
    void Union(int a, int b) 
    {
        int uP_a = fUp(a);
        int uP_b = fUp(b);

        if (uP_a == uP_b)
            return;

        if (size[uP_a] > size[uP_b]) {
            size[uP_a] += size[uP_b];
            parent[uP_b] = uP_a;
        } else {
            size[uP_b] += size[uP_a];
            parent[uP_a] = uP_b;
        }
    }
};



class Solution {
    public:
    
    int x[4]={-1,0,+1,0};
    int y[4]={0,+1,0,-1};
    
    static int countComponents(vector<vector<int>>& grid,DisjointSet& ds)
    {
        int n=grid.size();
        int m=grid[0].size();
        
        int cnt=0;
        for(int i=0;i<(n*m);i++)
        {
            if(grid[i/m][i%m] and ds.fUp(i)==i)
            cnt++;
        }
        return cnt;
    }
    
    int minDays(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        DisjointSet ds(n*m+2);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int node1=(i*m)+j;
                if(grid[i][j])
                {
                    for(int k=0;k<4;k++)
                    {
                        int r=i+x[k];
                        int c=j+y[k];
                        
                        if(r>=0 and r<n and c>=0 and c<m and grid[r][c])
                        {
                            int node2=(r*m)+c;
                            ds.Union(node1,node2);
                        }
                    }
                }
            }
        }
       
        int initialCount = countComponents(grid, ds);

        if (initialCount==0 or initialCount>=2)
            return 0;  

        // Check if removing one land cell makes it disconnected
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;  // Temporarily remove the land cell

                    DisjointSet new_ds(n * m);
                    for (int p = 0; p < n; p++) {
                        for (int q = 0; q < m; q++) {
                            if (grid[p][q] == 1) {
                                int node1 = p * m + q;
                                for (int k = 0; k < 4; k++) {
                                    int r = p + x[k];
                                    int c = q + y[k];

                                    if (r >= 0 and r < n and c >= 0 and c < m and grid[r][c]) {
                                        int node2 = r * m + c;
                                        new_ds.Union(node1, node2);
                                    }
                                }
                            }
                        }
                    }

                    int newCount = countComponents(grid, new_ds);
                    if (newCount > 1 or newCount==0) 
                    return 1;  

                    grid[i][j] = 1;  
                }
            }
        }

        // If removing one land cell doesn't work, return 2
        return 2;
    }
};


// 1 2 3 4
// 5 6 7 8
// 9 10 11 12



// [[1,1,0,1,1],
//  [1,1,1,1,1],
//  [1,1,0,1,1],
//  [1,1,0,1,1]]

 // [1,1,0,1,1],
 // [1,1,1,1,1],
 // [1,1,0,1,1],
 // [1,1,1,1,1]

// [1,1]
// [1,0]

 // [1,1,0,1,1],
 // [1,1,1,1,1],
 // [1,1,0,1,1],
 // [1,1,1,1,1]

// [[0,0,0],
//  [0,1,0],
//  [0,0,0]]


// Method - 2
// By dfs
class Solution {
    public:
    
    int x[4]={-1,0,+1,0};
    int y[4]={0,+1,0,-1};
    
    void helpDfs(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& visited)
    {
        visited[i][j]=1;
        int n=grid.size();
        int m=grid[0].size();
        for(int k=0;k<4;k++)
        {
            int r=i+x[k];
            int c=j+y[k];
            
            if(r>=0 and r<n and c>=0 and c<m and grid[r][c] and !visited[r][c])
            helpDfs(grid,r,c,visited);
        }
    }
    
    int help2(vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int disConnectedComp=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] and !visited[i][j])
                {
                    helpDfs(grid,i,j,visited);
                    disConnectedComp++;
                }
            }
        }
        return disConnectedComp;
    }
    
    int minDays(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int disConnectedComp=help2(grid);
        
        if(disConnectedComp==0 or disConnectedComp>=2)
        return 0;
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                {
                    grid[i][j]=0;
                    int disConnectedComp=help2(grid);
        
                    if(disConnectedComp==0 or disConnectedComp>=2)
                    return 1;
                    
                    grid[i][j]=1;
                }
            }
        }
        
        return 2;
    }
};
