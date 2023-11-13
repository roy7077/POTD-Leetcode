// Time complexity - O(NlogN)
// Space complexity- O(N)
class Solution {
    private:
    bool done=0;
    unordered_map<char,int> mp;
    public:
    void fun()
    {
        mp['A']=1;
        mp['a']=1;
        mp['e']=1;
        mp['E']=1;
        mp['i']=1;
        mp['I']=1;
        mp['o']=1;
        mp['O']=1;
        mp['u']=1;
        mp['U']=1;
        done=1;
    }
    
    string sortVowels(string s) {
        
        if(!done)
        fun();
        
        priority_queue <int, vector<int>, greater<int>> pq;
        for(auto& it:s)
        {
            if(mp[it])
            {
                pq.push(int(it));
                it='1';
            }
        }
        
        for(auto& it:s)
        {
            if(it=='1')
            {
                it=char(pq.top());
                pq.pop();
            }
        }
        return s;
    }
};
