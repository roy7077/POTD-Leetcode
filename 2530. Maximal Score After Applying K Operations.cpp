// Time complexity - O(KlogN)
// Space complexity- O(N)
#define ll long long
class Solution {
    public:
    long long maxKelements(vector<int>& nums, int k) {
        ll sum=0;
        priority_queue<ll> pq;
        
        for(auto& it:nums)
        pq.push(it);
        
        while(!pq.empty() and k--)
        {
            int num=pq.top();
            pq.pop();
            
            sum+=num;
            int temp=ceil(num/3.0);
            pq.push(temp); 
        }
        return sum;
    }
};
