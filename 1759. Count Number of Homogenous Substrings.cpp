// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    int mod=1e9+7;
    int countHomogenous(string s) {
        
        int cnt=1;
        char pre=s[0];
        int ans=1;
        for(int i=1;i<s.length();i++)
        {
            if(s[i]==pre)
            cnt++;
            else
            cnt=1;
            
            pre=s[i];
            ans=(ans+cnt)%mod;
        }
        return ans;
    }
};
