
// MLE
class Solution {
public:
    string decodeAtIndex(string s, int k) {
        
        string ans="";
        for(auto it:s)
        {
            if(it>='a' and it<='z')
            ans+=it;
            else
            {
                int n=it-'0';
                string temp=ans;
                ans="";
                while(n)
                {
                    ans+=temp;
                    n--;
                }
                
                if(ans.length()>=k)
                {
                    string result="";
                    result+=ans[k-1];
                    return result;
                }
            }
        }

        if(k>ans.length())
        return "-1";

        string result="";
        result+=ans[k-1];
        return result;
    }
};


// OPTIMIZED SOLUTION 
class Solution {
    public:
    string decodeAtIndex(string s, int k) {
        
        long long N=0;
        for(auto it:s)
        {
            if(it>='a' and it<='z')
                N++;
            else
                N*=(it-'0');
        }
        
        string ans="";
        for(int i=s.length()-1;i>=0;i--)
        {
            k=k%N;
            if(k==0 and (s[i]>='a' and s[i]<='z'))
            {
                ans+=s[i];
                return ans;
            }
            
            if(s[i]>='a' and s[i]<='z')
                N--;
            else
                N/=(s[i]-'0');
            
        }
        
        return "swati";
    }
};