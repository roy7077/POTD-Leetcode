// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int> mp;
        for(auto it:words)
        {
            for(auto x:it)
            mp[x]++;
        }
        
        int n=words.size();
        for(auto it:mp)
        {
            if(it.second%n)
            return 0;
        }
        
        return 1;
    }
};