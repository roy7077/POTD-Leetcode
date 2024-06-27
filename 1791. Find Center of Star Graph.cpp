
class Solution {
    public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int> mp;
        for(auto& it:edges)
        {
            mp[it[1]]++;
            mp[it[0]]++;
            
            if(mp[it[1]]==3)
            return it[1];
            
            if(mp[it[0]]==3)
            return it[0];
        }
        
        for(auto& it:mp)
        {
            if(it.second==2)
            return it.first;
        }
        
        return -1;
    }
};

// 1 - 2 - 3 - 4 - 5