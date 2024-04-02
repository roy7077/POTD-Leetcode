// Unordered map
// Time complexity - O(N)
// Space complexity- O(26+26) - constant
class Solution {
    public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        unordered_map<char,char> mapped;
        
        for(int i=0;i<s.length();i++)
        {
            if(mp.count(s[i]))
            {
                s[i]=mp[s[i]];
                if(s[i]!=t[i])
                return 0;
            }
            else if(mapped.count(t[i]))
            {
                if(mapped[t[i]]!=s[i])
                return 0;
            }
            else
            {
                mp[s[i]]=t[i];
                mapped[t[i]]=s[i];
                s[i]=t[i];
            }
        }
        return 1;
    }
};
