// Time complexity - O(N+M)
// Space complexity -O(N)
class Solution {
    public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum=0;
        for(auto& it:rolls)
        sum+=it;
        
        int x=(n+rolls.size())*mean - sum;
        int num=x/n;
        int temp=num;
        
        if(x%n)
        temp++;
        
        if(num<=0 or temp>6 or x<0)
        return {};
        
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            ans.push_back(num);
            x-=num;
        }
        
        num=x%n;
        for(int i=0;i<num;i++)
        ans[i]+=1;
        
        return ans;
    }
};
