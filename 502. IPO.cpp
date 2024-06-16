typedef pair<int,int> pi;
class Solution {
    public:
//     static bool cmp(pi& a,pi& b)
//     {
//         if(a.second==b.second)
//         return a.first>b.first;
        
//         return a.second<b.second;
//     }
//     int help(vector<pi>& v,int i,int w,int k)
//     {
//         //base case
//         if(i>=v.size())
//         return 0;
        
//         if(k==0)
//         return 0;
        
//         //recursive calls
//         //and small calculation
//         int a=0;
//         int b=0;
//         a=help(v,i+1,w,k);
        
//         if(v[i].second<=w)
//         b=v[i].first+help(v,i+1,w+v[i].first,k-1);
        
//         return max(a,b);
        
//     }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pi> v;
        for(int i=0;i<n;i++)
        v.push_back({capital[i],profits[i]});
        
        sort(v.begin(),v.end());
        
        priority_queue<int> maxProfit;
        int i=0;
        while(k--)
        {
            while(i<n and v[i].first<=w)
            {
                maxProfit.push(v[i].second);
                i++;
            }
            
            if(maxProfit.empty())
            break;
            
            w+=maxProfit.top();
            maxProfit.pop();
        }
        return w;
    }
};