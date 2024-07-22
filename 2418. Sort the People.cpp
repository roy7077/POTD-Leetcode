// Time complexity - O(NlogN)
// Space complexity- O(N+N)
typedef pair<int,string> pi;
class Solution {
    public:
    static bool cmp(pi& a,pi& b)
    {
        return a.first>b.first;
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n=names.size();
        vector<pi> v;
        for(int i=0;i<n;i++)
        v.push_back({heights[i],names[i]});
        
        sort(v.begin(),v.end(),cmp);
        
        vector<string> ans;
        for(auto& it:v)
        ans.push_back(it.second);
        
        return ans;
    }
};
