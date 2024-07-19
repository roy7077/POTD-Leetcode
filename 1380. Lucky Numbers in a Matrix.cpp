// Time complexity - O(N*M)
// Space complexity- O(N+M)
class Solution {
    public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        // for rows
        vector<int> row(n);
        for(int i=0;i<n;i++)
        {
            int mini=matrix[i][0];
            for(int j=1;j<m;j++)
            mini=min(mini,matrix[i][j]);
            
            row[i]=mini;
        }
        
        
        // for col
        vector<int> col(m);
        for(int j=0;j<m;j++)
        {
            int maxi=matrix[0][j];
            for(int i=0;i<n;i++)
            maxi=max(maxi,matrix[i][j]);
            
            col[j]=maxi;
        }
        
        //ans
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==col[j] and matrix[i][j]==row[i])
                ans.push_back(matrix[i][j]);
            }
        }
        
        return ans;
    }
};
