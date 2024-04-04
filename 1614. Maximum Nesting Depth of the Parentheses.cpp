// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    int maxDepth(string s) {
        stack<int> st;
        for(auto it:s)
        {
            if(it=='(')
            st.push(-1);
            else if(it==')')
            {
                int maxi=0;
                while(!st.empty() and st.top()!=-1)
                {
                    maxi=max(maxi,st.top());
                    st.pop();
                }
    
                if(!st.empty())
                {
                    st.pop();
                    st.push(maxi+1);
                }
                else
                st.push(maxi);
            }
                    
        }
        
        int ans=0;
        while(!st.empty())
        {
            ans=max(ans,st.top());
            st.pop();
        }
        return ans;
    }
};

