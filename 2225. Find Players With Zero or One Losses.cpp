// Time complexity - O(N)
// Space complexity- O(4*N)
class Solution {
    public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        unordered_map<int,int> lost,winner;
        for(auto it:matches)
        {
            winner[it[0]]++;
            lost[it[1]]++;
        }
        
        vector<int> l1,l2;
        
        //for those player who dont lost any match
        for(auto it:winner)
        {
            if(!lost.count(it.first))
            l1.push_back(it.first);
        }
        
        //for those player who  lost excatly one match
        for(auto it:lost)
        {
            if(it.second==1)
            l2.push_back(it.first);
        }
        
        sort(l1.begin(),l1.end());
        sort(l2.begin(),l2.end());
        return {l1,l2};
    }
};