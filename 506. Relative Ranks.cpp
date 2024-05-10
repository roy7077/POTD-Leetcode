class Solution {
    public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> temp=score;
        sort(temp.begin(),temp.end(),greater<int>());
        unordered_map<int,int> mp;
        for(int i=0;i<temp.size();i++)
        mp[temp[i]]=i+1;
        
        vector<string> ans;
        for(auto& it:score)
        {
            if(mp[it]==1)
            ans.push_back("Gold Medal");
            else if(mp[it]==2)
            ans.push_back("Silver Medal");
            else if(mp[it]==3)
            ans.push_back("Bronze Medal");
            else
            {
                string ch=to_string(mp[it]);
                ans.push_back(ch);
            }
        }
        return ans;
    }
};