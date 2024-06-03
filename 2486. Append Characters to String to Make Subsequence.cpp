class Solution {
    public:
    int appendCharacters(string s, string t) {
        int n=s.length();
        int m=t.length();
        
        int i=0;
        int j=0;
        int cnt=0;
        int maxLen=0;
        while(i<n and j<m)
        {
            if(s[i]==t[j])
            {
                cnt++;
                i++;
                j++;
            }
            else
            i++;
            
            maxLen=max(maxLen,cnt);
        }
        maxLen=max(maxLen,cnt);
        return (m-maxLen);
    }
};
