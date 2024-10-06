class Solution {
    public:
    bool help(vector<string>& s1,vector<string>& s2,int i,int j,int ind)
    {
        // base case
        if(j>=s2.size())
        {
            if(i>=s1.size() or ind==-1 or ind==i-1)
            return 1;
            else
            return 0;
        }
        
        if(i>=s1.size())
        return 0;
        
        
        // recursive calls
        // and small calculation
        bool a(false),b(false);
        if(s1[i]==s2[j])
        a=help(s1,s2,i+1,j+1,ind);
        
        if(ind==-1 or ind==i-1)
        b=help(s1,s2,i+1,j,i);
        
        return a or b;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> s1;
        vector<string> s2;
        
        // for sentence 1
        string str="";
        for(auto& ch:sentence1)
        {
            if(ch==' ')
            {
                if(str.length())
                s1.push_back(str);
                
                str="";
            }
            else
            str+=ch;
        }
        if(str.length())
        s1.push_back(str);
        
        // for sentence 1
        str="";
        for(auto& ch:sentence2)
        {
            if(ch==' ')
            {
                if(str.length())
                s2.push_back(str);
                
                str="";
            }
            else
            str+=ch;
        }
        if(str.length())
        s2.push_back(str);
        
        if(s1.size()>s2.size())
        return help(s1,s2,0,0,-1);
        else
        return help(s2,s1,0,0,-1);
    }
};
