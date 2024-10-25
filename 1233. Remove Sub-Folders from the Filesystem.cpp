// Method - 1
class Trie{
    public:
    bool flag=0;
    string node="";
    unordered_map<string,Trie*> mp;
    
    Trie(string ch)
    {
        this->node=ch;
        this->flag=0;
    }
};

class Solution {
    public:
    Trie* root=new Trie("0");
    void addToTrie(string& s)
    {
        //cout<<s<<endl;
        Trie* node=root;
        string str="";
        for(int i=1;i<s.length();i++)
        {
            if(s[i]!='/')
            {
                //cout<<str<<endl;
                str+=s[i];
                continue;
            }
            
            //cout<<str<<endl;
            if(node->mp.count(str)==0)
            {
               //cout<<str<<endl;

               Trie* newNode=new Trie(str);
               node->mp[str]=newNode;
            }
                        
            node=node->mp[str];
            if(node->flag)
            return ;
            
            str="";
            
        }
        
        if(str.length()==0)
        {
            node->flag=1;
            return ;
        }
        
        if(node->mp.count(str)==0)
        {
            Trie* newNode=new Trie(str);
            node->mp[str]=newNode;
        }

        node=node->mp[str];
        node->flag=1;
    }
    
    void evaluate(vector<string>& ans,Trie* node,string str)
    {
        // base case
        if(node->flag)
        {
            ans.push_back(str);
            return ;
        }
        
        // recursive calls
        for(auto& it:node->mp)
        evaluate(ans,it.second,str+"/"+it.first);
    }
    
    vector<string> removeSubfolders(vector<string>& folder) {
        
        for(auto& it:folder)
        {
            if(it[0]=='/')
            {
                //cout<<it<<endl;
                addToTrie(it);
            }
        }
        
        vector<string> ans;
        evaluate(ans,root,"");
        
        return ans;
    }
};


// Method - 2
// Time complexity - O(NlogN)
// Space complexity- O(N)
class Solution {
    public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string> ans;
        ans.push_back(folder[0]);
        
        for(int i=1;i<folder.size();i++)
        {
            
            string temp=folder[i].substr(0,ans.back().size());
            int ind=ans.back().length();
            while(ind<folder[i].length() and folder[i][ind]!='/')
            {
                temp+=folder[i][ind];
                ind++;
            }
            
            temp+='/';
            
            if((ans.back()+'/')!=temp)
            ans.push_back(folder[i]);
        }
        
        return ans;
    }
};
