typedef pair<int,int> pi;
class Solution {
    public:
    int x[4]={-1,0,+1,0};
    int y[4]={0,+1,0,-1};
    
    bool help(vector<vector<int>>& nearThief,int& val)
    {
        int n=nearThief.size();
        queue<pi> q;
        vector<vector<int>> visited(n,vector<int>(n,0));
        
        if(nearThief[0][0]>=val)
        q.push({0,0});
        
        visited[0][0]=1;
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            
            int i=it.first;
            int j=it.second;
            
            if(i==n-1 and j==n-1)
            return 1;
            
            for(int k=0;k<4;k++)
            {
                int delr=i+x[k];
                int delc=j+y[k];
                
                if(delr>=0 and delr<n and delc>=0 and delc<n and !visited[delr][delc] and nearThief[delr][delc]>=val)
                {
                    visited[delr][delc]=1;
                    q.push({delr,delc});
                }
            }
        }
        return 0;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        
        //pre calculation of nearest thief
        int n=grid.size();
        int m=grid[0].size();
    
        vector<vector<int>> nearThief(n,vector<int>(m,-1));
        queue<pi> q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                {
                    q.push({i,j});
                    nearThief[i][j]=0;
                }
            }
        }
        
        int cnt=1;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                auto it=q.front();
                q.pop();
                
                int i=it.first;
                int j=it.second;
    
                for(int k=0;k<4;k++)
                {
                    int delrow=i+x[k];
                    int delcol=j+y[k];
                    
                    if(delrow>=0 and delrow<n and delcol>=0 and delcol<m and nearThief[delrow][delcol]==-1)
                    {
                        nearThief[delrow][delcol]=cnt;
                        q.push({delrow,delcol});
                    }
                }
            }
            cnt++;
        }
       
        //Binary Search
        int l=0;
        int r=400;
        int ans=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(help(nearThief,mid))
            {
                ans=mid;
                l=mid+1;
            }
            else
            r=mid-1;
        }
        return ans;
    }
};