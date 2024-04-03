// Time complexity - O((N*M)*(N*M)*4)
class Solution {
    public:
    int x[4]={-1,0,1,0};
    int y[4]={0,1,0,-1};
    bool help(vector<vector<char>>& board,int& i,int& j,string& word,int ind,vector<vector<int>>& visited)
    {
        //base case
        if(ind==word.length()-1)
        return 1;
            
        
        //recursive calls
        //and small calculation
        visited[i][j]=1;
        for(int k=0;k<4;k++)
        {
            int r=i+x[k];
            int c=j+y[k];
            
            if(r>=0 and r<board.size() and c>=0 and c<board[0].size() and board[r][c]==word[ind+1] and visited[r][c]==0)
            {
                bool ans=help(board,r,c,word,ind+1,visited);
                if(ans)
                return 1;
            }
        }
        visited[i][j]=0;
        return 0;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    bool ans=help(board,i,j,word,0,visited);
                    if(ans)
                    return 1;
                }
            }
        }
        return 0;
    }
};