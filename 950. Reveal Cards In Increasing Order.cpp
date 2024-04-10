
// Method - 1 
// Recursion
// Time complexity - O(N^2)
// Space complexity- O(N^2)
class Solution {
    public:
    vector<int> help(vector<int>& deck,bool flag)
    {
        //base case
        if(deck.size()==1)
        return deck;
        
        //recursive calls
        //and small calculation
        vector<int> temp;
        vector<int> copy=deck;
        int j=0;
        if(flag)
        {
            int i=0;
            while(i<deck.size())
            {
                if(i%2==0)
                {
                    copy[i]=deck[j];
                    j++;
                }
                else
                copy[i]=-1;
                
                i++;
            }
        }
        else
        {
            int i=0;
            while(i<deck.size())
            {
                if(i%2==0)
                copy[i]=-1;
                else
                {
                    copy[i]=deck[j];
                    j++;
                }
                i++;
            }
        }
        
        //remaining ele
        while(j<deck.size())
        {
            temp.push_back(deck[j]);
            j++;
        }
        
        bool tempFlag=1;
        if(deck.size()&1)
        {
            if(flag)
            tempFlag=0;
            else
            tempFlag=1;
        }
        else
        {
            if(flag)
            tempFlag=1;
            else
            tempFlag=0;  
        }
        
        vector<int> ans=help(temp,tempFlag);
        int k=0;
        for(int i=0;i<deck.size();i++)
        {
            if(copy[i]==-1)
            {
                copy[i]=ans[k];
                k++;
            }
        }
        return copy;
    }
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        return help(deck,true);
    }
};


// Method - 2
// queue
// Time complexity - O(NlogN)
// Space complexity- O(N)
class Solution {
    public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        queue<int> q;
        for(int i=0;i<deck.size();i++) 
        q.push(i);
        
        vector<int> ans(deck.size());
        for(int i=0;i<deck.size();i++)
        {
            int front=q.front();
            q.pop();
            
            ans[front]=deck[i];
            
            if(!q.empty())
            {
                front=q.front();
                q.pop();
                q.push(front);
            }
        }
        return ans;
    }
};