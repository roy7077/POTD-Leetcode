// Monotonic stack
// Time complexity - O(N)
// Space complexity- O(2*N)
#define ll long long
class Solution {
    public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> left_small(n,0);
        vector<int> right_small(n,0);
        
        //left small
        stack<int> st1;
        for(int i=0;i<n;i++)
        {
            while(!st1.empty() and arr[st1.top()]>=arr[i])
            st1.pop();
            
            if(st1.empty())
            left_small[i]=0;
            else
            left_small[i]=st1.top()+1;
            
            st1.push(i);
        }
        
        //right small
        stack<int> st2;
        for(int i=n-1;i>=0;i--)
        {
            while(!st2.empty() and arr[st2.top()]>arr[i])
            st2.pop();
            
            if(st2.empty())
            right_small[i]=n-1;
            else
            right_small[i]=st2.top()-1;
            
            st2.push(i);
        }
        
        
        ll ans=0;
        int mod=1e9+7;
        
        for(int i=0;i<n;i++)
        {
            int left=i-left_small[i]+1;
            int right=right_small[i]-i+1;
            ll temp_ans=(static_cast<ll> (left) * right * arr[i] )%mod;
            ans=(ans+temp_ans)%mod;
            
        }
        
        return ans;
    }
};

/*
  (left+1) * (right+1) * arr[i]
  
  consider current element as minimum and
  find the number of subarray that can be 
  form using current element , 
*/