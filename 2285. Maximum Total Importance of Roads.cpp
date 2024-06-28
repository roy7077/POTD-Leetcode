// Time complexity - O(NlogN)
// Space complexity- O(N+N)
typedef pair<int,int> pi;
#define ll long long
class Solution {
    public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<pi> outdegree(n);
        for(auto& it:roads)
        {
            // for 1st element
            outdegree[it[0]].first++;
            outdegree[it[0]].second=it[0];
            
            //for second element
            outdegree[it[1]].first++;
            outdegree[it[1]].second=it[1];
        }
        
        //sorting
        sort(outdegree.begin(),outdegree.end(),greater<pi>());
        n;
        
        unordered_map<int,int> mp;
        for(auto& it:outdegree)
        {
            if(it.first==0)
            break;
            
            mp[it.second]=n;
            n--;
        }
        
        
        ll ans=0;
        for(auto& it:roads)
        {
            ans+=mp[it[0]];
            ans+=mp[it[1]];
        }
        
        return ans;
    }
};