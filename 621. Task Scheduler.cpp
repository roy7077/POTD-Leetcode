// Method - 1
// Time complexity - O(NlogN)
// Space complexity- O(N+N+N)
class Solution {
    public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        for(auto it:tasks)
        mp[it]++;
        
        priority_queue<int> pq;
        for(auto it:mp)
        pq.push(it.second);
        
        int t=0;
        while(!pq.empty())
        {
            int top=pq.top();
            top--;
            pq.pop();
            
            int cnt=0;
            vector<int> store;
            while(!pq.empty() and cnt<n)
            {
                int num=pq.top();
                pq.pop();
                num--;
                cnt++;
                
                if(num)
                store.push_back(num);
            }
            
            for(auto it:store)
            pq.push(it);
            
            if(top)
            pq.push(top);
            
            if(cnt==n)
            t+=(cnt+1);
            else if(cnt<n and top)
            t+=(n+1);
            else
            t+=cnt+1;
        }
        return t;
    }
};