class Solution {
    public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]<0)
            {
                arr[i]*=-1;
                if(mp[arr[i]%k]>=1)
                mp[arr[i]%k]--;
                else if(mp[-1*(k-arr[i]%k)]>=1)
                mp[-1*(k-arr[i]%k)]--;
                else
                mp[-1*(arr[i]%k)]++;
            }
            else
            {
                if(mp[k-arr[i]%k]>=1)
                mp[k-arr[i]%k]--;
                else if(mp[-1*(arr[i]%k)]>=1)
                mp[-1*(arr[i]%k)]--;
                else
                mp[arr[i]%k]++;
            }
        }
        
        
        for(auto& it:mp)
        {
            if(it.second>=1)
            {
                if(it.first==0)
                {
                    if(it.second&1)
                    return 0;
                    
                    continue;
                }
               // cout<<it.first<<" "<<it.second<<endl;
                return 0;
            }
        }
        
        return 1;
    }
};
