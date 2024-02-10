// Time complexity - O(N^2)
// Space complexity- O(1)
class Solution {
    public:
    int countPalindrome(string& s,int i,int j)
    {
        int cnt=0;
        while(i>=0 and j<s.length())
        {
            if(s[i]==s[j])
            {
                cnt++;
                i--;
                j++;
            }
            else
            break;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            int a=countPalindrome(s,i,i);
            int b=countPalindrome(s,i,i+1);
            ans+=(a+b);
        }
        return ans;
    }
};