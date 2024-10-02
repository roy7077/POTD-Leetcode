// Time complexity - O(NlogN)
// Space complexity- O(N)
typedef pair<int,int> pi;
class Solution {
    public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        if(arr.size()==0)
        return {};
        
        vector<pi> v;
        for(int i=0;i<arr.size();i++)
        v.push_back({arr[i],i});
        
        sort(v.begin(),v.end());
        
        vector<int> ans(arr.size());
        int rank=1;
        ans[v[0].second]=1;
        for(int i=1;i<arr.size();i++)
        {
            if(v[i].first!=v[i-1].first)
            rank++;
                
            ans[v[i].second]=rank;
        }
        
        return ans;
    }
};
