// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    bool find132pattern(vector<int>& nums) {
        
        int mid=-1e9;
        stack<int> st;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]<mid)
            return true;
            
            while(!st.empty() and st.top()<nums[i])
            {
                mid=st.top();
                st.pop();
            }
            
            st.push(nums[i]);
        }
        
        return false;
    }
};