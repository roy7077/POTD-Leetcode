// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    int lengthOfLastWord(string s) {
        bool ch=0;
        int cnt=0;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(ch and s[i]==' ')
            return cnt;
            
            if(s[i]!=' ')
            {
                ch=1;
                cnt++;
            }
        }
        return cnt;
    }
};
