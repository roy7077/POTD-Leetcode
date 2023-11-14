// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    int countPalindromicSubsequence(string s) {
        int ans=0;
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        
        for(int i=0;i<s.length();i++)
        {
            if(mp1.count(s[i])==0)
            mp1[s[i]]=i;
            
            mp2[s[i]]=i;
        }
        
        for(auto it:mp1)
        {
            unordered_map<char,int> unique;
            int i=it.second+1;
            int j=mp2[it.first];
            
            while(i<j)
            {
                unique[s[i]]++;
                i++;
            }
            ans+=unique.size();
        }
        
        return ans;
    }
};