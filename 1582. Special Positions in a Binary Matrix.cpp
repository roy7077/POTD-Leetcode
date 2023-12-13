// Time complexity - O(N*M)
// Space complexity- O(N+M)
class Solution {
    public:
    int numSpecial(vector<vector<int>>& mat) {
    
        int n=mat.size();
        int m=mat[0].size();
        vector<int> col(m,0);
        vector<int> row(n,0);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j])
                {
                    col[j]++;
                    row[i]++;
                }
            }
        }
        
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j] and col[j]==1 and row[i]==1)
                cnt++;
            }
        }
        return cnt;
    }
};