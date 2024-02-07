// Time complexity - O(NlogN)
// Space complexity- O(N+2*N)
class Solution {
    public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto it:s)
        mp[it]++;
        
        vector<pair<int,char>> ans;
        for(auto it:mp)
        ans.push_back({it.second,it.first});
        
        sort(ans.begin(),ans.end(),greater<pair<int,char>>());
        string str="";
        for(auto it:ans)
        {
            for(int i=0;i<it.first;i++)
            str+=it.second;
        }
        return str;
    }
};