class Solution {
    public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> v(n,0);
        for(auto& it:edges)
        v[it[1]]++;
        
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            if(v[i]==0)
            {
                if(ans!=-1)
                return -1;
                
                ans=i;
            }
        }
        
        return ans;
    }
};
