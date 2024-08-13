class Solution {
    public:
    void help(unordered_map<int,int>& mp,vector<int>& v,set<vector<int>>& st,int& sum,int& target)
    {
        // base case
        if(sum==target)
        {
            vector<int> temp=v;
            sort(temp.begin(),temp.end());
            st.insert(temp);
            return ;
        }
        
        if(sum>target)
        return ;
        
        // recursive calls
        // and small calculation
        for(auto& it:mp)
        {
            if(it.second==0)
            continue;
            
            sum+=it.first;
            v.push_back(it.first);
            mp[it.first]--;

            help(mp,v,st,sum,target);

            mp[it.first]++;
            v.pop_back();
            sum-=it.first;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        set<vector<int>> st;
        unordered_map<int,int> mp;
        for(auto& it:candidates)
        mp[it]++;
        
        vector<int> v;
        int sum=0;
        help(mp,v,st,sum,target);
        
        vector<vector<int>> ans;
        for(auto& it:st)
        ans.push_back(it);
        
        return ans;
    }
};
