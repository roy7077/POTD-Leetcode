/*-------------Method 1---------------------------*/
// Time complexity - O(N*M)
// Space complexity- O(2*N + 2*M)
class Solution {
    public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<pair<int,int>> col(m,pair<int,int>({0,0}));
        vector<pair<int,int>> row(n,pair<int,int>({0,0}));
        vector<vector<int>> ans(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                {
                    col[j].second++;
                    row[i].second++;
                }
                else
                {
                    col[j].first++;
                    row[i].first++;
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int temp=(col[j].second+row[i].second)-(col[j].first+row[i].first);
                ans[i][j]=temp;
            }
        }
        return ans;
    }
};




/*1---------------------------Method 2--------------------*/
// Time complexity - O(N*M)
// Space complexity- O(M+N)
#define ll long long
class Solution {
    public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        ll maxi=1e5+1;
        
        vector<ll> col(m,0);
        vector<ll> row(n,0);
        vector<vector<int>> ans(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                {
                    //col
                    int one1=col[j]%maxi;
                    int zero1=col[j]/maxi;
                    
                    one1++;
                    col[j]=(maxi*zero1)+one1;
                    
                    
                    //row
                    int one2=row[i]%maxi;
                    int zero2=row[i]/maxi;
                    
                    one2++;
                    row[i]=(maxi*zero2)+one2;
                }
                else
                {
                    //col
                    int one1=col[j]%maxi;
                    int zero1=col[j]/maxi;
                    
                    zero1++;
                    col[j]=(maxi*zero1)+one1;
                    
                    
                    //row
                    int one2=row[i]%maxi;
                    int zero2=row[i]/maxi;
                    
                    zero2++;
                    row[i]=(maxi*zero2)+one2;
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int one1=col[j]%maxi;
                int zero1=col[j]/maxi;
                int one2=row[i]%maxi;
                int zero2=row[i]/maxi;
                
                int temp=(one1+one2)-(zero1+zero2);
                ans[i][j]=temp;
            }
        }
        return ans;
    }
};