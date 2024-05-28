class Solution {
    public:
    int equalSubstring(string s, string t, int maxCost) {
        int i=0;
        int j=0;
        int maxLen=0;
        int cnt=0;
        while(j<s.length())
        {
            cnt+=abs(s[j]-t[j]);
            
            while(cnt>maxCost and i<s.length())
            {
                int req=abs(s[i]-t[i]);
                cnt-=req;
                
                i++;
            }
            maxLen=max(maxLen,j-i+1);
            j++;
        }
        return maxLen; 
    }
};