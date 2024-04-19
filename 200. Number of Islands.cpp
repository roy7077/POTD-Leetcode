// (DFS)
// Method - 1
// Time complexity - O(N*M)
// Space complexity- O(N+M) - Recursion stack space
class Solution {
    public:
    int x[4]={-1,0,+1,0};
    int y[4]={0,+1,0,-1};
    void dfs(vector<vector<char>>& grid,int i,int j)
    {
        int n=grid.size();
        int m=grid[0].size();
        for(int k=0;k<4;k++)
        {
            int r=i+x[k];
            int c=j+y[k];
            
            if(r>=0 and r<n and c>=0 and c<m and grid[r][c]=='1')
            {
                grid[r][c]='0';
                dfs(grid,r,c);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};


// Method - 2
// BFS
// Time complexity - O(N*M)
// Space complexity- O(N+M) - queue
class Solution {
    public:
    int x[4]={-1,0,+1,0};
    int y[4]={0,+1,0,-1};
    void bfs(vector<vector<char>>& grid,int i,int j)
    {       
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j]='0';
        
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            
            i=it.first;
            j=it.second;
            
            for(int k=0;k<4;k++)
            {
                int r=i+x[k];
                int c=j+y[k];

                if(r>=0 and r<n and c>=0 and c<m and grid[r][c]=='1')
                {
                    grid[r][c]='0';
                    q.push({r,c});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    bfs(grid,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};