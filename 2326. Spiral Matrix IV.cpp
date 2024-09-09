// Time complexity - O(N*M)
// Space complexity- O(N*M)
class Solution {
    public:
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        
        vector<vector<int>> ans(n,vector<int>(m,-1));
        
        int i1=0;
        int j1=0;
        int i2=n-1;
        int j2=m-1;
        
        while(i1<=i2 and j1<=j2 and head)
        {
            // left to right
            for(int j=j1;j<=j2 and head;j++)
            {
                ans[i1][j]=head->val;
                head=head->next;
            }
            
            i1++;
            
            // top to buttom
            for(int i=i1;i<=i2 and head;i++)
            {
                ans[i][j2]=head->val;
                head=head->next;
            }
            
            j2--;
            
            // right to left
            for(int j=j2;j>=j1 and head ;j--)
            {
                ans[i2][j]=head->val;
                head=head->next;
            }
            
            i2--;
            
            // buttom to top
            for(int i=i2;i>=i1 and head ;i--)
            {
                ans[i][j1]=head->val;
                head=head->next;
            }
            
            j1++;
        }
        return ans;
    }
};
