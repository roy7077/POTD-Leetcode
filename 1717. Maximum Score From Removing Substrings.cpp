/*----------------------Method - 1-------------------------*/
// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    int help(string& s, string str, int point)
    {
        int cnt = 0;
        stack<int> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '#')
                continue;

            // Ensure stack is not empty before accessing the top element
            if(!st.empty())
            {
                string combined_chars(1, s[st.top()]); // Convert character to string
                combined_chars += s[i];               // Concatenate the current character

                if (combined_chars == str)
                {
                    int ind = st.top();
                    s[ind] = '#';
                    s[i] = '#';
                    cnt += point;
                    st.pop();
                }
                else
                {
                    st.push(i);
                }
            }
            else
            {
                st.push(i);
            }
        }
        return cnt;
    }

    int maximumGain(string s, int x, int y) {
        
        string str1,str2;
        int mini,maxi;
        if(x>y)
        {
            str1="ab";
            str2="ba";
            maxi=x;
            mini=y;
        }
        else
        {
            str1="ba";
            str2="ab";
            maxi=y;
            mini=x;
        }
        
        int ans=help(s,str1,maxi);
        ans+=help(s,str2,mini);
        return ans;
    }
};


/*--------------------------------Method - 2----------------------*/
// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    int help(string& s, string str, int point)
    {
        int i=0;
        int j=0;
        int cnt=0;
        while(j<s.length())
        {
            if(s[j]=='#')
            break;
            
            s[i]=s[j];
            i++;
            
            if(i-2>=0)
            {
                string temp="";
                temp+=s[i-2];
                temp+=s[i-1];
                
                if(temp==str)
                {
                    cnt+=point;
                    i-=2;
                }
            }
            j++;
        }
        s[i]='#';
        return cnt;
    }

    int maximumGain(string s, int x, int y) {
        
        string str1,str2;
        int mini,maxi;
        if(x>y)
        {
            str1="ab";
            str2="ba";
            maxi=x;
            mini=y;
        }
        else
        {
            str1="ba";
            str2="ab";
            maxi=y;
            mini=x;
        }
        
        int ans=help(s,str1,maxi);
        ans+=help(s,str2,mini);
        return ans;
    }
};
