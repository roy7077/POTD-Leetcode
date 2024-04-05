// Stack
// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    string makeGood(string s) {
        stack<char> st;
        for(auto it:s)
        {
            int asic=int(it);
            if(!st.empty() and (int(st.top())==asic+32 or int(st.top())==asic-32))
            st.pop();
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


// Iterative
// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    string makeGood(string s) {
        int i=0;
        int j=1;
        while(j<s.length())
        {
            if(int(s[i])==int(s[j])+32 or int(s[i])==int(s[j])-32)
            {
                s[i]='#';
                s[j]='#';
                i--;
                while(i>=0 and s[i]=='#')
                i--;
                
                if(i<0)
                {
                    i=j+1;
                    j+=2;
                }
                else
                j++;
            }
            else
            {
                i=j;
                j++;
            }
        }
        
        string ans="";
        for(auto it:s)
        {
            if(it!='#')
            ans+=it;
        }
        return ans;
    }
};