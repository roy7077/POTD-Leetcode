/*---------------Method-1-----------*/
// sorting
// Time complexity - O(NlogN)
// Space complexity- O(1)
class Solution {
    public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=g.size()-1;
        int j=s.size()-1;
        int cnt=0;
        
        while(i>=0 and j>=0)
        {
            if(s[j]>=g[i])
            {
                cnt++;
                j--;
            }
            i--;
        }
        return cnt;
    }
};


/*---------------Method-2-----------*/
// priority queue
// Time complexity - O(NlogN)
// Space complexity- O(N+N)
class Solution {
    public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        priority_queue<int> pq1;
        priority_queue<int> pq2;
        
        for(auto it:g)
        pq1.push(it);
        
        for(auto it:s)
        pq2.push(it);
        
        int cnt=0;
        while(!pq1.empty() and !pq2.empty())
        {
            int top1=pq1.top();
            int top2=pq2.top();
            
            if(top2>=top1)
            {
                pq1.pop();
                pq2.pop();
                cnt++;
            }
            else
            pq1.pop();
        }
        return cnt;
    }
};
