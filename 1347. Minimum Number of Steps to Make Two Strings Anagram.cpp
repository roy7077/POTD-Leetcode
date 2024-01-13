// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    int minSteps(string s, string t) {
        unordered_map<char,int> mp;
        for(auto it:s)
        mp[it]++;
        
        int cnt=0;
        for(auto it:t)
        {
            if(mp[it]<=0)
            cnt++;
            else
            mp[it]--;
        }
        return cnt;
    }
};
