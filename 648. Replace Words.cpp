class Solution {
    public:
    string help(string str,unordered_map<string,int>& mp)
    {
        string s="";
        string temp=str;
        while(temp.length())
        {
            if(mp.count(temp))
            s=temp;
            
            temp.pop_back();
        }
        if(s.length()==0)
        s=str;
        
        return s;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        
        //storing in unordered map
        unordered_map<string,int> mp;
        for(auto& it:dictionary)
        mp[it]++;
        
        //making sentence
        string ans="";
        bool flag=0;
        string str="";
        for(auto& it:sentence)
        {
            if(it==' ')
            {
                // cout<<str<<endl;
                string s=help(str,mp);
                // cout<<"s -> "<<s<<endl;
                if(!flag)
                {
                    ans=s;
                    flag=1;
                }
                else
                {
                    ans+=" ";
                    ans+=s;
                }
                
                str="";
            }
            else
            str+=it;
            
        }
        
        //if string is completed and we have some string left
        // in our str string
        if(str.length())
        {
            string s=help(str,mp);
            if(!flag)
            {
                ans=s;
                flag=1;
            }
            else
            {
                ans+=" ";
                ans+=s;
            }
        }
        
        return ans;
    }
};