// Time complexity - O(N^2)
// Space complexity- O(N)
class Solution {
    public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(auto& it:s)
        {
            if(it=='(')
            st.push('(');
            else if(it==')')
            {
                string temp="";
                while(st.top()!='(')
                {
                    temp+=st.top();
                    st.pop();
                }
                st.pop();
                
                for(auto& it:temp)
                st.push(it);
            }
            else
            st.push(it);
        }
        
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
