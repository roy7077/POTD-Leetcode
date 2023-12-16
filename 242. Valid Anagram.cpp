// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    bool isAnagram(string s, string t) {
        
        if(s.length()!=t.length())
        return 0;
        
        unordered_map<char,int> mp;
        for(auto it:s)
        mp[it]++;
        
        for(auto it:t)
        {
            if(mp[it]<=0)
            return 0;
            
            mp[it]--;
        }
        return 1;
    }
};