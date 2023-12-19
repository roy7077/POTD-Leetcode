// Time complexity - O(N*M*9)
// Space complexity- O(N*M)
class Solution {
    public:
    int x[9]={0,0,-1,-1,-1,0,+1,+1,+1};
    int y[9]={0,-1,-1,0,+1,+1,+1,0,-1};
    int help(vector<vector<int>>& img,int& i,int& j)
    {
        int n=img.size();
        int m=img[0].size();
        int sum=0;
        int cnt=0;
        for(int k=0;k<9;k++)
        {
            int row=i+x[k];
            int col=j+y[k];
            
            if(row>=0 and row<n and col>=0 and col<m)
            sum+=img[row][col],cnt++;
        }
        return sum/cnt;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size();
        int m=img[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            ans[i][j]=help(img,i,j);
        }
        return ans;
    }
};