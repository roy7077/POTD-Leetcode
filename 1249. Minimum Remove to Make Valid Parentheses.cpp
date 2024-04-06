// Method - 1 (Jama Nihayati chutiya code)
// Time complexity - O(N)
// Space complexity- O(N+N)
typedef pair<char,int> pi;
class Solution {
    public:
    string minRemoveToMakeValid(string s) {
        unordered_set<int> st;
        stack<pi> stk;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            stk.push({'(',i});
            else if(s[i]==')')
            {
                if(!stk.empty() and stk.top().first=='(')
                stk.pop();
                else
                st.insert(i);
            }
        }
        
        while(!stk.empty())
        {
            st.insert(stk.top().second);
            stk.pop();
        }
        
        string ans="";
        for(int i=0;i<s.length();i++)
        {
            if(st.count(i)==0)
            ans+=s[i];
        }
        return ans;
    }
};


// Method - 2 
// Time complexity - O(N)
// Space complexity- O(N)
typedef pair<char,int> pi;
class Solution {
    public:
    string minRemoveToMakeValid(string s) {
        stack<pi> stk;   
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            stk.push({'(',i});
            else if(s[i]==')')
            {
                if(!stk.empty() and stk.top().first=='(')
                stk.pop();
                else
                s[i]='#';
            }
        }
        
        while(!stk.empty())
        {
            s[stk.top().second]='#';
            stk.pop();
        }
        
        string ans="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='#')
            ans+=s[i];
        }
        return ans;
    }
};