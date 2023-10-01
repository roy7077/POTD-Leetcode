
// 🔥 BEST SOLUTION 🔥


// **T - O(2*N) | S - O(N)
// Time complexity - O(2*N)
// Space complexity- O(N)
class Solution {
    public:
    void help(string& st)
    {
        int i=0;
        int j=st.length()-1;
        while(i<j)
        {
            char ch=st[j];
            st[j]=st[i];
            st[i]=ch;
            i++;
            j--;
        }
    }
    
    string reverseWords(string s) {
        
        string ans="";
        string temp="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                help(temp);
                ans+=temp;
                temp="";
                ans+=" ";
            }
            else
            temp+=s[i];
        }
        
        if(temp.length())
        {
            help(temp);
            ans+=temp;
        }
        
        return ans;
    }
};

// **T - O(N) | S - O(1) **
// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    string reverseWords(string s) {
        
        int i=0;
        int j=0;
        while(j<s.length())
        {
            if(s[j]==' ')
            {
                reverse(s.begin()+i,s.begin()+j);
                i=j+1;
            }
            j++;
        }
        
        if(j-i>1)
        reverse(s.begin()+i,s.begin()+j);
        
        return s;
    }
};
