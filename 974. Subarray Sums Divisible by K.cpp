class Solution {
    public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int sum=0;
        int cnt=0;
        for(auto& it:nums)
        {
            sum+=it;
            int rem=sum%k;
            if(rem<0)
            rem+=k;
            
            cnt+=mp[rem];
            mp[rem]++;
            
           // cout<<"it -> "<<it<<" cnt-> "<<cnt<<endl;
        }
        return cnt;
    }
};