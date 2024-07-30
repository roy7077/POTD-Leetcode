class Solution {
    public:
    int minimumDeletions(string s) {
        int n=s.length();
        vector<int> a(n+1,0);
        vector<int> b(n+1,0);
        
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='a')
            {
                a[i]+=(a[i+1]+1);
                b[i]+=b[i+1];
            }
            else
            {
                b[i]+=(b[i+1]+1);
                a[i]+=a[i];
            }
        }
        
        int cntA=0;
        int cntB=0;
        int ans=1e9;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a')
            {
                int len=cntA+1+b[i];
                ans=min(n-len,ans);
                cntA++;
            }
            else
            {
                int len=cntA+b[i];
                ans=min(n-len,ans);
                cntB++;
            }
        }
        
        return ans>=1e9 ? 0 : ans;
    }
};
