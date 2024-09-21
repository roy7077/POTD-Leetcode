class Solution {
    public:
    void help(string& str,int n,vector<int>& ans)
    {
        if(str.length())
        {
            int num=stoi(str);
            if(num>n)
            return ;
            else
            ans.push_back(num);
        }
            
        
        for(int i='0';i<='9';i++)
        {
            if(str.length()==0 and i=='0')
            continue;
            
            str+=i;
            help(str,n,ans);
            str.pop_back();
        }
    }
    vector<int> lexicalOrder(int n) {
        string str="";
        vector<int> ans;
        
        help(str,n,ans);
        return ans;
    }
};
