// Time complexity - O(NlogN)
// Space complexity- O(N+N)
typedef pair<int,int> pi;
class Solution {
    public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto& it:nums)
        mp[it]++;
        
        vector<pi> v;
        for(auto& it:mp)
        v.push_back({it.first,it.second});
        
        sort(v.begin(),v.end(),[](pi& a,pi& b){
            if(a.second!=b.second)
            return a.second<b.second;
            
            return a.first>b.first;
        });
        
        vector<int> ans;
        for(auto& it:v)
        {
            while(it.second)
            {
                ans.push_back(it.first);
                it.second--;
            }
        }
        
        return ans;
    }
};
