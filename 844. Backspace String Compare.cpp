STACK | T - O(N) | S - O(2*N)

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        stack<char> s1,s2;
        
        for(auto it:s)
        {
            if(it!='#')
            s1.push(it);
            else
            {
                if(!s1.empty())
                s1.pop();
            }
        }
        
        for(auto it:t)
        {
            if(it!='#')
            s2.push(it);
            else
            {
                if(!s2.empty())
                s2.pop();
            }
        }
        
        if(s1.size()!=s2.size())
        return 0;
        
        while(!s1.empty())
        {
            if(s1.top()!=s2.top())
            return 0;
            
            s1.pop();
            s2.pop();
        }
        
        return 1;
    }
};
TWO POINTER APPROACH | T - O(N) | S - O(1)

class Solution {
    public:
    void help(string& s)
    {
        int n1=s.length();
        int i=n1-1;
        while(i>=0)
        {
            if(s[i]=='#')
            {
                if(i==0)
                {
                    s[i]='0';
                    i--;
                    continue;
                    i--;
                }
                
                if(s[i-1]!='#')
                {
                    s[i]='0';
                    s[i-1]='0';
                    i--;
                }
                else
                {
                    int cnt=0;
                    while(i>=0 and s[i]=='#')
                    {
                        cnt++;
                        s[i]='0';
                        i--;
                    }
                    
                    while(i>=0 and cnt)
                    {
                        if(s[i]=='#')
                        {
                            cnt++;
                            s[i]='0';
                            i--;
                            continue;
                        }
                        s[i]='0';
                        cnt--;
                        i--;
                    }
                }
                    
            }
            else
            i--;
        }
        
    }
    bool backspaceCompare(string s, string t) {
        
        int n1=s.length();
        int n2=t.length();
        
        help(s);
        help(t);
        
        int i=n1-1;
        int j=n2-1;
        
        while(i>=0 and j>=0)
        {
            while(i>=0 and s[i]=='0')
            i--;
            
            while(j>=0 and t[j]=='0')
            j--;
            
            if(i==-1 and j!=-1)
            return 0;
            else if(j==-1 and i!=-1)
            return 0;
            else if(i==-1 and j==-1)
            return 1;
            
            if(s[i]!=t[j])
            return 0;
            
            i--;
            j--;
        }
        
        while(i>=0 and s[i]=='0')
        i--;

        while(j>=0 and t[j]=='0')
        j--;

        if(i==-1 and j!=-1)
        return 0;
        else if(j==-1 and i!=-1)
        return 0;
        else if(i==-1 and j==-1)
        return 1;
        
        return 1;
    }
};
