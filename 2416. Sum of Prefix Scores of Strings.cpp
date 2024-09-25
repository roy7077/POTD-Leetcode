class Trie {
public:
    int end = 0;
    char ch;
    unordered_map<char, Trie*> arr;

    Trie(char ch) : ch(ch), end(0) {}
};

class Solution {
public:
    Trie* t = new Trie('1');

    void buildTrie(const string& s) 
    { 
        Trie* node = this->t;
        for (char c : s) 
        { 
            if (node->arr.find(c) == node->arr.end()) 
            {  
                Trie* newNode = new Trie(c);
                node->arr[c] = newNode; 
            }

            node = node->arr[c];  
            node->end++;  
        }
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        
        for (auto& it : words)
        buildTrie(it);

        vector<int> ans;
        for (auto& it : words) {
            int cnt = 0;
            Trie* node = this->t;

            for (char c : it) 
            { 
                if (node->arr.find(c) == node->arr.end())
                break;  

                node = node->arr[c]; 
                cnt += node->end;  
            }

            ans.push_back(cnt); 
        }

        return ans;
    }
};



/*
// It is taking to much memory
// Trie 
class Trie{
    public:
    int end=0;
    char ch;
    vector<Trie*> arr;
    
    Trie(char ch){
        this->ch=ch;
        arr.resize(26,NULL);
        this->end=0;
    }
};


class Solution {
    public:
    Trie* t=new Trie('1');
    
    void buildTrie(string& s)
    {
        Trie* node=this->t;
        for(int i=0;i<s.length();i++)
        {
            if(node->arr[s[i]-'a']==NULL)
            {
                Trie* newNode=new Trie(s[i]);
                node->arr[s[i]-'a']=newNode;
            }
            
            node=node->arr[s[i]-'a'];
            node->end=node->end + 1;
        }
    }
    
    vector<int> sumPrefixScores(vector<string>& words) {
        
        // inserting into trie
        for(auto& it:words)
        buildTrie(it);
        
        vector<int> ans;
        for(auto& it:words)
        {
            int cnt=0;
            Trie* node=this->t;
            
            for(int i=0;i<it.length();i++)
            {
                node=node->arr[it[i]-'a'];
                
                if(node==NULL)
                break;
                
                cnt+=node->end;
            }
            
            ans.push_back(cnt);
        }
        
        return ans;
    }
};
*/
