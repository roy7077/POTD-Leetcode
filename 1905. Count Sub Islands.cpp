typedef pair<int,int> pi;
class Solution {
    public:
    int x[4]={-1,0,+1,0};
    int y[4]={0,+1,0,-1};
    void bfs(vector<vector<int>>& grid,int i,int j,int& isLandNum)
    {
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pi> q;
        q.push({i,j});
        
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            for(int k=0;k<4;k++)
            {
                int newR=row+x[k];
                int newC=col+y[k];
                
                if(newR>=0 and newR<n and newC>=0 and newC<m and grid[newR][newC]==1){
                    grid[newR][newC]=isLandNum;
                    q.push({newR,newC});
                }
            }
        }
    }
    
    
    bool check(vector<vector<int>>& grid1,vector<vector<int>>& grid2,int i,int j,vector<vector<int>>& visited,int isLandNum){
        
        int n=grid1.size();
        int m=grid1[0].size();
        
        bool ans=1;
        visited[i][j]=1;
        queue<pi> q;
        q.push({i,j});
        
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            
            for(int k=0;k<4;k++)
            {
                int newR=r+x[k];
                int newC=c+y[k];
                
                if(newR>=0 and newR<n and newC>=0 and newC<m and grid2[newR][newC] and !visited[newR][newC])
                {
                    visited[newR][newC]=1;
                    q.push({newR,newC});
                    
                    if(grid1[newR][newC]!=isLandNum)
                    ans=0;
                }
            }
        }
        return ans;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size();
        int m=grid1[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        int isLandNum=2;
        int cntAns=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid2[i][j]==1 and !visited[i][j])
                {
                    if(grid1[i][j]==1)
                    {
                        bfs(grid1,i,j,isLandNum);
                        isLandNum++;
                    }
                    
                    if(grid1[i][j]==0)
                    check(grid1,grid2,i,j,visited,-1);
                    else
                    {
                        bool ans=check(grid1,grid2,i,j,visited,grid1[i][j]);
                        if(ans)
                        cntAns++;
                    }
                }
            }
        }
        return cntAns;
    }
};
