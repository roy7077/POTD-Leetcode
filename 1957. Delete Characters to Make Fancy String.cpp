// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    string makeFancyString(string s) {
        string ans="";
        ans+=s[0];
        int cnt=1;
        for(int i=1;i<s.length();i++)
        {
            if(s[i-1]==s[i])
            cnt++;
            else
            cnt=1;
            
            if(cnt<=2)
            ans+=s[i];
        }
        
       return ans;
    }
};
// leeeetcode
