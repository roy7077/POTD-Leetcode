// Time complexity - O(N*M*9)
// Space complexity- O(9)
class Solution {
    public:
    bool isValid(vector<vector<int>>& grid,int i,int j)
    {
        int n=grid.size();
        int m=grid[0].size();
        
        // all elements should be unique 
        // and between 1 to 9
        unordered_set<int> st;
        for(int k=i;k<=(i+2);k++)
        {
            for(int l=j;l<=(j+2);l++)
            {
                if(grid[k][l]<=0 or grid[k][l]>9 or st.count(grid[k][l])) 
                return 0;
                
                st.insert(grid[k][l]);
            }
        }
                
        // check for sum
        int sum=grid[i][j]+grid[i][j+1]+grid[i][j+2];
        
        // row sum
        for(int k=i+1;k<=(i+2);k++)
        {
            if(sum!=(grid[k][j]+grid[k][j+1]+grid[k][j+2]))
            return 0;
        }
        
        // col sum
        for(int k=j;k<=(j+2);k++)
        {
            if(sum!=(grid[i][k]+grid[i+1][k]+grid[i+2][k]))
            return 0;
        }
        
        // check for both diagonal
        int sum2=grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
        int sum3=grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j];
        
        if(sum2!=sum or sum3!=sum)
        return 0;
        
        return 1;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n-2;i++)
        {
            for(int j=0;j<m-2;j++)
            {
                if(isValid(grid,i,j))
                cnt++;
            }
        }
        return cnt;
    }
};

// 1 2 3 4 5 6
// 2
// 3
// 4

// 7 0 5
// 2 4 6
// 3 8 1
