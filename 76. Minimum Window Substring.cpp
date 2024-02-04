/* Very Very Important */
class Solution {
    public:
    string minWindow(string str, string t) {
        unordered_map<char,int> mp1;
        for(auto it:t)
        mp1[it]++;
        
        
        unordered_map<char,int> mp2;
        int formed=0;
        int required=mp1.size();
        int s=0;
        int e=0;
        
        int len=1e9;
        int i=0;
        int j=0;
        
        while(j<str.length())
        {
            char ch=str[j];
            mp2[ch]++;
            
            if(mp1.count(ch) and mp2[ch]==mp1[ch])
            formed++;
            
            while(i<=j and formed>=required)
            {
                cout<<len<<endl;
                if((j-i+1)<len)
                {
                    len=j-i+1;
                    s=i;
                    e=j;
                }
                
                ch=str[i];
                mp2[ch]--;
                
                if(mp1.count(ch) and mp2[ch]<mp1[ch])
                formed--;
                
                i++;
            }
            j++;
        }
        
        if(len>=1e9)
        return "";
        
        return str.substr(s,len);
    }
};