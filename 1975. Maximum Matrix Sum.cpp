// Time complexity - O(N*M)
// Space complexity- O(1)
#define ll long long
class Solution {
    public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        ll cntNeg=0;
        ll totalSum=0;
        int n=matrix.size();
        int m=matrix[0].size();
        ll minEle=1e18;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                totalSum+=abs(matrix[i][j]);
                if(matrix[i][j]<0)
                cntNeg++;
                
                minEle=min(minEle,abs((ll)matrix[i][j]));
            }
        }
       // -1 -2 -3
        if(cntNeg&1)
        totalSum-=(2*minEle);
        
        return totalSum;
    }
};
